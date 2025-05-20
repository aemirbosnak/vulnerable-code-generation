//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to convert a string to uppercase
char* to_upper(char* str) {
    char* result = (char*) malloc(strlen(str) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str); i++) {
        result[i] = toupper(str[i]);
    }
    return result;
}

// Function to reverse a string
char* reverse(char* str) {
    char* result = (char*) malloc(strlen(str) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str); i++) {
        result[i] = str[strlen(str) - 1 - i];
    }
    return result;
}

// Function to encrypt a string
char* encrypt(char* str) {
    char* result = (char*) malloc(strlen(str) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str); i++) {
        result[i] = (char) (str[i] + 3);
    }
    return result;
}

// Function to decrypt a string
char* decrypt(char* str) {
    char* result = (char*) malloc(strlen(str) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str); i++) {
        result[i] = (char) (str[i] - 3);
    }
    return result;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline character
    char* uppercase = to_upper(str);
    char* reversed = reverse(uppercase);
    char* encrypted = encrypt(reversed);
    char* decrypted = decrypt(encrypted);
    printf("Encrypted string: %s\n", encrypted);
    printf("Decrypted string: %s\n", decrypted);
    free(uppercase);
    free(reversed);
    free(encrypted);
    free(decrypted);
    return 0;
}