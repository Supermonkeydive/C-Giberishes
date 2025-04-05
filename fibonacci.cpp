#include <iostream>
#include <math.h>

using namespace std;
class fibonacci {
    public:
    typedef long long ll;
    
    ll recursiveFibonacci(ll n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 1;
        } 
        else {
            return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
        }
    }
    
    ll iterativeFibonacci(ll n) {
        ll temp;
        ll f1 = 0;
        ll f2 = 1;
        if (n <= 0) {
            return f1;
        }
        else if (n == 1) {
            return f2;
        }
        for (ll i = 2; i <= n+1;i++) {
            temp = f2;
            f2 += f1;
            f1 = temp;
        }
        return f2;
    }
    
    ll formulaFibonacci(ll n) {
        return ( pow(((1+sqrt(5))/2), n) - pow(((1-sqrt(5))/2), n)/ sqrt(5));
    }
    
};

int main() {
    fibonacci fib;
    fibonacci::ll fib1 = fib.recursiveFibonacci(2);
    fibonacci::ll fib2 = fib.iterativeFibonacci(2);
    fibonacci::ll fib3 = fib.formulaFibonacci(2);
    cout << "recursive result:" << fib1 << endl;
    cout << "iterative result:" << fib2 << endl;
    cout << "formula result:" << fib3 << endl;
    
}
