#ifndef _EVENT_TEST_OBJECT_H_
#define _EVENT_TEST_OBJECT_H_
#include "event_manager.hpp"

struct Message
{
	int iMsg;
};


class EventTestObject: public EventManager
{
private:
	Message message;
public:
	EventTestObject();

	void printUid();
	void sendMessage(int value);
	void catchMessage();
};


#endif