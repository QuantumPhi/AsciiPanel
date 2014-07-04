#include <iostream>
#include <Windows.h>

#include "panel.h"

using namespace std;

int main(int argc, char** argv)
{
	Panel* panel = new Panel(10, 10);

	panel->toggleCursorVisible();

	for (int i = 0; i < panel->getWidth(); i += 2)
		for (int j = 0; j < panel->getHeight(); j += 2)
			panel->setTile(i, j, new Tile('#', Tile::BLUE));

	panel->paint(2, 1, 10, 4, 5, 1);

	getchar();

	return 0;
}