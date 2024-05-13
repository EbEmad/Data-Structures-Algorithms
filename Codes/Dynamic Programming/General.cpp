//
// Created by Ebrahim Emad on 2/13/2024.
//
// General Form
/*
#define N 1000
int a[N];
int n,k;
int memo[N][N];
int vis[N][N];
int func(int l,int r,int k){
    if(l>r)return 0;
    int &ret=memo[l][r];
    if(vis[l[r]])return ret;
    int ch1=func(l+1,r,k+1)+k*a[l];
    int ch2=func(l,r-1,k+1)+k*a[r];
    return ret=max(ch1,ch2);
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<dp(0,n-1,0);
    return 0;
}
 */

#define N 1000
int a[N];
int n,k;
bool memo[N][N];
bool vis[N][N];
string s;
int isba(int l,int r){
    if(l>=r)return 1;
    int &ret=memo[l][r];
    if(vis[l][r])return memo[l][r];
    vis[l][r]=1;

    return ret=s[l]==s[r]&& isba(l+1,r-1); // two && is better than & in number of calls
}
int main(){
   cin>>s;
   int q;cin>>q;
   while(q--){
        int l,r;cin>>l>>r;
       cout<<dp(l--,r--)<<"\n";
   }

    return 0;
}