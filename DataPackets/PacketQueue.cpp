#include "PacketQueue.h"

#include "Utilities/MutexGuard.h"

PacketQueue::PacketQueue(IAmMutex& mutex, IAmAutoResetEvent& autoResetEvent): _mutex(mutex), _autoResetEvent(autoResetEvent) {
}

void PacketQueue::Push(const Packet& packet) {
	MutexGuard guard = MutexGuard(_mutex);

	std::vector<float> packetBuffer = packet.GetBuffer();
	for (std::vector<float>::iterator it  = packetBuffer.begin(); it < packetBuffer.end(); ++it) {
		_queue.push(*it);
	}

	_autoResetEvent.Set();
}

Packet PacketQueue::WaitForPacketOfSize(int packetSize) {
	std::vector<float> resultBuffer;

	while (resultBuffer.size() < packetSize) {
		bool waitForTheQueue = false;
		{
			MutexGuard guard = MutexGuard(_mutex);
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