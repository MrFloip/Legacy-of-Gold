#ifndef _TEXTURE_ATLAS_HPP_
#define _TEXTURE_ATLAS_HPP_
#include <map>
#include <string>
#include "include_gl.hpp"

using std::map;
using std::string;


class TextureAtlas
{
private:
public:
	TextureAtlas();
	~TextureAtlas();
	GLfloat* getTexture(int id, int pixelWidth, int pixelHeight);
};


#endif //_TEXTURE_ATLAS_HPP_