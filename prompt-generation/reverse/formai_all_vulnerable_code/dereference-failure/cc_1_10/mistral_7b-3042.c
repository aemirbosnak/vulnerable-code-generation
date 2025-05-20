//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#define KEY_BIT 0b11010111
#define _IN_BUF_SIZE 100
#define _OUT_BUF_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryption(char* message, int length);
void decryption(char* message, int length);
void print_bitwise(char* message, int length);

int main() {
    char input[_IN_BUF_SIZE];
    char output[_OUT_BUF_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input) - 1;
    if (len >= _IN_BUF_SIZE) {
        printf("Message too long!\n");
        return 1;
    }

    encryption(input, len);
    strcpy(output, input);
    decryption(output, len);

    printf("\nOriginal message: %s\n", input);
    printf("Encrypted message: %s\n", output);

    print_bitwise(input, len);
    print_bitwise(output, len);

    free(input);
    free(output);

    return 0;
}

void encryption(char* message, int length) {
    for (int i = 0; i < length; i++) {
        message[i] = (char)(message[i] ^ KEY_BIT);
    }
}

void decryption(char* message, int length) {
    for (int i = 0; i < length; i++) {
        message[i] = (char)(message[i] ^ KEY_BIT);
    }
}

void print_bitwise(char* message, int length) {
    printf("\nBitwise representation of the %s:\n", message);
    for (int i = 0; i < length; i++) {
        int value = (int)message[i];
        printf("'%c' -> ", message[i]);
        for (int j = 7; j >= 0; j--) {
            printf("%d", (value >> j) & 1);
        }
        printf("\n");
    }
}