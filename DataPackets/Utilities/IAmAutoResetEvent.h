#ifndef I_AM_AUTO_RESET_EVENT
#define I_AM_AUTO_RESET_EVENT

class IAmAutoResetEvent {
public:
	virtual void Set() = 0;
	virtual void Wait() = 0;
};

#endif
