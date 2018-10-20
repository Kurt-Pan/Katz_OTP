// read key from key.txt (hex) and ciphertext from ctext.txt (hex);
// output message to ptext2.txt (ASCII)

// The user must ensure that the lengths of the key and message match

#include <stdio.h>
#define len 12 // length of the key and the message in bytes

int main(){
    FILE *keyfile, *pfile, *cfile;
    int i;
    unsigned char ch1, ch2;

    keyfile = fopen("key.txt", "r");
    pfile = fopen("ptext2.txt", "w");
    cfile = fopen("ctext.txt", "r");
    if((keyfile == NULL) ||(pfile == NULL) || (cfile == NULL)){
        printf("File errer!\n");
        return 1;
    }

    for(i = 0; i < len; i++){
        fscanf(keyfile, "%2hhX", &ch1);
        fscanf(cfile, "%2hhX", &ch2);
        fprintf(pfile, "%c", (char)ch1^ch2);
    }

    fclose(keyfile);
    fclose(pfile);
    fclose(cfile);

    return 0;
}