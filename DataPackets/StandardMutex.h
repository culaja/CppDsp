#ifndef STANDARD_MUTEX
#define STANDARD_MUTEX

#include "IAmMutex.h"
#include <mutex>

class StandardMutex : IAmMutex {
private:
	std::mutex _mutex;
public:
	void Lock();

	void Unlock();
};

#endif