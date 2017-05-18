#include "ConsumerProducerTest.h"

#include "PacketQueue.h"
#include "StandardMutex.h"
#include "StandardAutoResetEvent.h"
#include "FloatNumberSequenceGenerator.h"
#include "SimpleOutputPacketProcessor.h"
#include <thread>
#include <windows.h>

const size_t MAXIMAL_INPUT_PACKET_SIZE = 10; // Maximum 100 floats can be created in input packet
const size_t FIXED_PACKET_SIZE = 20; // Each output packet will contain 10 floats

void producerWorker(PacketQueue* packetQueuePointer) {
	PacketQueue& packetQueue = *packetQueuePointer;

	IAmPacketGenerator& packetGenerator = FloatNumberSequenceGenerator(MAXIMAL_INPUT_PACKET_SIZE);
	for (;;) {
		Packet& packet = packetGenerator.GenerateRandomLength();
		packetQueue.Push(packet);

		Sleep(1000);
	}
}

void consumerWorker(PacketQueue* packetQueuePointer) {
	PacketQueue& packetQueue = *packetQueuePointer;

	IAmPacketProcessor& packetProcessor = SimpleOutputPacketProcessor();
	for (;;) {
		Packet& packet = packetQueue.WaitForPacketOfSize(FIXED_PACKET_SIZE);
		packetProcessor.Process(packet);
	}
}

int ConsumerProducerTest::Run(int argc, char* argv[]) {
	PacketQueue& packetQueue = PacketQueue(StandardMutex(), StandardAutoResetEvent());

	std::thread producer = std::thread(producerWorker, &packetQueue);
	std::thread consumer = std::thread(consumerWorker, &packetQueue);

	producer.join();
	consumer.join();

	return 0;
}