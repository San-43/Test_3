/// Sandro Martínez Pérez
/// Cuenta::475218

#include <iostream>
#include <windows.h>
#include <limits>
#include <cmath>

using namespace std;

void salir();
void showInfo(struct videogames &a , struct videogames &b);
double minor();
void numberIsOdd(struct videogames &a, struct videogames &b);
double valor(string num);
void arregloB(int valores[3][5]);

struct videogames{

    string nombre_juego;
    int num_personajes;
    float precio;
    string tipo_consola;
    string marca;
};

int main() {
    videogames GEARS_OF_WAR = {"Gears of War Judment", 20, 899.00, "X BOX 360", "Epic Games"};
    videogames CALL_OF_DUTY = {"Call of Duty:Warzone", 37, 570.00, "Mobile", "TiMi Studios"};

    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    system("color 0c");

    int valores[3][5] =
            { { -3, 1, 10, 6, -1},
              { 2, -6, -7, 22, -4},
              {-11, 7, 5, 15, -9} };

    char option;
    char band;
    bool isBack = true;
    double x;
    do {
        system("cls");
        cout << "\t\t" << "+---------------++------------------++----------------------+" << endl;
        cout << "\t\t" << "|---------------||     MENU     ||--------------------------|" << endl;
        cout << "\t\t" << "+----------++---++------------------++---++-----------------+" << endl;
        cout << "\t\t" << "|----------|| C) - c) Valor Menor              ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| A) - a) Arreglo Bidimensional    ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| E) - e) Estructura               ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl;
        cout << "\t\t" << "|----------|| Q) - q) SALIR                    ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------------+" << endl << endl;
        cout << "\tOPCIÓN A ELEGIR: ";
        cin >> option;

        switch (option) {
            case 'C': case 'c':
                cin.ignore(numeric_limits<int>::max(), '\n');
                system("cls");
                x = minor();
                cout << "El menor valor es: " << x;
                cout << endl;
                system("pause");
                break;
            case 'A': case 'a':
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << endl;
                arregloB(valores);
                system("pause");
                break;
            case 'E': case 'e':
                cin.ignore(numeric_limits<int>::max(), '\n');
                system("cls");
                showInfo(GEARS_OF_WAR, CALL_OF_DUTY);
                system("cls");
                numberIsOdd(GEARS_OF_WAR, CALL_OF_DUTY);
                cout << endl;
                break;
            case 'Q': case 'q':
                salir();
                isBack = false;
                break;
            default:
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << "Opción incorrecta, verifique las opciones a seleccionar en el inicio del programa.\n\n";
                system("pause");
                continue;
        }

        system("cls");
        if (isBack) {
            cout << "Desea regresar al programa? S o s para SI, cualquier otra tecla para no." << endl;
            cin >> band;
            if (band == 'S' || band == 's') {
                cin.ignore(numeric_limits<int>::max(), '\n');
                continue;
            } else {
                cout << "\n\n BYE!!!";
                return 0;
            }
        }
    }while(isBack);

    return 0;
}

double minor() {
    double const a = valor("primer");
    double const b = valor("segundo");
    double const *p1 = &a;
    double const *p2 = &b;
    if (*p1 <= *p2) {
        return *p1;
    } else {
        return *p2;
    }
}

void arregloB(int valores[3][5]) {
    int count = 0;
    int cuadrados[3][5];
    int cubos[3][5];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << valores[i][j] << " ";
            cuadrados[i][j] = (int) pow(valores[i][j], 2);
            cubos[i][j] = (int) pow(valores[i][j], 3);
            if (valores[i][j] < 0) {
                count++;
            }
        }
        cout << endl;
    }

    cout << "Número de valores impares: " << count << endl << endl;
    system("pause");
    system("cls");
    cout << "CUADRADOS: \n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << cuadrados[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n";
    system("pause");
    system("cls");
    cout << "CUBOS: \n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << cubos[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
}

void showInfo(videogames &a, videogames &b) {
    cout <<"Nombre del juego: " <<  a.nombre_juego << "\n";
    cout <<"Número de personajes: " << a.num_personajes << "\n";
    cout <<"Precio: " << a.precio << "\n";
    cout <<"Tipo de consola: " << a.tipo_consola << "\n";
    cout <<"Marca: " << a.marca << "\n\n";

    cout <<"Nombre del juego: " <<  b.nombre_juego << "\n";
    cout <<"Número de personajes: " << b.num_personajes << "\n";
    cout <<"Precio: " << b.precio << "\n";
    cout <<"Tipo de consola: " << b.tipo_consola << "\n";
    cout <<"Marca: " << b.marca << "\n\n";
    system("pause");
}

void numberIsOdd(videogames &a, videogames &b) {
    cout << "\n\n";
    if (a.num_personajes % 2 == 0) {
        cout << "El juego: " << a.nombre_juego << " tiene un número de personajes par.\n\n";
    } else {
        cout << "El juego: " << a.nombre_juego << " tiene un número de personajes impar.\n\n";
    }
    if (b.num_personajes % 2 == 0) {
        cout << "El juego: " << b.nombre_juego << " tiene un número de personajes par.\n\n";
    } else {
        cout << "El juego: " << b.nombre_juego << " tiene un número de personajes impar.\n\n";
    }
    system("pause");
}

void salir() {
    system("cls");
    cout << "GRACIAS POR USAR MI APLICACIÓN\n" << endl;
    cout << "\t\t\tAtte. Sandro Martínez Pérez\n\n";
    system("pause");
}

double valor(string num) {
    double x;

    system("cls");
    cout << "Ingrese el " << num << " valor.";
    do {
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto... Solo se admiten números\n";
            cout << "Ingrese el " << num << " valor.";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    return x;
}
