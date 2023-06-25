#include <stdio.h>
#define uc unsigned char

int main(){
    for (uc i=0; i<255; i++){
        uc mess = i;
        char cipher[] = {0x01, 0x21, 0x31, 0x7d, 0x1d, 0x5d, 0x07, 0x01, 0x63, 0x6e, 0x35, 0x5f, 0x4b, 0x23, 0x7e};
        char key;
        for (int j=0; j<2606; j++){
            for (int k=14; k>=0; k--){
                key = cipher[k]^mess;
                cipher[k] = mess;
                mess = key;
            }
        }
        if(cipher[0]=='A')
            // for (int j=0; j<15; j++)
                // printf("%c", cipher[j]);
            puts(cipher);

    }
}