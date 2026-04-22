//
// Created by Sofía Marín Bustamante on 19/04/26.
//

#include "Kmp.h"
#include "FailureFunction.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Kmp::kmpSearch(string text, string word) { //recibe el patrón (word) a buscar y el texto en el que la va a buscar
    int textn = text.length(); // longitud del texto 
    int wordn = word.length(); // longitud del patrón (word)

    FailureFunction ff; // objeto tipo failure function para poder invocar los métodos de la clase
    vector<int> f = ff.failureFunction(word); //el vecto f va a contener la failure function del patrón (word)
    int s=0;  // contador que indica la posición en el patrón (word)
    for (int i=0; i<textn; i++) { // i es el contador en el texto, jamás retrocede, solo iteramos sobre el patrón retrocediendo según la ff
        while (s>0 && text[i]!=word[s]) { // mientras no estemos en la posicion 0 del patrón, dado que el caracter del texto y de la palabra no coincidan 
            s = f[s-1]; //retrocedo en el patrón hasta donde diga la failure function (arreglo f)
        }
        if (text[i]==word[s]) { //si coinciden los caracteres entonces s avanza, i no avanza acá en el if porque ya avanza en el for
            s=s+1;
        }
        if (s==wordn) { //si la longitud del patrón es igual al número guardado en s (cantidad de caracteres matched), devuelves que si se encontró
            return "yes";
        }
    }
    return "no"; //si es diferente no encontró la palabra. 
}

void Kmp::solveExerciseKMP() { //ejercicio del libro
    cout<<"This is the solution to exercise 3.4.6"<< endl; 
    string texts[] = {
        "abababaab",
        "abababbaa",
    }; //texto en el que se busca el patrón
    string word = "ababaa"; //la palabra patrón

    for (int i = 0; i < 2; i++) {   // for para recorrer el arreglo texts y evaluar cada patron
        string text = texts[i]; //cada palabra del arreglo texts
        cout << "Exercise 3.4.6" << endl;
        cout << "The word '" << word << "' is a substring of '"<< text <<"' ?"<< endl;
        cout << "Result:  " << kmpSearch(text, word) << endl;
    }
}
