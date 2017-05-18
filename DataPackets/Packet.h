#ifndef PACKET
#define PACKET

#include <vector>

class Packet {
private:
	std::vector<float> _buffer;

public:
	Packet(const std::vector<float>& buffer);

	size_t GetSize() const;

	const std::vector<float> GetBuffer() const;
};

#endif