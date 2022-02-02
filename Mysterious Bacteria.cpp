#include <bits/stdc++.h>

using namespace std;

#define MAX 123456789
#define ll long long

//*******SIEVE***********//

// vector<ll> primes;
// bitset<MAX> bs;
// // ll ar[MAX];
// void sieve() {
//     bs.set();
//     for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
//     bs[0] = bs[1] = 1;
//     primes.push_back(2);
//     for (ll i = 3; i <= 9999; i += 2) {
//         if (bs[i]) {
//             // ar[i] = i;
//             for (ll j = i * i; j <= MAX; j += i) {
//                 bs[j] = 0;
//                 // ar[j]++;
//             }
//             // primes.push_back(i);
//         }
//     }
//     for (int i = 3; i <= MAX; i += 2) {
//         if (bs[i]) primes.push_back(i);
//     }
// }

// Big Mod

ll binpow(ll b, ll p, ll m) {
    long long res = 1;
    b %= m;
    while (p > 0) {
        if (p & 1)
            res = (res % m * b % m) % m;
        b = (b%m * b%m) % m;
        p >>= 1;
    }
    return res;
}


ll solve(ll n)
{
    int neg=0;
    if(n<0) n*=-1,neg=1;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i) continue;
        ll x=n;
        ll cnt=0;
        while(x%i==0) x/=i,cnt++;
        if(x==1)
        {
            if(!neg || cnt%2) return cnt;
        }
    }
    return 1;
}

int main() { 
    int t;cin>>t; int ca = 0;
    while(t--) {
        ll n;cin>>n;
        cout<<"Case "<<++ca<<": ";
        cout<<solve(n)<<endl;
    }     
}
