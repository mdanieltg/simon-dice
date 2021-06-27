#include <iostream>
#include "game.h"
#define MAX_LIMIT 32767

using namespace std;

int main()
{
	int levels;

	cout << "Simón dice" << endl;
	cout << "Cantidad de niveles (0 para infinito): ";
	cin >> levels;

	cout << "\033[2J\033[1;1H";

	if (levels > 0)
	{
		game(levels);
	}
	else
	{
		game(MAX_LIMIT);
	}

	return 0;
}
