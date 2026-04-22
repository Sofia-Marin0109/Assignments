//
// Created by Sofía Marín Bustamante on 19/04/26.
//

#include "FailureFunction.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> FailureFunction::failureFunction(string pattern) { // se crea la función, recibe una cadena (patrón) como parámetro y devuelve un arreglo de números enteros
    int n = pattern.length(); // calcula la longitud de la cadena
    vector<int> f(n); // se crea un arreglo para guardar los resultados
    int t = 0; // t contador del prefijo (rastrea la longitud del prefijo)
    f[0] = 0; //s posición cero, (caso base) un string de un solo caracter no tiene prefijos propios, su valor de fallo siempre es cero

    for (int s = 1; s < n; s++) {  // for para recorrer la cadena (el patron dado) desde la posición 1
        while (t > 0 && pattern[s] != pattern[t]) {  // Si algún caracter no coincide con el patron retrocede usando valores ya calculados en vez de empezar desde cero
            t = f[t - 1];
        }
        if (pattern[s] == pattern[t]) { // si coiciden t incrementa, sino guarda cero
            t = t + 1;
            f[s] = t;
        } else {
            f[s] = 0;
        }
    }
    return f;
}

void FailureFunction::solveExercise() {
    cout<<"This is the solution to exercise 3.4.3"<< endl;
    string patterns[] = {
        "abababaab",
        "aaaaaa",
        "abbaabb"
    };

    for (int i = 0; i < 3; i++) {   // for para recorrer el arreglo patterns y evaluar cada patron

        string pattern = patterns[i];
        vector<int> f = failureFunction(pattern);  // se llama la función y se guarda en el arreglo de resultados
        cout << "Pattern: " << pattern << endl;
        cout << "Failure function: ";

        for (int j = 0; j < (int)f.size(); j++) {  // for que imprime los resultados (arreglo de resultados), recorre de izquierda a derecha e imprime cada número
            cout << f[j] << " ";
        }
        cout << endl;
        cout << endl;
    }
}
