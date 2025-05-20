//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char* rand_str(int len) {
    char* str = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
    return str;
}

void encrypt(char* input, int key) {
    int len = strlen(input);
    char* output = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ (key % 26 + 'a');
        key++;
    }
    output[len] = '\0';
    printf("Encrypted message: %s\n", output);
}

void decrypt(char* input, int key) {
    int len = strlen(input);
    char* output = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ (key % 26 + 'a');
        key++;
    }
    output[len] = '\0';
    printf("Decrypted message: %s\n", output);
}

int main() {
    srand(time(NULL));
    int key = rand_int(1, 1000);
    char* message = rand_str(rand_int(10, 50));
    printf("Original message: %s\n", message);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}