#ifndef _LEVEL_MANAGER_HPP_
#define _LEVEL_MANAGER_HPP_
#include <vector>
#include "include_gl.hpp"
#include <map>

using std::map;
using std::string;

class Level;
class EntityManager;
class ObjectLoader;
class LevelManager
{
private:
	ObjectLoader* objLoader;

	map<string,Level*> levels;
	EntityManager* entityManager;

	GLuint levelVbo;
	GLuint levelIndexVbo;

	GLfloat* vertexArray;
	GLfloat* textureArray;
	GLuint* indexArray;
	unsigned vertexSize;
public:
	~LevelManager(){delete objLoader;}
	LevelManager(EntityManager* _entityManager);
	bool loadLevel(string levelName);
	void freeLevel(string levelName);
	void setActiveLevel(string levelName);

	void renderLevel();
};
#endif