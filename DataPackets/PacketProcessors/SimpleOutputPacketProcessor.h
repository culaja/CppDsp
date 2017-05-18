#ifndef SIMPLE_OUTPUT_PACKET_GENERATOR
#define SIMPLE_OUTPUT_PACKET_GENERATOR

#include "IAmPacketProcessor.h"

class SimpleOutputPacketProcessor : public IAmPacketProcessor {
public:
	SimpleOutputPacketProcessor() {}

	void Process(const Packet& packet);

private:
	SimpleOutputPacketProcessor(const SimpleOutputPacketProcessor&);
};

#endif