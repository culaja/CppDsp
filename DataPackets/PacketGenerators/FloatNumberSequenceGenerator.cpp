#include "FloatNumberSequenceGenerator.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

FloatNumberSequenceGenerator::FloatNumberSequenceGenerator(size_t maximalPacketSize)
	: _maximalPacketSize(maximalPacketSize), _maximalNumberSize(10) {
	srand((unsigned int)time(NULL));
}

Packet FloatNumberSequenceGenerator::GenerateRandomLength() {
	int packetSize = GenerateRandomIntegerWithLimit(_maximalPacketSize);

	std::vector<float> packetBuffer;
	for (int i = 0; i < packetSize; ++i) {
		float newFloat = GenerateRandomFloatWithLimit(_maximalNumberSize);
		packetBuffer.push_back(newFloat);
	}

	std::cout << "Generated " << packetSize << " float numbers!" << std::endl;
	return Packet(packetBuffer);
}

int FloatNumberSequenceGenerator::GenerateRandomIntegerWithLimit(int limit) {
	return rand() % limit;
}

float FloatNumberSequenceGenerator::GenerateRandomFloatWithLimit(int limit) {
	return (float)(rand() % limit);
}