#include "event_test_object.hpp"
#include <iostream>

void EventTest::onEvent(EventMessage eMsg, void* msg)
{
	switch(eMsg)
	{
	case MSG_ENTITY_TAKE_DAMAGE:
		EventTestMessage* message = static_cast<EventTestMessage*>(msg);
		if(message->target == this)
			health -= message->damage;
		break;
	}

}

void EventTest::catchMessage(Message msg)
{
	onEvent(msg.eventMsg, msg.msg);
}