#include "StandardMutex.h"

void StandardMutex::Lock() {
	_mutex.lock();
}

void StandardMutex::Unlock() {
	_mutex.unlock();
}
