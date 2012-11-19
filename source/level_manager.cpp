#include "level_manager.hpp"
#include "entity_manager.hpp"
#include "level.hpp"
#include "flog.hpp"
#include "object_loader.hpp"
#include "flog_format.hpp"

LevelManager::LevelManager(EntityManager* entityManager)
{
	objLoader = new ObjectLoader();
	glGenBuffers(1,&levelVbo);
}

bool LevelManager::loadLevel(string fileName)
{
	levels[fileName] = new Level();
	if(!levels[fileName]->loadLevelData(fileName))
	{
		return false;
	}
	return true;
}

void LevelManager::setActiveLevel(string fileName)
{

	string file = "basic_isometric_cube.obj";
	if(!objLoader->loadObj(file))
	{
		ft::Flog::out() << "%tFailed to load Model\n";
	}

	ft::Flog::out() << "%tapplying vertex data:";
	for(int i=0;i<objLoader->getModel(file)->vertexSize;i++)
		ft::Flog::out() << ft::Format::getString(objLoader->getModel(file)->objVertexData[i]) << " ";

	ft::Flog::out() << "\n" << "%tapplying index data:";
	for(int i=0;i<objLoader->getModel(file)->indexSize;i++)
		ft::Flog::out() << ft::Format::getString(objLoader->getModel(file)->objIndexData[i]) << " ";

	glBindBuffer(GL_ARRAY_BUFFER,levelVbo);
	glBufferData(GL_ARRAY_BUFFER, objLoader->getModel(file)->vertexSize*sizeof(GLfloat), objLoader->getModel(file)->objVertexData, GL_STATIC_DRAW);
	glVertexPointer(3, GL_FLOAT, 0, 0);

}

void LevelManager::renderLevel()
{
	string file = "basic_isometric_cube.obj";
	glBindBuffer(GL_ARRAY_BUFFER,levelVbo);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawElements(GL_TRIANGLES, objLoader->getModel(file)->indexSize, GL_UNSIGNED_INT, objLoader->getModel(file)->objIndexData);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	static float x = 0;
	if(x>360)
		x = 0;
	//glRotatef(x+=10,1,0,0);
	system("pause");
	glRotatef(0.5f,0,1,0);
	
}