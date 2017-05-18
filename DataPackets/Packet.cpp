#include "Packet.h"

Packet::Packet(const std::vector<float>& buffer) {
	_buffer = buffer;
}

size_t Packet::GetSize() const {
	return _buffer.size();
}

float Packet::operator[](int index) const {
	return _buffer[index];
}