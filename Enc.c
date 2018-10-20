// read key from key.txt (hex) and message from ptext.txt (ASCII);
// output ciphertext to ctext.txt (hex)

// The user must ensure that the lengths of the key and message match

#include <stdio.h>
#define len 12 // length of the key and the message in bytes

int main(){
    FILE *keyfile, *pfile, *cfile;
    int i;
    unsigned char ch1;
    char ch2;

    keyfile = fopen("key.txt", "r");
    pfile = fopen("ptext.txt", "r");
    cfile = fopen("ctext.txt", "w");
    if((keyfile == NULL) ||(pfile == NULL) || (cfile == NULL)){
        printf("File errer!\n");
        return 1;
    }

    for(i = 0; i < len; i++){
        fscanf(keyfile, "%2hhX", &ch1);
        fscanf(pfile, "%c", &ch2);
        fprintf(cfile, "%02x", ch1^ch2);
    }

    fclose(keyfile);
    fclose(pfile);
    fclose(cfile);

    return 0;
}