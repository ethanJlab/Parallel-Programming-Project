// Fibonacci Series using Dynamic Programming

#include <iostream>
#include <chrono>

long long int fibonacci(int n) 
{
    long long int fib[n+2]; // Stores Fibonacci numbers

    // 0th and 1st number of the series are 0 and 1
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) 
    {
        fib[i] = fib[i-1] + fib[i-2]; // Generates ith term by adding the two previous terms
    }

    return fib[n];
}

int main () 
{
    int n;

    // Currently only supports up to the 92nd term before going out of bounds
    std::cout << "Enter number of terms: "; std::cin >>n;

    auto start = std::chrono::high_resolution_clock::now(); // Starts clock

    std::cout << n<<" Fibonacci Term: "<<fibonacci(n)<<std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // Time elapsed


    std::cout << "Program finished in " << duration.count() << " microseconds" << std::endl;
}