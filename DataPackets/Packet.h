#ifndef PACKET
#define PACKET

#include <vector>

/*
	Each Packet contains zero or more float numbers.
	In current implementation Packet is immutable class meaning that
	once object is created it can't be modified.
*/
class Packet {
private:
	std::vector<float> _buffer;

public:
	Packet(const std::vector<float>& buffer);

	/*
		Size of the packet.
		Note that size represents number of float numbers in the packet, not absolute size in bytes!
	*/
	size_t GetSize() const;

	float operator[](int index) const;
};

#endif