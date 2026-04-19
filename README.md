In this repository you will find a program that implements two algorithms: Failure function and KMP.

# Assignment 1 – Failure Function

## What does the failure function do?

The failure function (also called the prefix function) takes a pattern, of length *n* and computes, for each position *s*, the length of the longest proper prefix of the pattern that is also a suffix of the substring ending at position *s*. In other words, `f(s)` answers: "if we've matched the first *s* characters and the next character fails, what is the longest prefix we can still reuse without starting over?"

## What is it used for?

The failure function is a key component of the **Knuth-Morris-Pratt (KMP)** string-matching algorithm, which is used during the **lexical analysis** (token recognition) phase of a compiler. Instead of naively restarting the comparison from scratch after a mismatch, the failure function allows the algorithm to skip ahead by reusing information about characters that have already been matched. This gives KMP a linear **O(n)** time complexity for computing the failure function and **O(n + m)** for the full search, where *n* is the pattern length and *m* is the text length.


## Exercise 3.4.3 – Results

* Pattern: abababaab   
  * Failure Function: 0 0 1 2 3 4 5 1 2 

* Pattern: aaaaaa  
  * Failure Function: 0 1 2 3 4 5

* Pattern: abbaabb   
  * Failure Function: 0 0 0 1 1 2 3          

# Assignment 2 - KMP Algorithm

## What does the KMP algorithm do?
 
The Knuth-Morris-Pratt (KMP) algorithm checks whether a keyword appears as a substring inside a larger text.
 
It uses the failure function (Assignment 1) as a helper. The failure function pre-processes the keyword and tells KMP how far to fall back in the keyword when a mismatch happens, so work is never repeated.

### How the algorithm works
1. Start with s = 0 (zero characters of keyword matched).
2. For each character in the text:
   - If there is a mismatch and s > 0, fall back using f[s-1].
   - If the characters match, advance s by 1.
   - If s == n (full keyword matched), return "yes".
3. If the loop ends with no full match (s!=n), return "no".

## Exercise 3.4.6
 
Keyword: ababaa
 
- (a) Text: abababaab  -> Result: yes (ababaa appears as a substring)
- (b) Text: abababbaa  -> Result: no  (ababaa does not appear)

# General information

### Time complexity
 
- Failure function: O(n) where n = keyword length.
- KMP search: O(m) where m = text length.
- Total: O(m + n).

## How to Run
 
1. Clone this repository:
   ```
   git clone https://github.com/tu-usuario/nombre-del-repo.git
   ```
2. Open the project in CLion (File → Open → select the project folder).
   Note: this project uses CMake, so it is recommended to use CLion or any IDE that supports CMake projects.
3. CLion will automatically detect the CMakeLists.txt and configure the project.
4. Click the green Run button at the top right (or press Shift + F10).
5. The program will start and show a menu in the terminal where you can:
   - Use the KMP algorithm
   - Use the Failure Function
   - Exit the program

## Project Structure

- `failureFunction.h` and `failureFunction.cpp` — Contains the implementation of the failure function algorithm and the function `solveExercise()` that runs the three test patterns from Exercise 3.4.3.
- `Kmp.h` and `Kmp.cpp` — Contains the implementation of the KMP algorithm and the function `solveExerciseKMP()` that runs the two test cases from Exercise 3.4.6.
- `main` — Includes `int menu()` which is the function encharged of managing the user's choice of which algorithm to use or which exercise to run.


## Operating System and Tools
 
- **OS:** macOS 26.4.1 and Windows 11
- **Language:** C++20
- **Compiler:** Apple Clang 21.0.0 and g++.exe (GCC) 13.1.0
- **IDE:** CLion 2025.3.3 and Visual Studio Code

