#include "StandardAutoResetEvent.h"

void StandardAutoResetEvent::Set() {
	std::lock_guard<std::mutex> _(_mutex);
	_flag = true;
	_signal.notify_one();
}

void StandardAutoResetEvent::Wait() {
	std::unique_lock<std::mutex> lk(_mutex);
	while (!_flag) // prevent spurious wakeups from doing harm
		_signal.wait(lk);
	_flag = false; // waiting resets the flag
}