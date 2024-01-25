#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define int ll
using namespace std;

int Power(int a, int b, int mod) {
    int ans = 1;
    while(b > 0) {
        if(b % 2 > 0)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    // a = 5;
    // b = 4;
    cin >> a >> b;
    int a_power_b_with_mod = Power(a, b, MOD);
    cout << a_power_b_with_mod << endl;

    return 0;
}