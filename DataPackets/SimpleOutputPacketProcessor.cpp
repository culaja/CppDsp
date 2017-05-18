#include "SimpleOutputPacketProcessor.h"

#include <iostream>

void SimpleOutputPacketProcessor::Process(const Packet& packet) {
	std::cout << "Here is a new packet!" << std::endl;
}