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

ll solve(ll n)
{
    ll sum=0;
    while(n)
    {
        sum+=(n/5);
        n/=5;
    }
    return sum;
}

int main() {
    int ca = 0;
    int t;
    // sieve();
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll l = 0, r = 10000000000;
        ll ans = 0;
        while(l <= r) {
            ll mid = (l+r) / 2;
            ll x = solve(mid);
            if(x == n) {
                ans = mid; r = mid-1;
            } else if(x < n) {
                l = mid + 1;
            } else r = mid - 1;
        }
        cout<<"Case "<<++ca<<": ";
        if(!ans) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
}
