#include "PacketQueueTests.h"
#include "../PacketQueue.h"
#include "../Utilities/IAmMutex.h"
#include "../Utilities/IAmAutoResetEvent.h"

class NoOpMutex : public IAmMutex {
public:
	void Lock() {}
	void Unlock() {}
};

class NoOpAutoResetEvent : public IAmAutoResetEvent {
	void Set() {}
	void Wait() {}
};

PacketQueueTests::PacketQueueTests() {
	TEST_ADD(PacketQueueTests::WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketOfLengthFourRetrieved);
	TEST_ADD(PacketQueueTests::WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketWithSameFloatsRetrieved);
}

void PacketQueueTests::WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketOfLengthFourRetrieved() {
	// Arrange
	PacketQueue& packetQueue = PacketQueue(NoOpMutex(), NoOpAutoResetEvent());

	std::vector<float> inputBuffer;
	inputBuffer.push_back(1.0);
	inputBuffer.push_back(2.0);
	inputBuffer.push_back(3.0);
	inputBuffer.push_back(4.0);
	packetQueue.Push(Packet(inputBuffer));

	// Act
	Packet retrievedPacket = packetQueue.WaitForPacketOfSize(4);

	// Assert
	TEST_ASSERT_EQUALS(4, retrievedPacket.GetSize());
}

void PacketQueueTests::WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketWithSameFloatsRetrieved() {
	// Arrange
	PacketQueue& packetQueue = PacketQueue(NoOpMutex(), NoOpAutoResetEvent());

	std::vector<float> inputBuffer;
	inputBuffer.push_back(1.0);
	inputBuffer.push_back(2.0);
	inputBuffer.push_back(3.0);
	inputBuffer.push_back(4.0);
	packetQueue.Push(Packet(inputBuffer));

	// Act
	Packet retrievedPacket = packetQueue.WaitForPacketOfSize(4);

	// Assert
	TEST_ASSERT_EQUALS(1.0, retrievedPacket[0]);
	TEST_ASSERT_EQUALS(2.0, retrievedPacket[1]);
	TEST_ASSERT_EQUALS(3.0, retrievedPacket[2]);
	TEST_ASSERT_EQUALS(4.0, retrievedPacket[3]);
}