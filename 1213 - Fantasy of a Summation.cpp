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
long long binpow(long long a, long long b, ll m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res;
}
int main()
{
    AHNAF; int ca = 0;
    testcase(t)
    {
        ll n, k, mod;cin>>n>>k>>mod;
        ll sum = 0;
        for(int i=0; i<n; i++) {
            ll x;cin>>x; sum += x; sum %= mod;
        }
        sum = ((sum%mod)*(k%mod)%mod);
        ll now = binpow(n,k-1, mod);
        sum = ((sum%mod)*(now%mod)%mod);
        cout<<"Case "<<++ca<<": ";
        cout<<sum<<endl;
    }

}

