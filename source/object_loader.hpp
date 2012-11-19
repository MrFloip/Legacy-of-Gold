#ifndef _OBJECT_LOADER_HPP
#define _OBJECT_LOADER_HPP
#include <fstream>
#include <map>
#include <string>
#include "include_gl.hpp"
using namespace std;

struct ObjectModel
{
	GLuint vertexSize;
	GLuint indexSize;
	GLfloat* objVertexData;
	GLuint* objIndexData;

	ObjectModel(GLfloat* vertexData, GLuint* indexData, unsigned vSize, unsigned iSize)
	{
		objVertexData = vertexData;
		objIndexData = indexData;
		vertexSize = vSize;
		indexSize = iSize;
	}
};

//super simple .obj loader.
class ObjectLoader
{
private:
	ifstream modelFile;
	map<string,ObjectModel*> modelList;
public:
	ObjectLoader(){}
	~ObjectLoader();

	bool loadObj(string modelName);
	ObjectModel* getModel(string modelName)
	{
		return modelList[modelName];
	}

};

#endif