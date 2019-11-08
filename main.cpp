#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

char rand_num();
void game(int);

int main()
{
	int levels;

	cout << "Simón dice" << endl;
	cout << "Cantidad de niveles (0 para infinito): ";
	cin >> levels;

	cout << "\033[2J\033[1;1H";

	if (levels > 0)
		game(levels);
	else
		game(32000);

	return 0;
}

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

// Juego
void game(int max_phases)
{
	char keys[max_phases];
	int current_phase = 0;

	while (current_phase < max_phases)
	{
		// Asignar letra aleatoria
		keys[current_phase++] = rand_num();

		// Mostrar secuencia en pantalla, caracter por caracter
		for (int i = 0; i < current_phase; i++)
		{
			cout << "\033[2J\033[1;1H";
			cout << "  " << keys[i] << flush;

			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "\033[2J\033[1;1H" << "Tu respuesta: " << flush;

		// Leer secuencia de la entrada estándar y compararla
		for (int i = 0; i < current_phase; i++)
		{
			char input;
			do
			{
				cin.get(input);
			} while (input == 10);

			if (input != keys[i])
			{
				cout << "Nivel " << current_phase << endl;
				cout << "La secuencia era ";

				for (int j = 0; j < current_phase; j++)
					cout << keys[j];

				cout << endl;

				return;
			}
		}
	}

	cout << "¡Ganaste!" << endl;

	return;
}
// vim: set number:
