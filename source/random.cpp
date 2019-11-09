#include <chrono>
#include <cstdlib>

// Generar caracter (ASCII) aleatorio entre 97 y 122
char rand_num()
{
	int number;
	srand(time(0));

	do
	{
		number = rand()%200;
	} while (number < 97 || number > 122);

	return (char)number;
}
