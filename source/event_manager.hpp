#ifndef _EVENT_MANAGER_HPP_
#define _EVENT_MANAGER_HPP_
#include <map>
#include <vector>

using std::vector;
using std::map;

enum EventMessage
{
	OBJECT_COLLISION,
	CAMERA_MOVEMENT,

};


struct mParam
{
	vector<void*> messageHolder;
};

typedef map<EventMessage,mParam> EventMap;
class EventManager
{
protected:
	static EventMap eMap;
	unsigned uEventId;
	
	virtual void translateMessage(){}
	void generateUid(EventManager* eventObject );
public:
	//delete all Messages.
	virtual ~EventManager(); 

	void dispatchMessage(void* msg,EventMessage eMsg);
	vector<void*> catchMessages(EventMessage eMsg);
};

#endif