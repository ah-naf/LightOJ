#include <bits/stdc++.h>

using namespace std;

#define MAX 10000007
#define ll long long

//*******SIEVE***********//
/*
vector<ll> primes;
bitset<MAX> bs;
ll ar[MAX+2];
ll csum[15][MAX+2];
vector<ll> lucky;
void sieve() {
    bs.set();
    //for (int i = 4; i <= MAX; i += 2) bs[i] = 0, ar[i] = 1;
    //bs[0] = bs[1] = 0; ar[2] = 1; ar[1] = 1;
    primes.push_back(2);
    for (ll i = 2; i <= MAX; i += 1) {
        if (ar[i] == 0) {
            for (ll j = i; j <= MAX; j += i) {
                bs[j] = 0;
                ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for(ll i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i);
    }
    for(int i=0; i<=10; i++) {
        for(int j=1; j<=MAX; j++) {
            csum[i][j] = csum[i][j-1] + (ar[j] == i);
        }
    }
}
*/
ll fact[1000008], c=1000003;

void pre() {
        fact[0] = 1;
        for(int i=1; i<=1000007; i++) {
            fact[i] = (fact[i-1] * i) % c;
        }
}

unsigned ll power(unsigned ll x, int y, int p)
{
    unsigned ll res = 1;

    x = x % p;

    while (y > 0) {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned ll modInverse(unsigned ll n, int p)
{
    return power(n, p - 2, p);
}

unsigned ll fermet(unsigned ll n, int r, int p)
{
    if (r == 0)
        return 1;
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}

int main()
{
    pre(); int ca = 0;
    int t; cin>>t;
    while(t--) {
        int a,b;cin>>a>>b;
        cout<<"Case "<<++ca<<": "<<fermet(a,b,c)<<endl;
    }
}
