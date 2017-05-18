#include "Packet.h"

#include "PacketSizeNotAlignedWithFloatException.h"

Packet::Packet(const std::vector<float>& buffer) {
	if (buffer.size() % sizeof(float)) {
		throw PacketSizeNotAlignedWithFloatException();
	}

	_buffer = buffer;
}

size_t Packet::GetSize() const {
	return _buffer.size();
}