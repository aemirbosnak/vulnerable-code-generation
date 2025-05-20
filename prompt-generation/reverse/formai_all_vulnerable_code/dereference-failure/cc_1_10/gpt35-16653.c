//FormAI DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char* encrypt(char* plaintext, char* password);
char* decrypt(char* ciphertext, char* password);

int main() {
    char plaintext[MAX_SIZE], password[MAX_SIZE], *ciphertext, *decrypted_text;
    
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    
    ciphertext = encrypt(plaintext, password);
    
    printf("Encrypted text: %s\n", ciphertext);
    
    decrypted_text = decrypt(ciphertext, password);
    
    printf("Decrypted text: %s\n", decrypted_text);
    
    free(ciphertext);
    free(decrypted_text);
    
    return 0;
}

char* encrypt(char* plaintext, char* password) {
    char* ciphertext = (char*) malloc(sizeof(char) * (strlen(plaintext) + 1));
    int i, j = 0, n = strlen(password);
    
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + password[j];
        j = (j + 1) % n;
    }
    
    ciphertext[strlen(plaintext)] = '\0';
    
    return ciphertext;
}

char* decrypt(char* ciphertext, char* password) {
    char* decrypted_text = (char*) malloc(sizeof(char) * (strlen(ciphertext) + 1));
    int i, j = 0, n = strlen(password);
    
    for (i = 0; i < strlen(ciphertext); i++) {
        decrypted_text[i] = ciphertext[i] - password[j];
        j = (j + 1) % n;
    }
    
    decrypted_text[strlen(ciphertext)] = '\0';
    
    return decrypted_text;
}