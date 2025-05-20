//FormAI DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* filename, char* key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if (fp==NULL) {
        printf("File error");
        exit(1);
    }
    char c;
    int i = 0;
    long int keylen = strlen(key);
    while (fread(&c, 1, 1, fp)) {
        c = c ^ key[i%keylen];
        fseek(fp, -1, SEEK_CUR);
        fwrite(&c, 1, 1, fp);
        i++;
    }
    fclose(fp);
    printf("File encryption successful\n");
}


void decrypt(char* filename, char* key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if (fp==NULL) {
        printf("File error");
        exit(1);
    }
    char c;
    int i = 0;
    long int keylen = strlen(key);
    while (fread(&c, 1, 1, fp)) {
        c = c ^ key[i%keylen];
        fseek(fp, -1, SEEK_CUR);
        fwrite(&c, 1, 1, fp);
        i++;
    }
    fclose(fp);
    printf("File decryption successful\n");
}


int main(int argc, char** argv) {
    char* filename = NULL;
    char* key = NULL;
    int encrypt_flag = 0;
    int decrypt_flag = 0;

    for (int i = 1; i < argc; i++) {    
        if (strcmp(argv[i], "-f") == 0) {
            i++;
            filename = argv[i];
        } else if (strcmp(argv[i], "-k") == 0) {
            i++;
            key = argv[i];
        } else if (strcmp(argv[i], "-e") == 0) {
            encrypt_flag = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            decrypt_flag = 1;
        }
    }

    if (filename!=NULL && key!=NULL && (encrypt_flag || decrypt_flag)) {
        if (encrypt_flag) {
            encrypt(filename, key);
        } else {
            decrypt(filename, key);
        }
    } else {
        printf("Usage: file_encryption -f [filename] -k [key] -e/-d\n");
        exit(1);
    }
    
    return 0;
}