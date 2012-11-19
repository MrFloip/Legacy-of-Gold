#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

struct LevelEntity
{
	unsigned entityType;
	float x,y,z;
};

struct LevelTile
{
	unsigned tileType;
	float x,y,z;
	float h,w;
};

struct LevelEntityData
{
	unsigned nEntities;
	unsigned nEntityTypes;
	LevelEntityData* entities;

};

struct LevelTileData
{
	unsigned nTiles;
	unsigned nTileTypes;
	LevelTile* tiles;
};

class Level
{
private:
	ifstream levelFile;
	LevelEntityData entityData;
	LevelTileData tileData;
public:
	Level()
	{
		entityData.nEntities = 0;
		tileData.nTiles = 0;
	}
	~Level()
	{
		if(entityData.nEntities > 0)
			delete[] entityData.entities;
		if(tileData.nTiles > 0)
			delete[] tileData.tiles;
	}
	LevelEntityData getEntityData(){return entityData;}
	LevelTileData getTileData(){return tileData;}
	bool loadLevelData(string lFile);
};

#endif