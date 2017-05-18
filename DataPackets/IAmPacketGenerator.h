#ifndef I_AM_PACKET_GENERATOR
#define I_AM_PACKET_GENERATOR

#include <vector>

class IAmPacketGenerator {
public:
	virtual std::vector<float> GenerateRandomLength() = 0;
};

#endif