//
// Created by Ebrahim Emad on 2/13/2024.
//
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
#define N 1000
// dp (ranges  )  idea
// ( 1 2 3 -4 5)
int n,k;
int a[N];
int memo[N][N][2];
int vis[N][N][2];
int dp(int l,int r,int sign) {
    if(r==n)return 0;
    if(r-l+1>k)return -1e15;
    int &ret=memo[l][r][sign];
    if(vis[l][r][sign])return ret;
    vis[l][r][sign]=1;

    int g=sign?-1*a[r]:a[r];
    int ch1=dp(l,r+1,sign);
    int ch2=dp(r+1,r+1,sign^1);
    return ret=max(ch1,ch2)+g;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;//cin>>tc;
    while(tc--){
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<dp(0,0,0);
    }
}