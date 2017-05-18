#ifndef I_AM_PACKET_GENERATOR
#define I_AM_PACKET_GENERATOR

#include "Packet.h"

class IAmPacketGenerator {
public:
	virtual Packet GenerateRandomLength() = 0;
};

#endif