#include "Packet.h"

#include "PacketSizeNotAlignedWithFloatException.h"

Packet::Packet(const std::vector<float>& buffer) {
	if (buffer.size() % sizeof(float)) {
		throw PacketSizeNotAlignedWithFloatException();
	}

	_buffer = buffer;
}