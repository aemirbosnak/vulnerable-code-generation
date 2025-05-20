//FormAI DATASET v1.0 Category: modern Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * Encrypts a string using Caesar Cipher algorithm
 * @param text the string to be encrypted
 * @param key the encryption key
 * @return the encrypted string
 */
char* encrypt(char* text, int key) {
    int len = strlen(text);
    char* result = (char*)malloc((len + 1) * sizeof(char)); // allocate memory for result buffer

    for (int i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (char)(((text[i] - 'a') + key) % 26 + 'a'); // apply caesar cipher
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (char)(((text[i] - 'A') + key) % 26 + 'A');
        } else {
            result[i] = text[i]; // keep other characters as is
        }
    }

    result[len] = '\0'; // null-terminate the result
    return result;
}

/**
 * Decrypts a string using Caesar Cipher algorithm
 * @param text the string to be decrypted
 * @param key the decryption key
 * @return the decrypted string
 */
char* decrypt(char* text, int key) {
    int len = strlen(text);
    char* result = (char*)malloc((len + 1) * sizeof(char)); // allocate memory for result buffer

    for (int i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (char)(((text[i] - 'a') - key + 26) % 26 + 'a'); // apply caesar cipher
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (char)(((text[i] - 'A') - key + 26) % 26 + 'A');
        } else {
            result[i] = text[i]; // keep other characters as is
        }
    }

    result[len] = '\0'; // null-terminate the result
    return result;
}

int main(void) {
    char text[MAX_SIZE];
    int key;

    printf("Enter the string to be encrypted: ");
    fgets(text, MAX_SIZE - 1, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    char* encrypted_text = encrypt(text, key);
    printf("Encrypted string: %s\n", encrypted_text);

    char* decrypted_text = decrypt(encrypted_text, key);
    printf("Decrypted string: %s\n", decrypted_text);

    free(encrypted_text); // free the memory allocated by encrypt()
    free(decrypted_text); // free the memory allocated by decrypt()

    return 0;
}