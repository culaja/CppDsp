#ifndef PACKET_QUEUE
#define PACKET_QUEUE

#include <queue>
#include "Packet.h"
#include "IAmMutex.h"
#include "IAmAutoResetEvent.h"

class PacketQueue {
private:
	std::queue<float> _queue;
	IAmMutex& _mutex;
	IAmAutoResetEvent& _autoResetEvent;
public:
	PacketQueue(IAmMutex& mutex, IAmAutoResetEvent& event);

	void Push(const Packet& packet);
	Packet WaitForPacketOfSize(int packetSize);

private:
	PacketQueue(const PacketQueue& that);
};

#endif