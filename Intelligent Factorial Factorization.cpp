#include <bits/stdc++.h>

using namespace std;

#define MAX 1234567
#define ll long long

//*******SIEVE***********//

vector<ll> primes;
bitset<MAX> bs;
// ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 1;
    primes.push_back(2);
    for (ll i = 3; i <= 9999; i += 2) {
        if (bs[i]) {
            // ar[i] = i;
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
                // ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for (int i = 3; i <= MAX; i += 2) {
        if (bs[i]) primes.push_back(i);
    }
}

// Big Mod
/*
ll binpow(ll b, ll p, ll m) {
    long long res = 1;
    while (p > 0) {
        if (p & 1)
            res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return res;
}
*/
int main() {
    int ca = 0;
    int t; sieve();
    cin >> t;
    while (t--) {
        vector<pair<ll, ll>> v;
        int n;
        cin >> n;
        for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
            int p = primes[i];
            int cnt = 0;
            while (n / p) {
                cnt += (n / p);
                p *= primes[i];
            }
            v.push_back(make_pair(primes[i], cnt));
        }
        sort(v.begin(), v.end());
        cout << "Case " << ++ca << ": ";
        cout << n << " = ";
        // map<int, int>::iterator it;
        for (int it = 0; it < v.size(); it++) {
            if (it == v.size() - 1) {
                cout << v[it].first << " (" << v[it].second << ")" << endl;
            } else
                cout << v[it].first << " (" << v[it].second << ") * ";
        }
    }
}
