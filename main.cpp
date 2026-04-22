#include <iostream>
#include "FailureFunction.h"
#include "Kmp.h"
using namespace std;

void menu(){
    Kmp kmp;
    FailureFunction f;
    cout<<"Hello, choose the option of which algorithm you want to use: "<<endl;
    cout <<"1. KMP algorithm" <<endl;
    cout <<"2. Failure function" <<endl;
    cout <<"3. Finish program" <<endl;
    int choice;
    cout<<"Your choice: "<<endl;
    cin>>(choice);
    switch (choice) {
        case 1:
            cout<<"KMP algorithm"<<endl;
            cout<<"1. Solve book exercise 3.4.6" <<endl;
            cout<<"2. Use KMP algorithm" <<endl;
            cout<<"Your choice: " <<endl;
            int kmpchoice;
            cin >> kmpchoice;
            if (kmpchoice == 1) {
                kmp.solveExerciseKMP();
            } else if (kmpchoice == 2) {
                cout<<"Write the word that you want to search: " <<endl;
                string word;
                cin >> word;
                cout<<"Write the text in which you want to search it up: "<<endl;
                string text;
                cin >> text;
                cout << "Result: " << kmp.kmpSearch(text, word) << endl;
            }
            menu();
            break;
        case 2:
            cout<<"Failure function" <<endl;
            cout<<"1. Solve book exercise 3.4.3" <<endl;
            cout<<"2. Use failure function" <<endl;
            cout<<"Your choice: " <<endl;
            int fchoice;
            cin >> fchoice;
            if (fchoice == 1) {
                f.solveExercise();
            } else if (fchoice == 2) {
                cout<<"Write the string: " <<endl;
                string pattern;
                cin >> pattern;
                vector<int> result = f.failureFunction(pattern);
                cout << "Result: ";
                for (int i = 0; i < result.size(); i++) {
                    cout << result[i] << " ";
                }
                cout << endl;
            }
            menu();
            break;
        case 3:
            cout<<"You have exited the program" <<endl;
            break;
        default:
            cout<<"Please enter a valid choice (1, 2 or 3)" <<endl;
            menu();
            break;
    };

}

int main() {
    menu();
    return 0;
}
