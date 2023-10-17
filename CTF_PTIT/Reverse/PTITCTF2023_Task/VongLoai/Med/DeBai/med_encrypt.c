#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

wchar_t cipher[37] = L"FVHVEVB{9dqIv5vdv54y_e5Fa7x_i4_r8wC}";

void _swap(char *a1, char *a2) {
    char temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void _random(char *a1, unsigned int a2) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(a2);
    strcpy(a1, alphabet);
    for (int i = 25; i > 0; i--) {
        int j = rand() % (i + 1);
        _swap(&a1[i], &a1[j]);
    }
}

void _encrypt(char *a1, char *a2, char *a3) {
    for (int i = 0; i < strlen(a1); i++) {
        char chr = a1[i];
        if (chr >= 'A' && chr <= 'Z') {
            a2[i] = a3[chr - 'A'];
        } 
		else if (chr >= 'a' && chr <= 'z') {
            a2[i] = a3[chr - 'a'] + 'a' - 'A';
        } 
		else if (chr >= '0' && chr <= '9'){
            a2[i] = chr + 4;
        }
        else {
            a2[i] = chr;
        }
    }
    a2[strlen(a1)] = '\0';
}

int main() {
    char v0[27] = "";
    char v1[37] = ""; 
    char v2[37] = "";
    char v3[37] = "";
    wchar_t cipher[37]= L"GJEJZJN{n8l7_nr8A_f7fb_jdK_8aCeq!!!}";
    wchar_t tmp[37] = L"";
    printf("Flag: ");
	fgets(v1, sizeof(v1), stdin);
    v1[strcspn(v1, "\n")] = '\0'; 
	srand(time(0));
    unsigned int v5 = (((rand())%(500000-1)));
    // printf("%d\n", v5);
    _random(v0, v5 << 5);
    // unsigned int v4 = 751264;
    // _random(v0, v4);
    _encrypt(v1, v2, v0);
    mbstowcs(tmp, v2, sizeof(v2));
    if (wcscmp(tmp, cipher) == 0) {
        printf("Correct!");
    } else {
        puts(v1);
    }
    system("pause");
    return 0;
}
