#include <iostream>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <thread>
#include <future>
#include <cstdlib>

using namespace std;

void testingSuite(long long n);
long long fib(long long n);
long long checkFibonacciNumber(long long n);
long long multithreadedFib(long long n);

bool printTOCSV = true;
long long maxFib = 60;



//main
int main() {
    if (printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_naive_multithreaded.csv");
        myfile << "Num,Time" << endl;
        cout << "Num,Time" << endl;
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

long long multithreadedFib(long long n) {
    if (n <= 1) {
        return n;
    }
    auto f1 = std::async(std::launch::async, fib, n-1);
    auto f2 = std::async(std::launch::async, fib, n-2);
    return f1.get() + f2.get();
}
long long fib(long long n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}


void testingSuite(long long n) {
    time_t start,end;
    time(&start);
    assert(multithreadedFib(n) == checkFibonacciNumber(n));
    time(&end);
    double time_taken = double (end-start);

    if(printTOCSV) {
        std::ofstream myfile;
        myfile.open("fib_naive_multithreaded.csv", std::ios_base::app);
        myfile << n << "," << time_taken << setprecision(5) << endl;
    }
    else {
        cout << n << "," << time_taken << setprecision(5) << endl;
    }

}

long long checkFibonacciNumber(long long n) {
    long long fibList[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,160500643816367088,259695496911122585,420196140727489673,679891637638612258,1100087778366101931,1779979416004714189,2880067194370816120,4660046610375530309,7540113804746346429};

    return fibList[n];
}
