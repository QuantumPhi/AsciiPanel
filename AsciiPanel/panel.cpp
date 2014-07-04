#include "panel.h"

void Panel::paint(unsigned int dispWidth, unsigned int dispHeight, unsigned int srcX, 
	unsigned int srcY, unsigned int posX, unsigned int posY)
{
	if(dispHeight - 1 > width || dispWidth - 1 > height || dispWidth - 1 < 0 || dispHeight - 1 < 0)
		return;
	for(int i = 0; i < dispWidth; i++)
	{
		for(int j = 0; j < dispHeight; j++)
		{
			COORD pos;
			pos.X = posX + i;
			pos.Y = posY + j;
			SetConsoleCursorPosition(console, pos);
			SetConsoleTextAttribute(console, values[i][j].getColor());
			cout << values[i][j].getGlyph();
		}
		cout << "\n";
	}
}

Tile* Panel::getTile(unsigned int x, unsigned int y)
{
	if(x >= width || y >= height || x < 0 || y < 0)
		return NULL;

	return &values[x][y];
}

void Panel::setTile(unsigned int x, unsigned int y, Tile* tile)
{
	if(x >= width || y >= height || x < 0 || y < 0)
		return;

	values[x][y] = *tile;
}