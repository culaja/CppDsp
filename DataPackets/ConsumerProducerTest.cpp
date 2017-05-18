#include "ConsumerProducerTest.h"

#include "PacketQueue.h"
#include "StandardMutex.h"
#include "FloatNumberSequenceGenerator.h"
#include "SimpleOutputPacketProcessor.h"
#include <thread>
#include <windows.h>

const size_t MAXIMAL_INPUT_PACKET_SIZE = 100;
const size_t FIXED_PACKET_SIZE = 10;

void producerWorker(PacketQueue& packetQueue) {
	IAmPacketGenerator& packetGenerator = FloatNumberSequenceGenerator(MAXIMAL_INPUT_PACKET_SIZE);
	for (;;) {
		Packet& packet = packetGenerator.GenerateRandomLength();
		packetQueue.Push(packet);

		Sleep(1000);
	}
}

void consumerWorker(PacketQueue& packetQueue) {
	IAmPacketProcessor& packetProcessor = SimpleOutputPacketProcessor();
	for (;;) {
		Packet& packet = packetQueue.WaitForPacketOfSize(FIXED_PACKET_SIZE);
		packetProcessor.Process(packet);
	}
}

int ConsumerProducerTest::Run(int argc, char* argv[]) {
	PacketQueue packetQueue = PacketQueue(StandardMutex());

	std::thread producer = std::thread(producerWorker, packetQueue);
	std::thread consumer = std::thread(consumerWorker, packetQueue);

	producer.join();
	consumer.join();

	return 0;
}