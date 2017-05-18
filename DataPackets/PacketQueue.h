#ifndef PACKET_QUEUE
#define PACKET_QUEUE

#include <queue>
#include "Packet.h"
#include "IAmMutex.h"

class PacketQueue {
private:
	std::queue<float> _queue;
	IAmMutex& _mutex;
public:
	PacketQueue(IAmMutex& mutex);

	void Push(const Packet& packet);
	Packet WaitForPacketOfSize(int packetSize);

private:
};

#endif