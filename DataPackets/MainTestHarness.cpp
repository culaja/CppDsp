#include "MainTestHarness.h"

#include "PacketQueue.h"
#include "Utilities/StandardMutex.h"
#include "Utilities/StandardAutoResetEvent.h"
#include "PacketGenerators/FloatNumberSequenceGenerator.h"
#include "PacketProcessors/SimpleOutputPacketProcessor.h"
#include <thread>
#include <windows.h>

/*
	MainTestHarness starts package producer and consumer threads. Both threads use
	the same PacketQueue object for communication. Threads will execute forever.
*/

const size_t MAXIMAL_INPUT_PACKET_SIZE = 10; // Maximum 100 floats can be created in input packet
const size_t FIXED_PACKET_SIZE = 20; // Each output packet will contain 10 floats

/*
	Each producer's cycle uses FloatNumberSequenceGenerator to generate package of random size and pushes
	generated packet to the queue.
*/
void producerWorker(PacketQueue* packetQueuePointer) {
	PacketQueue& packetQueue = *packetQueuePointer;

	IAmPacketGenerator& packetGenerator = FloatNumberSequenceGenerator(MAXIMAL_INPUT_PACKET_SIZE);
	for (;;) {
		const Packet& packet = packetGenerator.GenerateRandomLength();
		packetQueue.Push(packet);

		Sleep(1000);
	}
}

/*
	Each consumer's cycle extracts the packet of specified size from the queue (or waits f there is no
	enough data) and processes the extracted packet using SimpleOutputPacketProcessor.
*/
void consumerWorker(PacketQueue* packetQueuePointer) {
	PacketQueue& packetQueue = *packetQueuePointer;

	IAmPacketProcessor& packetProcessor = SimpleOutputPacketProcessor();
	for (;;) {
		Packet packet = packetQueue.WaitForPacketOfSize(FIXED_PACKET_SIZE);
		packetProcessor.Process(packet);
	}
}

int MainTestHarness::Run(int argc, char* argv[]) {
	PacketQueue& packetQueue = PacketQueue(StandardMutex(), StandardAutoResetEvent());

	std::thread producer = std::thread(producerWorker, &packetQueue);
	std::thread consumer = std::thread(consumerWorker, &packetQueue);

	producer.join();
	consumer.join();

	return 0;
}