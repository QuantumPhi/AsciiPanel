#include <iostream>
#include <Windows.h>

#include "panel.h"

using namespace std;

int main(int argc, char** argv)
{
	Panel* panel = new Panel(5, 5);

	for (int i = 0; i < panel->getWidth(); i += 2)
		for (int j = 0; i < panel->getHeight(); j += 2)
			panel->setTile(i, j, new Tile('#', Tile::BLUE));

	panel->paint(5, 5, 0, 0, 5, 5);

	getchar();

	return 0;
}