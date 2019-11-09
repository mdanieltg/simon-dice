#include <chrono>
#include <iostream>
#include <thread>
#include "random.h"

using namespace std;

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