//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext){
    srand(4);
    int keylen = strlen(key);
    int ptlen = strlen(plaintext);
    int r;
    int i, j;

    for(i = 0; i < ptlen; i++){
        r = rand() % keylen;
        j = i % keylen;
        ciphertext[i] = ((plaintext[i] - 32) + (key[j] - 32) + r) % 95 + 32;
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext){
    srand(4);
    int keylen = strlen(key);
    int ctlen = strlen(ciphertext);
    int r;
    int i, j;

    for(i = 0; i < ctlen; i++){
        r = rand() % keylen;
        j = i % keylen;
        plaintext[i] = ((ciphertext[i] - 32) - (key[j] - 32) - r + 95) % 95 + 32;
    }
    plaintext[i] = '\0';
}

int main(int argc, char *argv[])
{
    if(argc < 4){
        printf("Insufficient arguments.\n");
        return 0;
    }

    char plaintext[1000], key[100], ciphertext[1000];

    strcpy(plaintext, argv[2]);
    strcpy(key, argv[3]);

    if(strcmp(argv[1], "-e") == 0){
        encrypt(plaintext, key, ciphertext);
        printf("Ciphertext: %s\n", ciphertext);
    }
    else if(strcmp(argv[1], "-d") == 0){
        decrypt(argv[2], key, plaintext);
        printf("Plaintext: %s\n", plaintext);
    }
    else{
        printf("Invalid option, use -e to encrypt or -d to decrypt.\n");
    }

    return 0;
}