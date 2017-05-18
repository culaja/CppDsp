#include "PacketQueue.h"

#include "MutexGuard.h"
#include <vector>

PacketQueue::PacketQueue(IAmMutex& mutex): _mutex(mutex) {

}

void PacketQueue::Push(const Packet& packet) {
	MutexGuard guard = MutexGuard(_mutex);
	_queue.push_back(packet);
}

Packet PacketQueue::WaitForPacketOfSize(int packetSize) {
	std::vector<float> resultBuffer;

	do {

	} while (resultBuffer.size() != packetSize);
	
	return Packet(resultBuffer);
}

