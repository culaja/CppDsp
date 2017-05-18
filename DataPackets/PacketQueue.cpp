#include "PacketQueue.h"

#include "Utilities/MutexGuard.h"

PacketQueue::PacketQueue(IAmMutex& mutex, IAmAutoResetEvent& autoResetEvent): _mutex(mutex), _autoResetEvent(autoResetEvent) {
}

void PacketQueue::Push(const Packet& packet) {
	MutexGuard guard(_mutex);

	for (size_t i = 0; i < packet.GetSize(); ++i) {
		_queue.push(packet[i]);
	}

	_autoResetEvent.Set();
}

Packet PacketQueue::WaitForPacketOfSize(int packetSize) {
	std::vector<float> resultBuffer;
	int remainingItems = packetSize;

	while (remainingItems > 0) {
		WaitForItemsInQueue();
		FillResultBufferFromQueue(resultBuffer, remainingItems);
	}

	return Packet(resultBuffer);
}

void PacketQueue::WaitForItemsInQueue() {
	bool isQueueEmpty = false;
	{
		MutexGuard guard(_mutex);
		isQueueEmpty = _queue.size() == 0;
	}
	
	if (isQueueEmpty) {
		_autoResetEvent.Wait();
	}
}

void PacketQueue::FillResultBufferFromQueue(std::vector<float>& resultBuffer, int& remainingItems) {
	MutexGuard guard(_mutex);

	while (_queue.size() > 0 && remainingItems > 0) {
		resultBuffer.push_back(_queue.front());
		_queue.pop();
		remainingItems--;
	}
}