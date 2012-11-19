#include "event_manager.hpp"

EventMap EventManager::eMap;
EventManager::~EventManager()
{
	EventMap::iterator mIt = eMap.begin();
}


void EventManager::generateUid(EventManager* eventObject)
{
	eventObject->uEventId = reinterpret_cast<_Uint32t>(eventObject);
}

void EventManager::dispatchMessage(void* msg,EventMessage eMsg)
{
	eMap[eMsg].push_back(new void*(msg));
}

vector<void*> EventManager::catchMessages(EventMessage eMsg)
{
	return eMap[eMsg];
}