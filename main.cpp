#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

void wait(int);
char rand_num();

int main()
{
	int max_phases = 10,
		current_phase = 0;
	char keys[max_phases];

	while (current_phase <= max_phases)
	{
		keys[current_phase++] = rand_num();

		// Mostrar secuencia en pantalla, caracter por caracter
		for (int i = 0; i < current_phase; i++)
		{
			cout << "\033[2J\033[1;1H";
			cout << "  " << keys[i] << flush;

			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "\033[2J\033[1;1H" << "    " << flush;

		// Leer secuencia de la entrada estándar y compararla
		for (int i = 0; i < current_phase; i++)
		{
			char input;
			do
			{
				cin.get(input);
			} while (input == 13);

			if (input != keys[i])
				return 1;
		}
	}

	cout << "Ganaste!" << endl;

	return 0;
}

// Generar número aleatorio entre 97 y 122
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

// vim: set number:
