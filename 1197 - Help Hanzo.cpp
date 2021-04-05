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
#define MAX                     1234567
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

#define n 100005
vector<long long int>s,sg,segment;
long long int p[n],k=1,size;
bool a[n];
long long int prime() {
    long long i,j;
    a[0]=a[1]=1;
    for(i=4; i<=n; i=i+2) {
        a[i]=1;
    }
    for(i=3; i<=sqrt(n); i=i+2) {
        for(j=i*i; j<=n; j=j+2*i) {
            a[j]=1;
        }
    }
    p[0]=2;
    for(i=3; i<=n; i=i+2) {
        if(a[i]==0) {
            p[k]=i;
            //cout<<p[k]<<endl;
            k++;
        }
    }

}

void segmented_sieve(long long int l,long long int u) {
    long long int root,start,i,j,si;
    sg.clear();
    root=sqrt(u)+1;

    for(i=l; i<=u; i++) {
        sg.push_back(i);
    }

    if(l==0) {
        sg[1]=0;
    } else if(l==1) {
        sg[0]=0;
    }

    for(i=0; p[i]<=root; i++) {
        si=p[i];

        start=si*si;

        if(start<l) {
            start=((l+si-1)/si)*si;
        }


        for(j=start; j<=u; j=j+si) {
            sg[j-l]=0;

        }
    }

}

int main() {
    long long int m,g,c,r,t,l,h,u,w,tc,tx,i,j,st;
    prime();
    cin>>tc;

    for(tx=1; tx<=tc; tx++) {
        cin>>l>>u;
        segmented_sieve(l,u);

        for(i=l; i<=u; i++) {
            if(sg[i-l]!=0) {
                segment.push_back(sg[i-l]);
            }
        }
        st=segment.size();
        printf("Case %lld: %lld\n",tx,st);
        segment.clear();
        sg.clear();

    }
    return 0;
}

