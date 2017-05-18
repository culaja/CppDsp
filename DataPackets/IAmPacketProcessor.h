#ifndef I_AM_PACKET_PROCESSOR
#define I_AM_PACKET_PROCESSOR

#include "Packet.h"

class IAmPacketProcessor {
public:
	virtual void Process(const Packet& packet) = 0;
};

#endif