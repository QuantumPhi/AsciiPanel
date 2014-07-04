#include "panel.h"

void Panel::paint(unsigned int srcX, unsigned int srcY, unsigned int endX, 
	unsigned int endY, unsigned int posX, unsigned int posY)
{
	if (srcX >= width || srcX > endX || srcY >= height || srcY > endY)
		return;
	for(int i = srcX; i < width && i <= endX; i++)
	{
		for(int j = srcY; j < height && j <= endY; j++)
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

void Panel::paintText(string text, Tile::ColorValue color, unsigned int posX, unsigned int posY)
{
	COORD pos;
	pos.X = posX;
	pos.Y = posY;
	SetConsoleCursorPosition(console, pos);
	SetConsoleTextAttribute(console, color);
	cout << text.c_str();
}

void Panel::toggleCursorVisible()
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(console, &info);
	info.bVisible = !info.bVisible;
	SetConsoleCursorInfo(console, &info);
}

bool Panel::isCursorVisible()
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(console, &info);
	return info.bVisible;
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