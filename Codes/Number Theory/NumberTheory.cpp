//
// Created by Ebrahim Emad on 5/5/2024.
//
#include <cstdio>
#include <vector>
#include <cmath>
const int N = 1e6 + 6;
using namespace std;
struct new{
    // mult of 2 in range 2 to 10
    vector<int>mult;
    for(int i=x;i<n;i+=x){
        mult.push_back(i);
    }


};
struct Number_theory{

    bool ISPRIME[N];
    // function to check if the current number is pime or not
        void sieve(){
            memset(isprime,1, sizeof(isprime));
            ISPRIME[0]=ISPRIME[1]=0;
            for(int i=2;i*i<N;i++){
                if(ISPRIME[i]){
                    for(int m=i*i;m<N;m+=i){
                        ISPRIME[m]=0;
                    }
                }
           }
        }

        // to get the divisors of a number in  // O(sqrt(n))
        vector<int> GET_D(int n){
            vector<int>ret;
            int i=1;
            for(i=1;i*i<n;i++){
                if(n%i==0){
                    ret.push_back(i);
                    ret.push_back(n/i);
                }
            }
            if(i*i==n)ret.push_back(i);
            return ret;
        }


        // to get the multiples of a number O(n/x)
        vector<int> GET_M(int x,int n){
            vector<int>ret;
            for(int m=x;m<=n;m+=x){
                ret.push_back(m);
            }
            return ret;
        }

        // function to check if the number is prime or not
        bool is_Prime(int n) {   // O(sqrt(n))
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }

        // to get the prime_factors_of_Number
        vector<pair<int,int>>GET_PF(int n){
            vector<pair<int,int>>ret;
            for(int p=2;p*p<n;p++){
                int e=0;
                while(n%p==0){
                    n/=p;
                    e++;
                }
                if(e>0)ret.push_back({p,e});
            }
            if(n>1)ret.push_back({n,1});
            return ret;
        }

         // LCM * GCD = a * b
                 ll LCM(ll a, ll b) {
                    // return (a*b)/__gcd(a, b);
                    return a * (b / __gcd(a, b));
                    }
                    /*
                    Modular Arithmetic
                    (a + b) % m = (a % m + b % m) % m
                    (a - b) % m = (a % m - b % m) % m
                    (a * b) % m = ((a % m) * (b % m)) % m
                    */
};
