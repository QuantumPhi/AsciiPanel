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

	void paint(int dispWidth, int dispHeight, int srcX, int srcY, int posX, int posY);

	Tile* getTile(unsigned int x, unsigned int y);
	void setTile(unsigned int x, unsigned int y, Tile* tile);
protected:
	unsigned int width, height;
	Tile** values;
};