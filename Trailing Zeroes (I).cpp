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
    for(int i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i);
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
    int t; scanf("%d", &t); sieve(); int ca = 0;
    while(t--) {
        ll n; scanf("%lld", &n); ll ans = 1;
        for(auto it: primes) {
            if(it * it > n) break;
            ll cnt = 1;
            while(n % it == 0) {
                n /= it;
                cnt++;
            }
            ans *= cnt;
        }
        if(n > 1) ans *= 2;
        printf("Case %d: %d\n", ++ca, ans-1);
    }
}
