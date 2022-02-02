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

pair<int, int> giveFactorFact(int n) {
    map<int, int> v;
    vector<int> temp = {2, 5};
    for (int i = 0; i < temp.size() && temp[i] <= n; i++) {
        int p = temp[i];
        int cnt = 0;
        while (n / p) {
            cnt += (n / p);
            p *= temp[i];
        }
        v[temp[i]] = cnt;
    }
    return {v[2], v[5]};
}

pair<int, int> factor(int p, int q) {
    map<int, int> v;
    while(p % 2 == 0) p /= 2, v[2]++;
    while(p % 5 == 0) p /= 5, v[5]++;
    return {v[2] * q, v[5] * q};
}

int main() {
    int ca = 0;
    int t;
    sieve();
    cin >> t;
    while (t--) {
        int n,r,p,q; cin>>n>>r>>p>>q;
        pair<int, int> upore = giveFactorFact(n);
        pair<int, int> niche1 = giveFactorFact(r);
        pair<int, int> niche2 = giveFactorFact(n-r);
        pair<int, int> niche = {niche1.first + niche2.first, niche2.second+niche1.second};
        pair<int, int> total = {upore.first - niche.first, upore.second-niche.second};
        pair<int, int> pashe = factor(p,q);
        cout<<"Case "<<++ca<<": "<<min(total.first + pashe.first, total.second + pashe.second)<<endl;
    }
}
