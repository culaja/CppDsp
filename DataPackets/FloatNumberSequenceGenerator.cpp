#include "FloatNumberSequenceGenerator.h"

#include <stdlib.h>
#include <time.h>

FloatNumberSequenceGenerator::FloatNumberSequenceGenerator() {
	srand(time(NULL));
	_maximalPacketSize = 100;
	_maximalNumberSize = 10;
}

std::vector<float> FloatNumberSequenceGenerator::GenerateRandomLength() {
	int packetSize = GenerateRandomIntegerWithLimit(_maximalPacketSize);

	std::vector<float> newPacket;
	for (int i = 0; i < packetSize; ++i) {
		float newFloat = GenerateRandomFloatWithLimit(_maximalNumberSize);
		newPacket.push_back(newFloat);
	}

	return newPacket;
}

int FloatNumberSequenceGenerator::GenerateRandomIntegerWithLimit(int limit) {
	return rand() % limit;
}

float FloatNumberSequenceGenerator::GenerateRandomFloatWithLimit(int limit) {
	return (float)(rand() % limit);
}