/*________________________Bismillahir Rahmanir Rahim___________________
                                                                      |
|                    /\     |     | |\    |     /\     |-------        |
|                   /  \    |     | | \   |    /  \    |               |
|                  /----\   |-----| |  \  |   /----\   |-----          |
|                 /      \  |     | |   \ |  /      \  |               |
|                /        \ |     | |    \| /        \ |               |
|                     14th batch CSE , ID : 12008029                   |
|                     Comilla University                               |
|                     Email : sheikhahnafshifat@gmail.com              |
|______________________________________________________________________*/
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
#define ll                      long long
#define MAX                     1000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define vii                     vector<int>
#define vll                     vector<long long>
#define vp                      vector<pair<ll, ll> >
#define v_min(a)                *min_element(a.begin(),a.end())
#define v_max(a)                *max_element(a.begin(),a.end())
#define v_sum(a)                accumulate(a.begin(),a.end(),0)
#define un(a)                   a.erase(unique(a.begin(),a.end()),a.end())
#define SORT(a)                 sort(a.begin(),a.end())
#define AHNAF                   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define YES                     cout<<"YES"<<endl
#define NO                      cout<<"NO"<<endl
#define testcase(t)             int t;cin>>t;while(t--)
#define reverse(a)              reverse(a.begin(),a.end())
#define ff                      first
#define ss                      second
#define print(a)                for(auto it: a) cout<<it<<" "
#define all(a)                  a.begin(),a.end()
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
 ll mod = 1000000007;
map<ll,ll> factor(ll n) {
    map<ll, ll> tmp;
    while(n%2 == 0) {
        tmp[2]++; n/=2;
    }
    for(ll i = 3; i * i <= n; i+=2) {
        while(n % i == 0) {
            tmp[i]++; n /= i;
        }
    }
    if(n > 1) {
        if(!tmp[n]) {
            tmp[n]++;
        }
    }
    return tmp;
}
long long binpow(long long a, long long b, ll m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m) {
    return binpow(a, m-2, m);
}
int main()
{
    AHNAF; int ca = 0;
    testcase(t)
    {
        ll n, m;cin>>n>>m;
        map<ll,ll> fact = factor(n);
        map<ll, ll> prime;
        for(auto it: fact) {
            prime[it.ff] = it.ss * m;
        }
        ll ans = 1;
       // for(auto it: prime) cout<<it.ff<<" "<<it.ss<<endl;
       for(auto it: prime) {
            ll lob = binpow(it.ff, it.ss+1, mod);
            //cout<<it.ff<<"____"<<lob<<endl;
            //cout<<lob<<endl;
            lob -= 1;
            if(lob < 0) lob += mod;
            ll hor = inv(it.ff-1, mod);
            //cout<<it.ff<<"-----"<<hor<<endl;
             lob = ((lob%mod) * (hor%mod))%mod;
            //cout<<lob<<endl;
            ans = ((ans%mod) * (lob%mod))%mod;
            //cout<<ans<<endl;
        }
        cout<<"Case "<<++ca<<": "<<ans<<endl;
    }
}

