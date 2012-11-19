#ifndef IMAGECACHE_HPP
#define IMAGECACHE_HPP

#include <string>
#include <map>
#include <vector>
#include <SFML/graphics.hpp>
#include "include_gl.hpp"

using std::string;
using std::map;
using std::vector;

namespace ft
{

	namespace ImageCache 
	{
		typedef map<string,sf::Texture*> ImageMap;
		typedef vector<string> PriorityVector;

		//sets the total amount of images to be loaded at one time.
		void setStackSize(const unsigned _stackSize);
		//load  image-resources into memory.
		void loadImage(string filePath);
		void generateGlTexture(string filePath);
		//obtains an image-resource to be used.
		sf::Texture* getImage(string filePath);
		//discard images from memory.
		void discardImage(string filePath);
		//discards bottom image and return remaining vector size.
		unsigned discardBottomImage();
	}
}

#endif // IMAGECACHE_HPP
