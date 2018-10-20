//Generate random key of length len, and output it to key.txt

#include <stdio.h>
#define len 12 // len is specified in bytes , so the key is 8*len bits long

int main(int argc, char const *argv[])
{
    FILE *randfile, *outfile;
    int i;
    unsigned char next;

    randfile = fopen("/dev/random", "r"); //pool of entropy in Unix-like system
    outfile = fopen("key.txt", "w");
    if((randfile == NULL) || (outfile == NULL)){
        printf("File error!\n");
        return 1;
    }

    for(i = 0; i < len; i++){
        fscanf(randfile, "%c", &next);
        fprintf(outfile, "%02x", next);
    }

    fclose(randfile);
    fclose(outfile);
    return 0;
}
