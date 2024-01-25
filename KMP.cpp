#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
    for(auto i: arr)
        cout << i << " ";
    cout << endl;
}

vector<int> computeLPS(string &p, int m) {
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i++] = len;
        }
        else
        {
            if (len == 0)
                lps[i++] = len;
            else
                len = lps[len - 1];
        }
    }
    return lps;
}

vector<int> KMP(string &s, string &p) {
    int n = s.length(), m = p.length();
    vector<int> lps = computeLPS(p, m); // stores the max len the prefix of P(0, i) == suffix of P(0, i);
    // print(lps);
    vector<int> indexes;
    int i = 0, j = 0;
    while(i <= n) {
        if(j == m) {
            indexes.push_back(i - j);
            j = lps[j - 1];
            continue;
        }
        if(i == n)
            break;
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            if(j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    // print(indexes);
    return indexes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "ABABDABACDABABCABAB", p = "ABABCABAB";
    // cin >> s >> p;
    vector<int>
        indexes_of_p_as_substr_in_s = KMP(s, p);
    for(auto i: indexes_of_p_as_substr_in_s)
        cout << i << " ";
    cout << endl;

    return 0;
}