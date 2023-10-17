#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//secrect == 3240
#define el printf("\n")
unsigned char a6g1ecpknCn18gE[] = "6G1ECPKN>CN18G;ED8RQD:=7:@;7MTEDQAK2SGM5:IHNQ>AEM2";
unsigned char a22233301232120[] = "22233301232120101011320313033011000313301133003212";
int main() {
    int n;
    // char v7[]="PTITCTF{SuP3r_4nt1DeBuG_n_0bFu5c4Te!!}";
    char v7[]="PTITCTF{0bFu5c4Te_4nD_4nT1DeBuG_s0_Ez}";
    // char v7[38];
    int v6;   
    int j;
    for ( j = 50; j >= 0; --j ) {
        v6 = a6g1ecpknCn18gE[j] - 48;
        if ( a22233301232120[j] == 49 )
        {
            v7[v6] ^= 0x2Fu;
        }
        else if ( a22233301232120[j] - 48 <= 1 )
        {
            if ( a22233301232120[j] == 48 )
                --v7[v6];
        }
        else if ( a22233301232120[j] == 50 )
        {
            v7[v6] += 51;
        }
        else if ( a22233301232120[j] == 51 )
        {
            v7[v6] = (unsigned __int8)v7[v6] - 142;
        }
    }
    for(int i=0; i<38; i++){
        printf("%d, ", v7[i]);
  }
}