//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000 // Maximum length of string to be encrypted/decrypted
 
char* encrypt(char* plaintext, int key);
char* decrypt(char* ciphertext, int key);

int main() {
    char plaintext[MAX_LENGTH], ciphertext[MAX_LENGTH];
    int key;
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    fflush(stdin); // Clear any leftovers in stdin buffer
    strcpy(ciphertext, encrypt(plaintext, key));
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decrypt(ciphertext, key));
    return 0;
}

char* encrypt(char* plaintext, int key) {
    int i;
    char* ciphertext = (char*)malloc(MAX_LENGTH * sizeof(char));
    for(i = 0; i < strlen(plaintext); i++) {
        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (char)(((int)plaintext[i] + key - 65) % 26 + 65);
        } else if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (char)(((int)plaintext[i] + key - 97) % 26 + 97);
        } else {
            ciphertext[i] = (char)((int)plaintext[i]);
        }
    }
    ciphertext[i] = '\0'; // Terminate string
    return ciphertext;
}

char* decrypt(char* ciphertext, int key) {
    int i;
    char* plaintext = (char*)malloc(MAX_LENGTH * sizeof(char));
    for(i = 0; i < strlen(ciphertext); i++) {
        if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (char)(((int)ciphertext[i] - key - 65 + 26) % 26 + 65);
        } else if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') { 
            plaintext[i] = (char)(((int)ciphertext[i] - key - 97 + 26) % 26 + 97);
        } else {
            plaintext[i] = (char)((int)ciphertext[i]);
        }
    }
    plaintext[i] = '\0'; // Terminate string
    return plaintext;
}