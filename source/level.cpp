#include "level.hpp"
#include "flog.hpp"


bool Level::loadLevelData(string lFile)
{
	levelFile.open(lFile.c_str(),ios::beg);
	if(!levelFile.is_open())
	{
		#ifdef D_LVLOG_
			//ft::Flog::getInstance()->setColor(ft::LogColor::WHITE | ft::LogColor::INTENSITY);
			//*ft::Flog::getInstance() << "%tCould not read data from: " << lFile << "\n";	
		#endif
		return false;
	}

	levelFile >> tileData.nTiles;
	levelFile >> tileData.nTileTypes;
	tileData.tiles = new LevelTile[tileData.nTiles];
	for(unsigned i=0;i<tileData.nTiles;i++)
	{
		levelFile >> tileData.tiles[i].tileType;
		levelFile >> tileData.tiles[i].x;
		levelFile >> tileData.tiles[i].y;
		levelFile >> tileData.tiles[i].z;
		levelFile >> tileData.tiles[i].w;
		levelFile >> tileData.tiles[i].h;
	
	#ifdef D_LVLOG_
		//ft::Flog::getInstance()->setColor(ft::LogColor::GREEN);
		/*ft::Flog::getInstance() << "Tile[" << i <<"] type:" << tileData.tiles[i].tileType
			<< " x:" << tileData.tiles[i].x
			<< " y:" << tileData.tiles[i].y
			<< " z:" << tileData.tiles[i].z 
			<< " w:" << tileData.tiles[i].w
			<< " h:" << tileData.tiles[i].h << "\n";*/
	#endif
	
	}
	return true;
}