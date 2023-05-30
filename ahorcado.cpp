#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void dibujarAhorcado(int intentos)
{
    // Dibuja el ahorcado según el número de intentos restantes
    if (intentos == 6)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else if (intentos == 5)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else if (intentos == 4)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << "  |     |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else if (intentos == 3)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << " /|     |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else if (intentos == 2)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << " /|\\    |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else if (intentos == 1)
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << " /|\\    |" << endl;
        cout << " /      |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
    else
    {
        cout << "  _______" << endl;
        cout << "  |     |" << endl;
        cout << "  O     |" << endl;
        cout << " /|\\    |" << endl;
        cout << " / \\    |" << endl;
        cout << "        |" << endl;
        cout << "________|" << endl;
    }
}

bool palabraAdivinada(const string &palabraSecreta, const vector<bool> &letrasAdivinadas)
{
    // Verifica si se han adivinado todas las letras de la palabra secreta
    for (int i = 0; i < palabraSecreta.size(); i++)
    {
        if (!letrasAdivinadas[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Palabras posibles para el juego
    vector<string> palabras = {"HOLA", "ADIOS", "PROGRAMACION", "AHORCADO", "LAPTOP"};

    // Genera una semilla de números aleatorios basada en el tiempo actual
    srand(static_cast<unsigned int>(time(nullptr)));

    // Obtiene un índice aleatorio para seleccionar la palabra secreta
    int indice = rand() % palabras.size();

    // Selecciona la palabra secreta
    string palabraSecreta = palabras[indice];

    // Número de intentos disponibles
    int intentos = 7;

    // Vector que almacena qué letras se han adivinado de la palabra secreta
    vector<bool> letrasAdivinadas(palabraSecreta.size(), false);

    cout << "Bienvenido al juego del ahorcado. ¡Adivina la palabra secreta!" << endl;
    cout << "A CONTINUACION TENDRAS QUE ADIVINAR LA PALABRA CORRECTA O EL PEQUEÑO WILLY SERA AHOCADO " << endl;
    cout << "PD: RECUERDA ESCRIBIR LA LETRA SIEMPRE EN MAYUSCULAS GRACIAS";

    while (intentos > 0)
    {
        cout << "Palabra actual: ";
        for (int i = 0; i < palabraSecreta.size(); i++)
        {
            // Muestra las letras adivinadas y guiones bajos para las letras no adivinadas
            if (letrasAdivinadas[i])
            {
                cout << palabraSecreta[i] << " ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Ingresa una letra: ";
        char intento;
        cin >> intento;

        bool acierto = false;
        for (int i = 0; i < palabraSecreta.size(); i++)
        {
            // Verifica si la letra ingresada coincide con alguna letra de la palabra secreta
            if (intento == palabraSecreta[i])
            {
                letrasAdivinadas[i] = true;
                acierto = true;
            }
        }

        if (acierto)
        {
            cout << "¡Adivinaste una letra!" << endl;
        }
        else
        {
            intentos--;
            cout << "Letra incorrecta. Te quedan " << intentos << " intentos." << endl;
        }

        dibujarAhorcado(intentos);

        if (palabraAdivinada(palabraSecreta, letrasAdivinadas))
        {
            cout << "¡Felicidades! Adivinaste la palabra secreta." << endl;
            break;
        }
    }

    if (intentos == 0)
    {
        cout << "Se te acabaron los intentos. La palabra secreta era: " << palabraSecreta << endl;
    }

    return 0;
}
