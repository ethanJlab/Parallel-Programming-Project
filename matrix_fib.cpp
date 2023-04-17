// Fibonnaci Series using Matrix Multiplcation
/*
         n
| 1   1 |         | F_n+1   F_n   |
| 0   1 |     =   | F_n     F_n+1 | 
*/
#include <iostream>
#include <chrono>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

void testingSuite(long long n);
long long int fibonacci_matrix(int n);

bool printTOCSV = true;
long long maxFib = 50;

using namespace std;

int main() {
    if (printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_matrix.csv");
        myfile << "Num,Time" << endl;
    }
    else {
        cout << "Num,Time" << endl;
    }

    //testingSuite(5);

    for (int i = 0; i <= maxFib; i++) {
        testingSuite(i);
    }
    
    return 0;
}

void matrix_multiplication(long long int F[2][2], long long int M[2][2])
{
    long long int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long int z = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}
 
void power(long long int F[2][2], int n)
{
    long long int M[2][2] = { { 1, 1 }, { 1, 0 } };
     
    // Multiplies matrix by itself n-1 times
    for(int i = 2; i <= n-1; i++)
        matrix_multiplication(F, M);
}

long long int fibonacci_matrix(int n)
{
    long long int F[2][2] = {{1,1}, {1,0}};
     
    // First term
    if (n == 0)
        return 0;
         
    power(F, n);
     
    return F[0][0];
}

// Hardcoded so we don't waste time checking
long long checkFibonacciNumber(long long n) {
    long long fibList[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,
    17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,
    14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,
    1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,
    86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,
    2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,
    44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,
    806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,
    14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,
    160500643816367088,259695496911122585,420196140727489673,679891637638612258,1100087778366101931,
    1779979416004714189,2880067194370816120,4660046610375530309,7540113804746346429};

    return fibList[n];
}
void testingSuite(long long n) {
    auto start = std::chrono::high_resolution_clock::now(); // Starts clock

    assert(fibonacci_matrix(n) == checkFibonacciNumber(n)); // Verifies correct number

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); // Time elapsed

    double time_taken = static_cast<double>(duration.count());
    
    if(printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_matrix.csv", std::ios_base::app);
        myfile << n << "," << time_taken << setprecision(5) << endl;
    }
    else {
        cout << n << "," << time_taken << setprecision(5) << endl;
    }
}


