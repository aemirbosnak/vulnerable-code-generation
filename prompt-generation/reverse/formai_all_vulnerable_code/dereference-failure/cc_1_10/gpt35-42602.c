//FormAI DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define keyLength 16 // length of the encryption key
#define maxInputLength 1000 // maximum length of user input

char generateRandomChar() {
    char randomChar = rand() % 127;
    while (!isprint(randomChar)) {
        randomChar = rand() % 127;
    }
    return randomChar;
}

char * generateRandomKey() {
    srand(time(NULL));
    char * key = malloc(keyLength + 1); // add 1 for null terminator
    for(int i = 0; i < keyLength; i++) {
        key[i] = generateRandomChar();
    }
    key[keyLength] = '\0'; // add null terminator
    return key;
}

char * encrypt(char * plainText, char * key) {
    int length = strlen(plainText);
    char * cipherText = malloc(length + 1); // add 1 for null terminator
    for (int i = 0; i < length; i++) {
        cipherText[i] = plainText[i] ^ key[i % keyLength];
    }
    cipherText[length] = '\0'; // add null terminator
    return cipherText;
}


int main() {
    char input[maxInputLength];
    char * key = generateRandomKey();

    printf("Enter your message:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    char * cipherText = encrypt(input, key);

    printf("Your encrypted message:\n");
    for (int i = 0; i < strlen(cipherText); i++) {
        printf("%02X ", cipherText[i]); // print as hex
    }
    printf("\n");
    return 0;
}