#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    faster;
    char data[21] = "bHEC_T]PLKJ{MW{AdW]Y";
    char flag[21]={};
    int check = 1;
    for(int key=0; key <=255; key++){
        for(int i=0; i<20; i++){
            flag[i] = data[i] ^ key;
            if(flag[0]=='F'){
                check = 0;
                cout << flag[i];
            }
        }
        if(check==0)
          break;
    }
    return 0;
}