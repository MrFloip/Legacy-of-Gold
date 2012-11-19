#include "texture_atlas.hpp"
TextureAtlas::TextureAtlas()
{
}
TextureAtlas::~TextureAtlas()
{
	delete textureVertex;
}

//Doing the calculations in the set function.
void TextureAtlas::setClippings(int pixelWidth, int pixelHeight)
{
}

GLfloat* TextureAtlas::getTexture(int id)
{
}