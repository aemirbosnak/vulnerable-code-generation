//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plaintext, int key);
char* decrypt(char* ciphertext, int key);

int main(){
    int key = 3; 
    char plaintext[] = "Hello, World!";
    char* ciphertext = encrypt(plaintext, key);
    char* decryptedtext = decrypt(ciphertext, key);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decryptedtext);

    free(ciphertext);
    free(decryptedtext);

    return 0;
}

char* encrypt(char* plaintext, int key){
    int len = strlen(plaintext);
    char* ciphertext = (char*) malloc(len*sizeof(char));

    for (int i=0; i<len; i++){
        if (plaintext[i] == ' '){
            ciphertext[i] = ' ';
        }
        else{
            ciphertext[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
        }
    }
    return ciphertext;
}

char* decrypt(char* ciphertext, int key){
    int len = strlen(ciphertext);
    char* decryptedtext = (char*) malloc(len*sizeof(char));

    for (int i=0; i<len; i++){
        if (ciphertext[i] == ' '){
            decryptedtext[i] = ' ';
        }
        else{
            decryptedtext[i] = (((ciphertext[i] - 'A') - key + 26) % 26) + 'A';
        }
    }
    return decryptedtext;
}