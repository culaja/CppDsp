#ifndef SIMPLE_OUTPUT_PACKET_GENERATOR
#define SIMPLE_OUTPUT_PACKET_GENERATOR

#include "IAmPacketProcessor.h"

class SimpleOutputPacketProcessor : public IAmPacketProcessor {
public:
	void Process(const Packet& packet);
};

#endif