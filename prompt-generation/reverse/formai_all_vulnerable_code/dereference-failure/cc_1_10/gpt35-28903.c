//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plaintext, int key) {
    int n = strlen(plaintext);
    char* ciphertext = (char*)malloc((n+1)*sizeof(char));
    for(int i=0; i<n; i++) {
        if(plaintext[i]>='a'&&plaintext[i]<='z') {
            ciphertext[i] = 'a' + (plaintext[i]-'a'+key)%26;
        }
        else if(plaintext[i]>='A'&&plaintext[i]<='Z') {
            ciphertext[i] = 'A' + (plaintext[i]-'A'+key)%26;
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
    return ciphertext;
}

char* decrypt(char* ciphertext, int key) {
    int n = strlen(ciphertext);
    char* plaintext = (char*)malloc((n+1)*sizeof(char));
    for(int i=0; i<n; i++) {
        if(ciphertext[i]>='a'&&ciphertext[i]<='z') {
            plaintext[i] = 'a' + (ciphertext[i]-'a'+26-key)%26;
        }
        else if(ciphertext[i]>='A'&&ciphertext[i]<='Z') {
            plaintext[i] = 'A' + (ciphertext[i]-'A'+26-key)%26;
        }
        else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[n] = '\0';
    return plaintext;
}

int main() {
    char* msg = "This is a secret message!";
    int key = 7;
    char* cipher = encrypt(msg, key);
    printf("Encrypted message: %s\n", cipher);
    char* plain = decrypt(cipher, key);
    printf("Decrypted message: %s\n", plain);
    free(cipher);
    free(plain);
    return 0;
}