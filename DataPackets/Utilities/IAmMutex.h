#ifndef I_AM_MUTEX
#define I_AM_MUTEX

class IAmMutex {
public:
	virtual void Lock() = 0;

	virtual void Unlock() = 0;
};

#endif
