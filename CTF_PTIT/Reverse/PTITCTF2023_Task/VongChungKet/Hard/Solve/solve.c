#include <stdio.h>
#include <string.h>
#include <windows.h>

#define _DWORD unsigned __int32
#define _WORD unsigned __int16
#define _BYTE unsigned __int8
#define endl printf("\n")

char gen_const(char a1, _BYTE * a2, int a3) {
    int v4; 
    char v6; 
    int v7; 
    _WORD v8; 
    unsigned int v9; 
    char v10; 
    unsigned int v11; 
    _BYTE v12; 
    bool v13; 
    _BYTE * v14; 
    int v15; 
    char v16; 
    int v18; 

    v4 = a3 - 1;
    v18 = 171;
    v6 = 0;
    do {
        if (v4 <= 5) {
            if ( * (_DWORD * ) & a2[4 * v4 + 16])
                v8 = * (_WORD * ) & a2[4 * v4 + 16];
            else
                v8 = * (_WORD * ) & a2[4 * v4];
            v7 = (v8 >> 1) | (_WORD)(((_WORD)(32 * v8) ^ (v8 ^ (_WORD)(4 * (v8 ^ (2 * v8)))) & 0xFFE0) << 10);
            *(_DWORD * ) & a2[4 * v4 + 16] = v7;
        } 
        else {
            v7 = 0;
        }
        v9 = v7 & 0x7FF;
        v10 = v7 & 7;
        v11 = v9 >> 3;
        if (a1)
            v12 = a2[v11 + 44];
        else
            v12 = ~a2[v11 + 44];
        v13 = v18-- == 1;
        a2[v11 + 44] = v12 ^ (1 << v10);
    }
    while (!v13);
    v14 = a2 + 46;
    v15 = 64;
    do {
        v16 = * (v14 - 2);
        v14 += 4;
        v6 ^= * (v14 - 4) ^ * (v14 - 3) ^ * (v14 - 5) ^ v16;
        --v15;
    }
    while (v15);
    return v6;
}

int main(){
 	_DWORD index_array[] = {9, 18, 15, 3, 4, 23, 6, 7, 8, 22, 10, 11, 33, 13, 14, 27, 16, 37, 17, 19, 20, 21, 5, 34, 24, 25, 26, 2, 12, 29, 30, 31, 32, 28, 0, 35, 36, 1};
	_DWORD g_const[] = {1, 3, 1, 1, 2, 1, 3, 1, 2, 2, 4, 4, 1, 3, 4, 4, 4, 1, 2, 1, 4, 1, 4, 3, 1, 2, 4, 4, 2, 2, 1, 3, 4, 2, 1, 2, 2, 3};
	_BYTE default_output[] = {54,236,0,0,54,237,0,0,54,187,0,0,54,140,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
	_BYTE cipher[] = {14,235,243,246,209,107,167,143,61,145,133,43,134,167,107,219,123,110,137,137,24,149,103,202,95,226,84,14,211,62,32,90,126,212,184,16,194,183,0,0};
	_DWORD flow_progr[] = {6, 1, 7, 1, 3, 2, 4, 3, 6, 3, 7, 6, 1, 4, 7, 4, 1, 5, 7, 6, 7, 5, 6, 4, 5, 1, 7, 5, 2, 3, 1, 2, 3, 2, 1, 6, 2, 4};
 
  unsigned char flag[40]={};
 
	for(int i=0;i<38;i++){
		if(flow_progr[i]==1)
			flag[index_array[i]] = cipher[i] ^ gen_const(0, default_output, g_const[i]);
        else if(flow_progr[i]==2)
			flag[index_array[i]] = cipher[i] ^ gen_const(1, default_output, g_const[i]);
        else if(flow_progr[i]==3)
			flag[index_array[i]] = cipher[i] ^ gen_const(1, default_output, g_const[i]);
        else if(flow_progr[i]==4)
			flag[index_array[i]] = cipher[i] ^ gen_const(0, default_output, g_const[i]);
        else if(flow_progr[i]==5)
			flag[index_array[i]] = cipher[i] ^ gen_const(0, default_output, g_const[i]);
        else if(flow_progr[i]==6)
			flag[index_array[i]] = cipher[i] ^ gen_const(1, default_output, g_const[i]);
        else if(flow_progr[i]==7)
			flag[index_array[i]] = cipher[i] ^ gen_const(1, default_output, g_const[i]);
        else
			break;
	}
	printf("PTITCTF{%s}", flag);
    endl;
	return 0;
}