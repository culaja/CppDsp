#ifndef STANDARD_MUTEX
#define STANDARD_MUTEX

#include "IAmMutex.h"
#include <mutex>

class StandardMutex : public IAmMutex {
private:
	std::mutex _mutex;
public:
	StandardMutex() {}

	void Lock();

	void Unlock();

private:
	StandardMutex(const StandardMutex&);
};

#endif