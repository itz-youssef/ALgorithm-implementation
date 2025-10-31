#include <bits/stdc++.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int Recursive_fibonacci(int n) {
    if (n == 0)
        return 0;       
    else if (n == 1)
        return 1;        
    else
        return Recursive_fibonacci(n - 1) + Recursive_fibonacci(n - 2); 
}

vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B) {
    vector<vector<long long>> result(2, vector<long long>(2, 0));
    result[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    result[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    result[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    result[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    return result;
}

vector<vector<long long>> power(vector<vector<long long>> M, long long n) {
    vector<vector<long long>> Identity_matrix = {{1, 0}, {0, 1}};
    if (n == 0)
        return Identity_matrix;
    if (n == 1)
        return M;
    
    vector<vector<long long>> half = power(M, n / 2);
    vector<vector<long long>> final = multiply(half, half);

    if (n % 2 == 0)
        return final;
    else
        return multiply(final, M);
}

vector<vector<long long>> Matrix_Fibonacci(long long n) {
    vector<vector<long long>> M = {{1, 1}, {1, 0}};
    if (n == 0)
        return {{0, 0}, {0, 0}};
    return power(M, n - 1);
}

int dynamic_fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<int> f(n + 1);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    while (true)
    {
        int n;
        cout << MAGENTA << "Please enter the Fibonacci term: " << RESET;
        cin >> n;

        string choice;
        cout << GREEN  << "Please enter your choice:\n" << RESET;
        cout << YELLOW << "1. Fibonacci using recursion\n" << RESET;
        cout << YELLOW << "2. Fibonacci using matrix exponentiation\n" << RESET;
        cout << YELLOW << "3. Fibonacci using dynamic programming\n" << RESET;
        cout << YELLOW << "4. exit\n" << RESET;
        cin >> choice;

        if (choice == "1") {
            cout << GREEN << "Fibonacci Sequence: " << RESET;
            for (int i = 0; i < n; i++) {
                cout << Recursive_fibonacci(i) << " ";
            }
            cout << endl;
            cout << BLUE << "The " << n << "th Fibonacci number using recursion is: " 
            << RESET << Recursive_fibonacci(n - 1);
        } 
        else if (choice == "2") {
            cout << GREEN << "Fibonacci Sequence: " << RESET;
            for (int i = 0; i < n; i++) {
                vector<vector<long long>> F = Matrix_Fibonacci(i);
                cout << F[0][0] << " ";
            }
            cout << endl;
            vector<vector<long long>> Fn = Matrix_Fibonacci(n-1);
            cout << BLUE << "The " << n << "th Fibonacci number using matrix method is: " 
                << RESET << Fn[0][0];
        }
        else if (choice == "3") {
            cout << GREEN << "Fibonacci Sequence: " << RESET;
            for (int i = 0; i < n; i++) {
                cout << dynamic_fibonacci(i) << " ";
            }
            cout << endl;
            cout << BLUE << "The " << n << "th Fibonacci number using dynamic programming is: " 
                << RESET << dynamic_fibonacci(n - 1);
        }
        else if ( choice == "4"){
            break;
        }

        cout << endl;
        
    }
  
}
