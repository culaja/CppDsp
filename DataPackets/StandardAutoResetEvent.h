#ifndef STANDARD_AUTO_RESET_EVENT
#define STANDARD_AUTO_RESET_EVENT

#include "IAmAutoResetEvent.h"
#include <mutex>
#include <condition_variable>

class StandardAutoResetEvent : IAmAutoResetEvent {
public:
	void Set();
	void Wait();
private:
	bool _flag = false;
	std::mutex _mutex;
	std::condition_variable _signal;
};

#endif