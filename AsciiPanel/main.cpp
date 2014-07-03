#include <iostream>
#include <Windows.h>

#include "panel.h"

using namespace std;

int main(int argc, char** argv)
{
	Panel* panel = new Panel(5, 5);
	
	panel -> paint(5, 5, 5, 5, 0, 0);

	getchar();

	return 0;
}