#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl '\n'
#define all(a) a.begin() , a.end()
#define alr(a) a.rbegin() , a.rend()
const int N=2e5;
#define ll long long
using namespace std;

struct Node
{
    ll val;
    ll cnt ;

    Node()
    {
        // update this variable to a value that has no effect on the answer of the operation
        val = 1e9;
        cnt=0;
    }

    Node(long long x,int c)
    {
        val = x;
        cnt=c;
    }
};

struct SegTree
{
    int tree_sz;
    vector<Node> Seg_Data;
    SegTree(int n)
    {
        tree_sz = 1;
        while (tree_sz < n) tree_sz *= 2;
        Seg_Data.resize(2 * tree_sz, Node());
    }

    // update this function for the desired operation
    Node merge(Node & lf, Node & ri)
    {
        Node ans = Node();
        ans.val = min(lf.val, ri.val);
        ans.cnt+=lf.cnt;
        ans.cnt+=ri.cnt;
        return ans;
    }

    void init(vector<long long> & nums, int ni, int lx, int rx) {

        if(rx - lx == 1)
        {
            if(lx < (int)nums.size())
            {
                Seg_Data[ni] = Node(nums[lx],0);
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;
        init(nums, 2 * ni + 1, lx, mid);
        init(nums, 2 * ni + 2, mid, rx);

        Seg_Data[ni] = merge(Seg_Data[2 * ni + 1], Seg_Data[2 * ni + 2]);
    }

    void init(vector<int> & nums)
    {
        init(nums, 0, 0, tree_sz);
    }

    void set(int idx,int val,  int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            Seg_Data[node] = Node(val,1);
            return;
        }

        int mid = (lx + rx) / 2;
        if(idx < mid)
            set(idx,val,  2 * node + 1, lx, mid);
        else
            set(idx,val,  2 * node + 2, mid, rx);

        Seg_Data[node] = merge(Seg_Data[2 * node + 1], Seg_Data[2 * node + 2]);
    }
    void set(int idx,int val) // zero indexed
    {
        set(idx, val, 0, 0, tree_sz);
    }

    Node get_range(int idx,int val, int node, int lx, int rx)
    {
        if(rx-lx==1){
            if(lx<idx && Seg_Data[lx].val>val){
                return Seg_Data[lx];
            }
            return Node();
        }
        if(Seg_Data[node].val>val && rx<=idx)return Seg_Data[node];
        int m=(rx+lx)/2;
        Node lf= get_range(idx,val,2*node+1,lx,m);
        Node ri= get_range(idx,val,2*node+2,m,rx);
        return merge(lf,ri);
    }

    long long get_range(int val,int idx) // zero indexed range and get from l to r-1, i.e [l,r)
    {
        return get_range(idx,val, 0, 0, tree_sz).cnt;
    }

};
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int sz,q,typ;cin>>sz;
    SegTree tree(sz);
    vector<int>v(sz);
    for(int i=0;i<sz;i++){
        cin>>v[i];
    }
    tree.init(v);
    for(int i=0;i<sz;i++){
       cout<<tree.get_range(v[i],i)<<" ";
       tree.set(i,v[i]);
    }

    return 0 ;
}