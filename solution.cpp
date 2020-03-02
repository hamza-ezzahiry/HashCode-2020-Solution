
/**
 *  *    author:  SpiderX       
 *   **/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>
#include <ctype.h>
#include <bitset>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b)	for(ll i = a;i < b ;i++)


//		string binary = bitset<8>(a).to_string();
//		cout <<binary<<"\n";
//		unsigned long k = bitset<8>(binary).to_ulong();
//		cout <<k<<"\n";
//
using namespace std;

typedef    unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef vector<int> vi;
typedef pair <int,int> pi;


/*#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

vector <ll> b;
bool sortt(ll l,ll r)
{
    ll asd = b[l];
    ll asdd = b[r];
    
    if(asd>asdd)
        return 1;
    else
    {
        return 0;
    }
    
}

set<ll> allbooks;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("c_incunabula.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll books,libs, days;
    //vector <ll> b;
    cin >>books>>libs>>days;

    REP(i,0,books)
    {
        ll kk;
        cin>>kk;
        b.push_back(kk);
        //cin >>b[i];
    }
    //map<ll,vector<ll> >libook;
    vector<vector<ll> > libook;
    
    vector<pair<ll,pair<ll,ll> > > all;
    int kkk=0;
    REP(i,0,libs)
    {
        ll nobooks,nosignup,noship;
        cin >>nobooks>>nosignup>>noship;
        all.push_back({nosignup,{noship,i}});
        libook.push_back(vector<ll>());
        for(ll k=0;k<nobooks;k++)
        {
            ll bo;
            cin>>bo;
            
            // cout<<i<<" "<<bo<<endl;
            if(allbooks.count(bo)!=0)
            libook[i].push_back(bo);
            allbooks.insert(bo);
            
        }
        // for(auto k:libook[i])
        // cout<<k<<" ";
        // cout<<endl;
        if(libook[i].size())kkk++;
        sort(libook[i].begin(),libook[i].end(),sortt);
    }
    
    sort(all.begin(),all.end());
    cout<<kkk<<endl;
    //vector<vector<ll> > libook2;
    for(auto i:all)
    {
        if(libook[i.second.second].size()!=0){
        cout<<i.second.second<<" "<<libook[i.second.second].size()<<endl;
        
        for(auto j:libook[i.second.second])
            cout<<j<<" ";
        
        cout<<endl;
        }
    }
    
    // for(ll i=0;i<libs;i++)
    // {
    //     cout<<i<<" "<<libook[i].size()<<endl;
    //     for(auto j:libook[i])
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
    return (0);
}
