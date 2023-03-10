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

bool printTOCSV = true;
long long maxFib = 90;
using namespace std;

// Calculates dot product of rows and column
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

 
int fibonacci_matrix(int n)
{
    long long int F[2][2] = {{1,1}, {1,0}};
     
    // First term
    if (n == 0)
        return 0;
         
    power(F, n);
     
    return F[0][0];
}

void testingSuite(long long n) {
    time_t start,end;
    time(&start);
    fibonacci_matrix(n);
    time(&end);
    double time_taken = double(end - start);

    if(printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_matrix.csv", std::ios_base::app);
        myfile << n << "," << time_taken << setprecision(5) << endl;
    }
    else {
        cout << n << "," << time_taken << setprecision(5) << endl;
    }
    
}

 
int main()
{
    int n;

    std::cout << "Enter number of terms: "; std::cin >>n;

    auto start = std::chrono::high_resolution_clock::now(); // Starts clock

    std::cout << n<<" Fibonacci Terms: "<<fibonacci_matrix(n)<<std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // Time elapsed


    std::cout << "Program finished in " << duration.count() << " microseconds" << std::endl;

    if (printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_matrix.csv");
        myfile << "Num,Time" << endl;
    }
    else {
        cout << "Num,Time" << endl;
    }

    for (int i = 0; i <= maxFib; i++) {
        testingSuite(i);
    }
}
 