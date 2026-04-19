//
// Created by Sofía Marín Bustamante on 19/04/26.
//

#include "Kmp.h"
#include "FailureFunction.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Kmp::kmpSearch(string text, string word) {
    int textn = text.length();
    int wordn = word.length();

    FailureFunction ff;
    vector<int> f = ff.failureFunction(word);
    int s=0;
    for (int i=0; i<textn; i++) {
        while (s>0 && text[i]!=word[s]) {
            s = f[s-1];
        }
        if (text[i]==word[s]) {
            s=s+1;
        }
        if (s==wordn) {
            return "yes";
        }
    }
    return "no";
}

void Kmp::solveExerciseKMP() {
    cout<<"This is the solution to exercise 3.4.6"<< endl;
    string texts[] = {
        "abababaab",
        "abababbaa",
    };
    string word = "ababaa";

    for (int i = 0; i < 2; i++) {   // for para recorrer el arreglo patterns y evaluar cada patron
        string text = texts[i];
        cout << "Exercise 3.4.6" << endl;
        cout << "The word '" << word << "' is a substring of '"<< text <<"' ?"<< endl;
        cout << "Result:  " << kmpSearch(text, word) << endl;
    }
}
