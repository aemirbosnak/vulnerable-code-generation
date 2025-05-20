//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 256

typedef struct {
    char key[MAX_LENGTH];
    char iv[MAX_LENGTH];
} EncryptionKey;

EncryptionKey generateKey(char *key, char *iv) {
    EncryptionKey result;
    strcpy(result.key, key);
    strcpy(result.iv, iv);
    return result;
}

int encrypt(char *plaintext, char *key, char *iv, char *ciphertext) {
    int len = strlen(plaintext);
    char *pt = malloc(len + 1);
    strcpy(pt, plaintext);
    char *ct = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        int index = pt[i] + (int)key[i % MAX_LENGTH];
        if (index >= 256) {
            index -= 256;
        }
        ct[i] = index;
    }
    ct[len] = '\0';
    free(pt);
    return 0;
}

int main() {
    char plaintext[MAX_LENGTH];
    char key[MAX_LENGTH];
    char iv[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    
    printf("Enter key: ");
    fgets(key, MAX_LENGTH, stdin);
    
    printf("Enter initialization vector (IV): ");
    fgets(iv, MAX_LENGTH, stdin);
    
    EncryptionKey key_obj = generateKey(key, iv);
    encrypt(plaintext, key_obj.key, key_obj.iv, ciphertext);
    
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}