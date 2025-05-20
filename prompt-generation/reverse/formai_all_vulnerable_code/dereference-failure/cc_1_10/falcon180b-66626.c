//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void encrypt(char* text, int key) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[j] = (char)(((int)text[i] + key - 65) % 26 + 65);
            } else {
                result[j] = (char)(((int)text[i] + key - 97) % 26 + 97);
            }
        } else {
            result[j] = text[i];
        }
        j++;
    }
    result[j] = '\0';
    printf("Encrypted text: %s\n", result);
}

void decrypt(char* text, int key) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[j] = (char)(((int)text[i] - key - 65) % 26 + 65);
            } else {
                result[j] = (char)(((int)text[i] - key - 97) % 26 + 97);
            }
        } else {
            result[j] = text[i];
        }
        j++;
    }
    result[j] = '\0';
    printf("Decrypted text: %s\n", result);
}

int main() {
    char* text = "Hello, world!";
    int key = 3;
    encrypt(text, key);
    decrypt(text, key);
    return 0;
}