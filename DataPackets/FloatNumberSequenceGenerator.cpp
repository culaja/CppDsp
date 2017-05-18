#include "FloatNumberSequenceGenerator.h"

#include <stdlib.h>
#include <time.h>

FloatNumberSequenceGenerator::FloatNumberSequenceGenerator() {
	srand(time(NULL));
	_maximalPacketSize = 100;
	_maximalNumberSize = 10;
}

Packet FloatNumberSequenceGenerator::GenerateRandomLength() {
	int packetSize = GenerateRandomIntegerWithLimit(_maximalPacketSize);

	std::vector<float> packetBuffer;
	for (int i = 0; i < packetSize; ++i) {
		float newFloat = GenerateRandomFloatWithLimit(_maximalNumberSize);
		packetBuffer.push_back(newFloat);
	}

	return Packet(packetBuffer);
}

int FloatNumberSequenceGenerator::GenerateRandomIntegerWithLimit(int limit) {
	return rand() % limit;
}

float FloatNumberSequenceGenerator::GenerateRandomFloatWithLimit(int limit) {
	return (float)(rand() % limit);
}