#include <iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;
vector<long double> coinsProb;
ll const N= 3000 +2;
ll const M = 1500 +2;
long double memo[N][M];
long double sumofProb(ll n , ll np){

    if(n == 0) return 1;
    long double &ret = memo[n][np];
    if(ret == ret){return ret;}
    long double ch1 = 0;
    if(np){
      ch1 = (1- coinsProb[n-1])*sumofProb(n-1,np-1);
    }
    long double ch2 = (coinsProb[n-1])*sumofProb(n-1,np);

    return ret = ch1 + ch2;

}
int main(){
    memset(memo, -1, sizeof(memo));
   
    ll n ;
    cin >> n;
    for(ll i =0 ;i  <n;i++){long double k ; cin >> k;coinsProb.push_back(k);}

    long double ans = sumofProb(n,n/2);
    cout << fixed << setprecision(10) << ans;
   


}