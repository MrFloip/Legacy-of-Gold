#include "event.hpp"
#include <ctime>

class EventTest;
struct EventTestMessage
{
	EventTest* target;
	int damage;
};


class EventTest: public IEvent
{
private:
	int health;
	int damage;
	void onEvent(EventMessage eMsg, void* msg);
public:
	EventTest(int _health, int _damage)
	{
		health = _health;
		damage = _damage;
	}

	int getDamage(){return damage;}
	int getHealth(){return health;}
	void catchMessage(Message msg);
};