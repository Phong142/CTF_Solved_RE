#include <stdio.h>
#include <string.h>

int main(){
	char flag[]="you_know_how_to_remove_junk_code";
	for(int i=0; i<strlen(flag); i++){
		printf("%c", (char)(flag[i])^0x25);
	}
}

//\JPzNKJRzMJRzQJzW@HJS@zOPKNzFJA@  
// --> encrypt sang base64