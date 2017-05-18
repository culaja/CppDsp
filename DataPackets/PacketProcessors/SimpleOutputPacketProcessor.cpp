#include "SimpleOutputPacketProcessor.h"

#include <iostream>

void SimpleOutputPacketProcessor::Process(const Packet& packet) {
	std::cout << "\t\t\t\t" << "Here is a new packet of size: " << packet.GetSize() << "." << std::endl;
	for (int k = 0; k < packet.GetSize(); k += 2) {
		float r = packet[k];
		float i = packet[k + 1];
		std::cout << "\t\t\t\t\t" << r << " + " << i << "i" << std::endl;
	}
}