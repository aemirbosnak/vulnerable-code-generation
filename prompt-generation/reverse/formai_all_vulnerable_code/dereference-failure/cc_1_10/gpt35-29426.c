//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plaintext, char* key);
char* decrypt(char* ciphertext, char* key);

int main() {
    char plaintext[] = "Hello, world! This is a test message.";
    char key[] = "mysecretpassword";
    char* ciphertext;
    char* decrypted;

    ciphertext = encrypt(plaintext, key);
    printf("Encrypted message: %s\n", ciphertext);

    decrypted = decrypt(ciphertext, key);
    printf("Decrypted message: %s\n", decrypted);

    free(ciphertext);
    free(decrypted);

    return 0;
}

char* encrypt(char* plaintext, char* key) {
    int i, j;
    int len_plaintext = strlen(plaintext);
    int len_key = strlen(key);
    char* ciphertext = malloc(len_plaintext + 1);

    for(i=0, j=0; i<len_plaintext; i++, j=(j+1)%len_key) {
        ciphertext[i] = plaintext[i] ^ key[j];
    }
    ciphertext[i] = '\0';

    return ciphertext;
}

char* decrypt(char* ciphertext, char* key) {
    int i, j;
    int len_ciphertext = strlen(ciphertext);
    int len_key = strlen(key);
    char* plaintext = malloc(len_ciphertext + 1);

    for(i=0, j=0; i<len_ciphertext; i++, j=(j+1)%len_key) {
        plaintext[i] = ciphertext[i] ^ key[j];
    }
    plaintext[i] = '\0';

    return plaintext;
}