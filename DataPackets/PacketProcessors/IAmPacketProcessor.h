#ifndef I_AM_PACKET_PROCESSOR
#define I_AM_PACKET_PROCESSOR

#include "../Packet.h"

/*
Each PacketProcessor implementation have to implement this interface.
*/
class IAmPacketProcessor {
public:
	virtual void Process(const Packet& packet) = 0;
};

#endif