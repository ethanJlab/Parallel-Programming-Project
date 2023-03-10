#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Recursive Fibonacci function
long long fib(long long n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

// Thread function to calculate a Fibonacci number
void fib_thread(long long n, long long* result, std::mutex* mtx)
{
    // Calculate Fibonacci number
    long long f = fib(n);

    // Acquire lock to update result array
    mtx->lock();
    *result = f;
    mtx->unlock();
}

// Multithreaded Fibonacci function
long long fib_mt(long long n, int num_threads)
{
    // Initialize result array
    std::vector<long long> results(num_threads);

    // Calculate the range of Fibonacci numbers for each thread
    long long range = n / num_threads;
    long long remainder = n % num_threads;
    long long start = 0;
    long long end = range - 1;

    // Create threads to calculate Fibonacci numbers
    std::mutex mtx;
    std::vector<std::thread> threads(num_threads);
    for (int i = 0; i < num_threads; i++)
    {
        // Adjust the range for the last thread to account for the remainder
        if (i == num_threads - 1)
            end += remainder;

        // Create thread to calculate Fibonacci number in the range
        threads[i] = std::thread(fib_thread, end, &results[i], &mtx);

        // Update the range for the next thread
        end = start + range - 1;
        start += range;
    }

    // Join threads to wait for them to complete
    for (int i = 0; i < num_threads; i++)
        threads[i].join();

    // Sum the results to get the final Fibonacci number
    long long sum = 0;
    for (int i = 0; i < num_threads; i++)
        sum += results[i];
    return sum;
}

// Example usage
int main()
{
    long long n = 50;
    int num_threads = 4;

    long long result = fib_mt(n, num_threads);

    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}
