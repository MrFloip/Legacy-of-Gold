#ifndef _IEVENT_HPP_
#define _IEVENT_HPP_
#include <map>
#include <vector>
using std::vector;
using std::map;


enum EventMessage
{
	MSG_ENTITY_TAKE_DAMAGE,
	MSG_SPAWN_ENTITY
};

class IEvent;
struct Message
{
	EventMessage eventMsg;
	IEvent* sourceEntity;
	void* msg;
};

class IEvent
{
protected:
	virtual void onEvent(EventMessage eMsg, void* msg) = 0;
public:
	virtual void catchMessage(Message msg) = 0;
};


typedef map<EventMessage,vector<IEvent*>> SubscribeMap;
typedef vector<Message> MessageList;
class EventManager
{
private:
	MessageList messageQueue;
	SubscribeMap subscribers;
	
	//singleton implemetation.
	static EventManager *pInstance;
	EventManager(){}
public:	
	static EventManager* getInstance()
	{
		if(!pInstance)
		{
			pInstance = new EventManager();
		}
		return pInstance;
	}
	EventManager* operator=(EventManager* ev)
	{
		pInstance = ev->pInstance;
		return this;
	} 
	//EventManager functions.
	void subscribe(const EventMessage eMsg,IEvent* entity);
	void unsubscribe(const EventMessage eMsg, IEvent* entity);
	void sendMessage(const Message msg);
};

#endif 