#include "MutexGuard.h"

MutexGuard::MutexGuard(IAmMutex& mutex): _mutex(mutex) {
	_mutex.Lock();
}

MutexGuard::~MutexGuard() {
	_mutex.Unlock();
}