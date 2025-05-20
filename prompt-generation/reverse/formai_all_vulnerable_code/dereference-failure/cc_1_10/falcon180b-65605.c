//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1024

// Function to encrypt the given text using the given key
void encrypt(char* text, char* key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char* encrypted_text = (char*)malloc(text_length + 1);
    int j = 0;
    for(int i=0; i<text_length; i++) {
        char c = tolower(text[i]);
        if(isalpha(c)) {
            int k = 0;
            if(isupper(c)) {
                k = 'A' - 'a';
            }
            int index = (c - 'a' + k) % 26 + 'a';
            encrypted_text[j++] = index;
        }
        else {
            encrypted_text[j++] = c;
        }
    }
    encrypted_text[j] = '\0';
    printf("Encrypted text: %s\n", encrypted_text);
}

// Function to decrypt the given encrypted text using the given key
void decrypt(char* encrypted_text, char* key) {
    int encrypted_text_length = strlen(encrypted_text);
    int key_length = strlen(key);
    char* decrypted_text = (char*)malloc(encrypted_text_length + 1);
    int j = 0;
    for(int i=0; i<encrypted_text_length; i++) {
        char c = encrypted_text[i];
        if(isalpha(c)) {
            int k = 0;
            if(isupper(c)) {
                k = 'A' - 'a';
            }
            int index = (c - 'a' + k) % 26 + 'a';
            char d = (index - 'a' + k) % 26 + 'a';
            decrypted_text[j++] = d;
        }
        else {
            decrypted_text[j++] = c;
        }
    }
    decrypted_text[j] = '\0';
    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char* text = "The quick brown fox jumps over the lazy dog.";
    char* key = "secret";
    encrypt(text, key);
    decrypt(text, key);
    return 0;
}