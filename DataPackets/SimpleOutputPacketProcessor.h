#ifndef SIMPLE_OUTPUT_PACKET_GENERATOR
#define SIMPLE_OUTPUT_PACKET_GENERATOR

#include "IAmPacketProcessor.h"

class SimpleOutputPacketProcessor : IAmPacketProcessor {
public:
	void Process(const Packet& packet);
};

#endif