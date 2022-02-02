#include <bits/stdc++.h>

using namespace std;

#define MAX 12345678
#define ll long long

//*******SIEVE***********//
vector<ll> primes;
bitset<MAX> bs;
// ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= 99999; i += 2) {
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

int main() {
    sieve(); int ca = 0;
    int t; scanf("%d", &t);
    while(t--) {
        ll n; scanf("%lld", &n); int cnt = 0;
        for(int i=0; i<primes.size(); i++) {
            int p = primes[i];
            int q = n - p;
            if(p>q) break;
            if(bs[q] && p<=q) cnt++;
        }
        printf("Case %d: %d\n", ++ca, cnt);
    }
}
