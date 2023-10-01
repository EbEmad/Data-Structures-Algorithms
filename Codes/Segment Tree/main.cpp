#include <bits/stdc++.h>
using namespace std;
#define ll long long
void const_tree(vector<int>a,vector<int>&seg,int low,int high,int pos){
    if(low==high){
        seg[pos]=a[low];
        return ;
    }
    ll mid=(low+high)/2;
    const_tree(a,seg,low,mid,2*pos+1);
    const_tree(a,seg,mid+1 ,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);

}
int ans_query(vector<int>seg,int qlow,int qhigh,int low,int high,int pos){
    if(qlow<=low && qhigh>=high){
        return seg[pos];
    }
    if(qlow>high || qhigh<low)return 1e9;
    ll mid=(low+high)/2;
    return min(ans_query(seg,qlow,qhigh,low,mid,2*pos+1), ans_query(seg,qlow,qhigh,mid+1,high,2*pos+2));
}

int main() {
    /*
     * n=4
     * -1 2 0 -3
     */
    int n;cin>>n;
      vector<int>a(n);
     for(int i;i<n;i++)cin>>a[i];
    vector<int>seg(2*n-1);
    const_tree(a,seg,0,n-1,0);
    cout<<ans_query(seg,0,3,0,n-1,0)<<endl;
    for(int i=0;i<7;i++)cout<<seg[i]<<" ";

    return 0;
}