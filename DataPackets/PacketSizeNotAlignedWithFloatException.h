#ifndef PACKET_SIZE_NOT_ALIGNED_WITH_FLOAT_EXCEPTION
#define PACKET_SIZE_NOT_ALIGNED_WITH_FLOAT_EXCEPTION

#include <exception>
#include <sstream>

class PacketSizeNotAlignedWithFloatException : public std::exception
{
	virtual const char* what() const throw() {
		return "Packet size have to be aligned with float size";
	}
};

#endif
