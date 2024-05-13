//
// Created by Ebrahim Emad on 4/21/2024.
//
#define  ll long long
#include <vector>
using namespace std;
struct Node{
    ll val;
    Node(){
        val=0; // basic not affective value
    }
    // update mainly set the values
    Node(ll x){
        val=x;
    }

};
struct SegTree{
    int tree_sz;
    vector<Node>Seg_Data;
    // to construct the tree with the default value
    SegTree(int n){
        tree_sz=1;
        // to get the next power of two greater than n
        while(tree_sz<n)tree_sz*=2;
        Seg_Data.resize(2*tree_sz,Node()); // initialize the segment with the default value
    }
    // update the tree for the desired operation
    Node merge(Node &lf,Node & ri){
        Node ans=Node();
        ans.val=min(lf.val,ri.val); // desired op liker mn max sum ..
        return ans;
    }
        // initialize the array based on the desired op
    void init(vector<ll>&nums,int ni,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)nums.size())Seg_Data[ni]=Node(nums[lx]);
            return;
        }
        int m=lx+(rx-lx)/2;
        init(nums,2*ni+1,lx,m);
        init(nums,2*ni+2,m,rx);
        Seg_Data[ni]= merge(Seg_Data[2*ni+1],Seg_Data[2*ni+2]);
    }
    // pass the array and leave the other on us
    void init(vector<ll> & nums){
        init(nums,0,0,tree_sz);
    }

    // to set the  new value on the tree
    void set(int idx,ll val,int node,int lx,int rx){
        if(rx-lx==1){
            Seg_Data[node]=Node(val);
            return;
        }
        int m=(lx+rx)/2;
        // why i check here because we need to put the value on the right idx
        if(idx<m){
            set(idx,val,2*node+1,lx,m);
        }
        else set(idx,val,2*node+2,m,rx);
        Seg_Data[node]= merge(Seg_Data[2*node+1],Seg_Data[2*node+2]);
    }
    void set(int idx,ll val){
        set(idx,val,0,0,tree_sz);
    }
    Node get_range(int l,int r,int node,int lx,int rx){
        if(lx>=l && rx<=r)return Seg_Data[node];
        if(rx<=l || lx>=r)return Node();
        int m=(lx+rx)/2;
        Node lf= get_range(l,r,2*node+1,lx,m);
        Node ri= get_range(l,r,2*node+2,m,rx);
        return merge(lf,ri);

    }
    // zero indexed range get from l to r-1
    Node get_range(int l,int r) {

        return get_range(l,r,0,0,tree_sz);
    }



};
