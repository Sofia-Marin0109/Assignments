//
// Created by Sofía Marín Bustamante on 19/04/26.
//

#ifndef ASSIGNMENTS_KMP_H
#define ASSIGNMENTS_KMP_H
#include "FailureFunction.h"
#include <string>
using namespace std;


class Kmp {
    public:
    string kmpSearch(string text, string keyword);
    void solveExerciseKMP();
};


#endif //ASSIGNMENTS_KMP_H