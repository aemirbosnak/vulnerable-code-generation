//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_SIZE 100

char* encrypt(char* string);
char* decrypt(char* string);

int main() {
    srand(time(NULL));
    char string[MAX_STRING_SIZE];
    printf("Enter a phrase to encrypt: ");
    fgets(string, MAX_STRING_SIZE, stdin);
    printf("\nEncrypted phrase: %s\n", encrypt(string));
    return 0;
}

char* encrypt(char* string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    char* encrypted_string = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        int random_num = rand() % 100;
        if (random_num % 2 == 0) {
            encrypted_string[i] = string[i] + random_num;
        } else {
            encrypted_string[i] = string[i] - random_num;
        }
    }
    return encrypted_string;
}

char* decrypt(char* string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    char* decrypted_string = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        int random_num = rand() % 100;
        if (random_num % 2 == 0) {
            decrypted_string[i] = string[i] - random_num;
        } else {
            decrypted_string[i] = string[i] + random_num;
        }
    }
    return decrypted_string;
}