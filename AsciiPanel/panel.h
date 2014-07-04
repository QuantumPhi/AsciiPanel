#include <iostream>
#include <Windows.h>
#include "tile.h"

#define console GetStdHandle(STD_OUTPUT_HANDLE)

using namespace std;

class Panel
{
public:
	Panel(unsigned int width_, unsigned int height_)
	{
		width = width_;
		height = height_;
		values = new Tile*[width];

		for(int i = 0; i < width; i++)
			values[i] = new Tile[height];
	}

	~Panel()
	{
		delete [] values;
	}

	void paint(unsigned int dispWidth, unsigned int dispHeight, unsigned int srcX, 
		unsigned int srcY, unsigned int posX, unsigned int posY);

	int getWidth() { return width; }
	int getHeight() { return height; }

	Tile* getTile(unsigned int x, unsigned int y);
	void setTile(unsigned int x, unsigned int y, Tile* tile);
protected:
	unsigned int width, height;
	Tile** values;
};