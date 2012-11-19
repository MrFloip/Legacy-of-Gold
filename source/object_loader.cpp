#include "object_loader.hpp"
#include <vector>
#include "flog.hpp"

ObjectLoader::~ObjectLoader()
{
	map<string,ObjectModel*>::iterator it = modelList.begin();
	while(it != modelList.end())
	{
		delete it->second;
		it = modelList.erase(it);
	}
}


bool ObjectLoader::loadObj(string modelName)
{
	vector<GLfloat> vertexPoints;
	vector<GLuint> indexPoints;

	modelFile.open(modelName);
	if(!modelFile.is_open())
		return false;

	char in[256];
	vector<string> objectFileData;
	while(!modelFile.eof())
	{
		modelFile.getline(in,256);
		objectFileData.push_back(in);
	}

	for(unsigned i=0;i<objectFileData.size();i++)
	{
		if(objectFileData[i][0] == '#')
		{
			continue;
		}
		else if(objectFileData[i][0] == 'v' && objectFileData[i][1] != 'n')
		{
			char temp;
			GLfloat tempX, tempY, tempZ;
			sscanf(objectFileData[i].c_str(),"%c %f %f %f",&temp, &tempX, &tempY, &tempZ);
			
			//*ft::Flog::getInstance() <<"read vertex data: " << tempX << " " << tempY << " " << tempZ << "\n";
			vertexPoints.push_back(tempX);
			vertexPoints.push_back(tempY);
			vertexPoints.push_back(tempZ);
			

		}
		else if(objectFileData[i][0] == 'f')
		{
			char temp;
			GLuint tempA, tempB, tempC;
			sscanf(objectFileData[i].c_str(),"%c %d %d %d",&temp, &tempA, &tempB, &tempC);
			//*ft::Flog::getInstance() <<"\nread index data: " << tempA-1 << " " << tempB-1 << " " << tempC-1 << " ";
			indexPoints.push_back(tempA-1);
			indexPoints.push_back(tempB-1);
			indexPoints.push_back(tempC-1);
		}
	}

	//*ft::Flog::getInstance() <<"\nVertex array size: " << vertexPoints.size() << "\n";
	//*ft::Flog::getInstance() <<"\nIndex array size: " << indexPoints.size() << "\n";
	//*ft::Flog::getInstance() <<"\n";
	modelFile.close();

	GLfloat* vertexData = new GLfloat[vertexPoints.size()];
	GLuint* indexData = new GLuint[indexPoints.size()];
	for(unsigned i=0;i<vertexPoints.size();i++)
		vertexData[i] = vertexPoints[i];

	for(unsigned i=0;i<indexPoints.size();i++)
		indexData[i] = indexPoints[i];


	modelList[modelName] = new ObjectModel(vertexData, indexData,vertexPoints.size(),indexPoints.size());
	return true;
}