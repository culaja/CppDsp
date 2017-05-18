#ifndef COMPLEX_NUMBER_SEQUENCE_GENERATOR
#define COMPLEX_NUMBER_SEQUENCE_GENERATOR

#include "IAmPacketGenerator.h"

class ComplexNumberSequenceGenerator : IAmPacketGenerator {
public:
	std::vector<float> GenerateRandomLength();
};

#endif