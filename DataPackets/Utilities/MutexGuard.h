#ifndef MUTEX_GUARD
#define MUTEX_GUARD

#include "IAmMutex.h"

class MutexGuard {
	IAmMutex& _mutex;
public:
	MutexGuard(IAmMutex& mutex);
	~MutexGuard();
};

#endif