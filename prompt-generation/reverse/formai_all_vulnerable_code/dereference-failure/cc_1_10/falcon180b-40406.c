//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the given string using a key
void encrypt(char* str, char* key) {
    int len = strlen(str);
    char* encrypted_str = (char*) malloc(len + 1);
    int key_index = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key[key_index]) % 26 + 'a';
            key_index = (key_index + 1) % strlen(key);
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key[key_index]) % 26 + 'A';
            key_index = (key_index + 1) % strlen(key);
        }
        encrypted_str[i] = ch;
    }
    encrypted_str[len] = '\0';
    printf("Encrypted string: %s\n", encrypted_str);
}

// Function to decrypt the given string using a key
void decrypt(char* str, char* key) {
    int len = strlen(str);
    char* decrypted_str = (char*) malloc(len + 1);
    int key_index = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key[key_index] + 26) % 26 + 'a';
            key_index = (key_index + 1) % strlen(key);
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - key[key_index] + 26) % 26 + 'A';
            key_index = (key_index + 1) % strlen(key);
        }
        decrypted_str[i] = ch;
    }
    decrypted_str[len] = '\0';
    printf("Decrypted string: %s\n", decrypted_str);
}

int main() {
    char* str = "Hello World";
    char* key = "abcdefghijklmnopqrstuvwxyz";
    encrypt(str, key);
    decrypt(str, key);
    return 0;
}