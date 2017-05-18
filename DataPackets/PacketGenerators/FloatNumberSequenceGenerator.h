#ifndef FLOAT_NUMBER_SEQUENCE_GENERATOR
#define FLOAT_NUMBER_SEQUENCE_GENERATOR

#include "IAmPacketGenerator.h"

class FloatNumberSequenceGenerator : public IAmPacketGenerator {
private:
	int _maximalPacketSize;
	int _maximalNumberSize;

public:
	FloatNumberSequenceGenerator(size_t maximalPacketSize);

	Packet GenerateRandomLength();

private:
	FloatNumberSequenceGenerator(const FloatNumberSequenceGenerator&);

	int GenerateRandomIntegerWithLimit(int limit);
	float GenerateRandomFloatWithLimit(int limit);
};

#endif