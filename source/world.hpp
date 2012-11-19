#ifndef _WORLD_HPP_
#define _WORLD_HPP_
#include "include_gl.hpp"
#include <vector>
using std::vector;

class LevelManager;
class EntityManager;
class EventManager;
class World
{
private:
	LevelManager* levelManager;
	EntityManager* entityManager;
	EventManager* eventManager;
public:
	World();
	~World();
	void renderWorld();
};



#endif