#include <string>
#include <Windows.h>

#include "panel.h"

int main(int argc, char** argv)
{
	Panel* panel = new Panel(100, 100);

	panel->toggleCursorVisible();

	for (int i = 0; i < panel->getWidth(); i += 2)
	{
		for (int j = 0; j < panel->getHeight(); j += 2)
			panel->setTile(i, j, new Tile('#', Tile::BLUE));
	}

	for (int i = 0; i < 1000; i++)
	{
		panel->paint(0, 0, 35, 15, 5, 3);
	}

	getchar();

	return 0;
}