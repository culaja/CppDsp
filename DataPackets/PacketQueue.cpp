#include "PacketQueue.h"

#include "Utilities/MutexGuard.h"

PacketQueue::PacketQueue(IAmMutex& mutex, IAmAutoResetEvent& autoResetEvent): _mutex(mutex), _autoResetEvent(autoResetEvent) {
}

void PacketQueue::Push(const Packet& packet) {
	MutexGuard guard(_mutex);

	for (int i = 0; i < packet.GetSize(); ++i) {
		_queue.push(packet[i]);
	}

	_autoResetEvent.Set();
}

Packet PacketQueue::WaitForPacketOfSize(int packetSize) {
	std::vector<float> resultBuffer;

	while (resultBuffer.size() < packetSize) {
		bool waitForTheQueue = false;
		{
			MutexGuard guard(_mutex);
			if (_queue.size() > 0)
			{
				resultBuffer.push_back(_queue.front());
				_queue.pop();
			}
			else {
				waitForTheQueue = true;
			}
		}

		if (waitForTheQueue) {
			_autoResetEvent.Wait();
		}
	}

	return Packet(resultBuffer);
}