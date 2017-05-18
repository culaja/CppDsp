#ifndef PACKET
#define PACKET

#include <vector>

class Packet {
private:
	std::vector<float> _buffer;

public:
	Packet(const std::vector<float>& buffer);
};

#endif