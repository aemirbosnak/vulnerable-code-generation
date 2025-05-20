//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1); // Allocate memory for the reversed string plus null terminator
    int i;

    for (i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1]; // Copy each character from the end to the beginning
    }

    reversed[i] = '\0'; // Add null terminator to the end of the reversed string

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Free the memory allocated for the reversed string
    free(reversed);
}

// Function to encrypt a string using a simple substitution cipher
void encrypt_string(char* str) {
    int len = strlen(str);
    char* encrypted = malloc(len + 1); // Allocate memory for the encrypted string plus null terminator
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            encrypted[i] = 'A' + (str[i] - 'a'); // Encrypt lowercase letters by shifting them up by 13
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            encrypted[i] = 'a' + (str[i] - 'A'); // Encrypt uppercase letters by shifting them down by 13
        } else {
            encrypted[i] = str[i]; // Copy non-letter characters as is
        }
    }

    encrypted[i] = '\0'; // Add null terminator to the end of the encrypted string

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted);

    // Free the memory allocated for the encrypted string
    free(encrypted);
}

int main() {
    char* input_string = "Cyberpunk is not dead, it lives on in our hearts!";

    // Reverse the input string
    reverse_string(input_string);

    // Encrypt the reversed string
    encrypt_string(input_string);

    return 0;
}