#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int complexx(int a1, int a2){
    int v3; // [rsp+Ch] [rbp-4h]
  if ( a1 <= 64 || a1 > 125 )
  {
    puts("Suboptimal");
    exit(1);
  }
  v3 = (a2 + 65) % 122;
  if ( v3 <= 64 )
    v3 += 61;
  return (unsigned int)v3;
}

__int64 complex2(__int64 a1, int a2){
    int v3; // [rsp+8h] [rbp-4h]

  v3 = (a2 + 65) % 122;
  if ( v3 <= 64 )
    v3 += 61;
  return (unsigned int)v3;
}
int main() {
    faster;
    char cipher[] = "xk|nF{quxzwkgzgwx|quitH";
    char flag[24]={};
    for (int i=0; i<=22; i++){
        for (int j=65; j<=125; j++){
            unsigned int tmp = complexx(j, j);
            __int64 tmp2 = complex2(tmp, tmp);
            if(tmp2 == cipher[i]){
                flag[i]=(char)j;
                break;
            }
        }
    }
    puts(flag);
    return 0;
}