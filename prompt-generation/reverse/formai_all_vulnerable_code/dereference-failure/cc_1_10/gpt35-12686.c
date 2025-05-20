//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

#define MAX_STRING_SIZE 100 

char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main() 
{ 
    char plain[MAX_STRING_SIZE]; 
    char key[MAX_STRING_SIZE]; 
    char *cipher, *result; 

    printf("Enter plaintext: "); 
    fgets(plain, sizeof(plain), stdin);
    plain[strcspn(plain, "\n")] = 0; 

    printf("Enter key: "); 
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; 

    cipher = encrypt(plain, key); 
    printf("Cipher text: %s\n", cipher); 

    result = decrypt(cipher, key); 
    printf("Decrypted text: %s\n", result); 

    free(cipher); 
    free(result); 

    return 0; 
} 

char *encrypt(char *plaintext, char *key) 
{ 
    time_t t; 
    srand((unsigned) time(&t)); 
    int len = strlen(plaintext); 
    char *ciphertext = malloc(sizeof(char) * (len + 1)); 
    strncpy(ciphertext, plaintext, len); 
    ciphertext[len] = '\0'; 
    for(int i = 0; i < len; i++) { 
        ciphertext[i] = (char) (plaintext[i] ^ key[i % strlen(key)] ^ rand() % 256); 
    } 
    return ciphertext; 
} 

char *decrypt(char *ciphertext, char *key) 
{ 
    int len = strlen(ciphertext); 
    char *plaintext = malloc(sizeof(char) * (len + 1)); 
    strncpy(plaintext, ciphertext, len); 
    plaintext[len] = '\0'; 
    for(int i = 0; i < len; i++) { 
        plaintext[i] = (char) (ciphertext[i] ^ key[i % strlen(key)] ^ rand() % 256); 
    } 
    return plaintext; 
}