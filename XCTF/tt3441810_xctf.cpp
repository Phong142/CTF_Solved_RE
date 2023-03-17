#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    FILE *fp=fopen("./rev100", "r");
    while(1==fscanf(fp, "%x", &c)){
        if(isprint(c) && c!='H' && c!='4' && c!='$' && c!='h')
            printf("%c", c);
    }
    fclose(fp);
    return 0;
}