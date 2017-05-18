#ifndef PACKET_QUEUE_TESTS
#define PACKET_QUEUE_TESTS

#include <cpptest.h>
#include <string>

class PacketQueueTests : public Test::Suite
{
public:
	PacketQueueTests();

private:
	void WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketOfLengthFourRetrieved();
	void WaitForItemsInQueue_ThereIsFourFloatNumbersInQueue_PacketWithSameFloatsRetrieved();
};

#endif