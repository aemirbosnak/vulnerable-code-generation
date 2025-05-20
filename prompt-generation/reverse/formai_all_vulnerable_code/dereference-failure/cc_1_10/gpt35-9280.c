//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define KEY_SIZE 256

char* encrypt(char* plainText, char* key);
char* decrypt(char* cipherText, char* key);

int main(){
    char plainText[KEY_SIZE], key[KEY_SIZE], *cipherText, *decryptedText;

    printf("Enter the plain text: ");
    fgets(plainText, KEY_SIZE, stdin);

    printf("Enter the key: ");
    fgets(key, KEY_SIZE, stdin);

    cipherText = encrypt(plainText, key);
    printf("Encrypted text: %s", cipherText);

    decryptedText = decrypt(cipherText, key);
    printf("Decrypted text: %s", decryptedText);

    free(cipherText);
    free(decryptedText);

    return 0;
}

char* encrypt(char* plainText, char* key){
    int length = strlen(plainText);
    char* cipherText = (char*) malloc(length * sizeof(char));
    int keyLength = strlen(key);

    if(keyLength > length){
        keyLength = length;
    }

    int i, j;
    for(i = 0; i < length; i++){
        cipherText[i] = plainText[i] + key[i%keyLength];
    }

    cipherText[length] = '\0';
    return cipherText;
}

char* decrypt(char* cipherText, char* key){
    int length = strlen(cipherText);
    char* decryptedText = (char*) malloc(length * sizeof(char));
    int keyLength = strlen(key);

    if(keyLength > length){
        keyLength = length;
    }

    int i, j;
    for(i = 0; i < length; i++){
        decryptedText[i] = cipherText[i] - key[i%keyLength];
    }

    decryptedText[length] = '\0';
    return decryptedText;
}