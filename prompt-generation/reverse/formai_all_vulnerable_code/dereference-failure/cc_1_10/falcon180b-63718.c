//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    reversed[0] = '\0';
    for (int i = 0; i < len; i++) {
        strcat(reversed, str[len - i - 1]);
    }
    strcpy(str, reversed);
    free(reversed);
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to encrypt a string using a Caesar cipher
void caesarEncrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = str[i] + key - 65;
        } else if (islower(str[i])) {
            str[i] = str[i] + key - 97;
        }
    }
}

// Function to decrypt a string using a Caesar cipher
void caesarDecrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = str[i] - key - 65;
        } else if (islower(str[i])) {
            str[i] = str[i] - key - 97;
        }
    }
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverse(input);
    printf("Reversed string: %s\n", input);

    // Count the number of words in the string
    int wordCount = countWords(input);
    printf("Number of words: %d\n", wordCount);

    // Encrypt the string using a Caesar cipher
    int key = 5;
    caesarEncrypt(input, key);
    printf("Encrypted string: %s\n", input);

    // Decrypt the encrypted string
    caesarDecrypt(input, key);
    printf("Decrypted string: %s\n", input);

    return 0;
}