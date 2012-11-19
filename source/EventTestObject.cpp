#include "EventTestObject.h"
#include <iostream>

EventTestObject::EventTestObject()
{
	generateUid(this);
	message.iMsg = 1337;
}

void EventTestObject::sendMessage(int value)
{
	message.iMsg = value;
	dispatchMessage(&message,HELLO);
}

void EventTestObject::catchMessage()
{
	vector<void*> vpVoid;
	vpVoid = catchMessages(HELLO);

	for(int i=0;i<vpVoid.size();i++)
	{
		Message *msg = static_cast<Message*>(vpVoid[i]);
		std::cout <<i <<": "<< msg->iMsg <<std::endl;
	}

}

void EventTestObject::printUid()
{
	std::cout << "Unique ID: " << uEventId << std::endl;
}