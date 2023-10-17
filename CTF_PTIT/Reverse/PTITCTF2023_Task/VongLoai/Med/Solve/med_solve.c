#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void random_substitution_mapping(char *mapping, unsigned int seed) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(seed);
    strcpy(mapping, alphabet);
    for (int i = 25; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = mapping[i];
        mapping[i] = mapping[j];
        mapping[j] = temp;
    }
	// for (int i=0; i<=25; i++)
	// 	printf("%c", mapping[i]);
	// printf("\n");
}

void substitution_decrypt(char *ciphertext, char *plaintext, char *mapping) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        char char_to_decrypt = ciphertext[i];
        if (char_to_decrypt >= 'A' && char_to_decrypt <= 'Z') {
            for (int j = 0; j < 26; j++) {
                if (mapping[j] == char_to_decrypt) {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        } 
        else if (char_to_decrypt >= 'a' && char_to_decrypt <= 'z') {
            for (int j = 0; j < 26; j++) {
                if (mapping[j] == char_to_decrypt - ('a' - 'A')) {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        } 
        else if (char_to_decrypt >= '0' && char_to_decrypt <= '9') {
            plaintext[i] = char_to_decrypt - 4;
        }
        else {
            plaintext[i] = char_to_decrypt;
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[37] = "FVHVEVB{9dqIv5vdv54y_e5Fa7x_i4_r8wC}";
    //  char ciphertext[37] = "GJEJZJN{n8l7_nr8A_f7fb_jdK_8aCeq!!!}";
    for(int i=1; i<50000; i++){
        char mapping[27];
        char decrypted_plaintext[37];
        // unsigned int seed = 751264;
        random_substitution_mapping(mapping, i<<5);
        substitution_decrypt(ciphertext, decrypted_plaintext, mapping);
        // printf("Decrypted plaintext: %s\n", decrypted_plaintext);
        if (!strncmp(decrypted_plaintext, "PTITCTF", 7)){
            puts(decrypted_plaintext);
            printf("%d\n", i);
            // puts(mapping);
            // break;
        }
    }
    return 0;
}

