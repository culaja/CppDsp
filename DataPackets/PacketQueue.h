#ifndef PACKET_QUEUE
#define PACKET_QUEUE

#include <vector>
#include "Packet.h"
#include "IAmMutex.h"

class PacketQueue {
private:
	std::vector<Packet> _queue;
	IAmMutex _mutex;
public:
	
};

#endif