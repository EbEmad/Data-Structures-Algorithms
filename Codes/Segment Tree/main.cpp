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
void func(int a[],int seg[],int l,int h,int pos){
    if(l==h){
        seg[pos]=a[l];
        return ;
    }
    ll m=(l+h)/2;
    func(a,seg,l,m,2*pos+1);
    func(a,seg,m+1,h,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int get_ans(int seg[],int ql,int qh,int l,int h,int pos){
    if(ql>h || l>qh)return 1000;
    if(ql<l && qh>=h)return seg[pos];
    ll m=(l+h)/2;
    return min(get_ans(seg,ql,qh,l,m,2*pos+1),get_ans(seg,ql,qh,m+1,h,2*pos+2));
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
    vector<int>seg(7);
    const_tree(a,seg,0,n-1,0);
    //cout<<ans_query(seg,1,3,0,n-1,0);
    for(int i=0;i<7;i++)cout<<seg[i]<<" ";
    return 0;
}