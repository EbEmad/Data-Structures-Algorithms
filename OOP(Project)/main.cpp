#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

signed main() {
    int process;
        while(true){
            cout<<"Please Enter Your Process\n";
            cout<<"1-Add Student\t\t2-Remove Student\n";
            cout<<"3-Edit Student\t\t4-Show Student\n";
            cin>>process;
            int flag=0;
            switch (process) {
                case 1:
                    cout<<"Process Add\n";
                    break;
                case 2:
                    cout<<"Process Remove\n";
                    break;
                case 3:
                    cout<<"Process Edit\n";
                    break;
                case 4:
                    cout<<"Process Show\n";
                    break;
                case 5:
                    cout<<"Process Exit\n";
                    flag=1;
                    break;
                default:
                    cout<<"Invalid Case\n";


            }
            if(flag)
                break;
        }


    return 0;
}
