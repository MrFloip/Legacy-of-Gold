#include "event.hpp"


EventManager* EventManager::pInstance = NULL;
void EventManager::subscribe(const EventMessage eMsg, IEvent* entity)
{
	vector<IEvent*>::iterator it;
	it = subscribers[eMsg].begin();
	for(;it != subscribers[eMsg].end();it++)
		if(*it == entity)
		{
			return;
		}

	subscribers[eMsg].push_back(entity);
}

void EventManager::unsubscribe(const EventMessage eMsg, IEvent* entity)
{
	SubscribeMap::iterator mIt = subscribers.begin();
	vector<IEvent*>::iterator vIt;
	
	bool unsub = false;
	for(;mIt != subscribers.end();mIt++)
	{
		if(mIt->first == eMsg)
		{
			vIt = mIt->second.begin();
			unsub = true;
			break;
		}
	}

	if(unsub)
	{
		for(;vIt != mIt->second.end();vIt++)
		{
			if(*vIt == entity)
			{
				subscribers[eMsg].erase(vIt);
				break;
			}
		}
	}

}

void EventManager::sendMessage(const Message msg)
{
	for(int i=0;i<subscribers[msg.eventMsg].size();i++)
		if(msg.sourceEntity != subscribers[msg.eventMsg].at(i))
			subscribers[msg.eventMsg].at(i)->catchMessage(msg);
}