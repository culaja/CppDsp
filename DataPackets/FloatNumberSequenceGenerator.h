#ifndef FLOAT_NUMBER_SEQUENCE_GENERATOR
#define FLOAT_NUMBER_SEQUENCE_GENERATOR

#include "IAmPacketGenerator.h"

class FloatNumberSequenceGenerator : public IAmPacketGenerator {
public:
	FloatNumberSequenceGenerator(size_t maximalPacketSize);
	Packet GenerateRandomLength();

private:
	int _maximalPacketSize;
	int _maximalNumberSize;

	int GenerateRandomIntegerWithLimit(int limit);
	float GenerateRandomFloatWithLimit(int limit);
};

#endif