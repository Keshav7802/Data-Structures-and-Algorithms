#include<bits/stdc++.h>
using namespace std;

vector<int> Sieve_of_eratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n;i++) {
        for (int j = i * i; j <= n;j+=i) {
            isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n;i++) {
        if(isPrime[i])
            primes.push_back(i);
    }
    return primes;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> primes = Sieve_of_eratosthenes(n);
    for(auto i: primes)
        cout << i << ' ';
    cout << endl;

    return 0;
}