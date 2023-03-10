#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long int> memo;
unordered_map<int, long long int> memo2;

long long int fibonacci_memo(long long int n) {
  if (n <= 1) {
    return n;
  }

  if (memo.find(n) != memo.end()) {
    return memo[n];
  }

  long long int fib = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
  memo[n] = fib;
  return fib;
}


int main() {
  int n = 82;
  cout << "fibonacci_memo(" << n << ") = " << fibonacci_memo(n) << endl;
  cout << "fibonacci_db(" << n << ") = " << fibonacci_dp(n) << endl;

  return 0;
}