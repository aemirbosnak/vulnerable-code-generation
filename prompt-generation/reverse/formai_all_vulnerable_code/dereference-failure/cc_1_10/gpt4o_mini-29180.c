//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void encrypt(char *input, char *output, int shift) {
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        output[i] = c;
    }
    output[strlen(input)] = '\0'; // null-terminate the string
}

void decrypt(char *input, char *output, int shift) {
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - shift + 26) % 26 + 'A'; // add 26 to ensure positive
        } else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - shift + 26) % 26 + 'a'; // add 26 to ensure positive
        }
        output[i] = c;
    }
    output[strlen(input)] = '\0'; // null-terminate the string
}

void caesarCipher(char *input, int shift) {
    char *encrypted = (char *)malloc(MAX * sizeof(char));
    char *decrypted = (char *)malloc(MAX * sizeof(char));
    
    if (encrypted == NULL || decrypted == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    encrypt(input, encrypted, shift);
    printf("Encrypted: %s\n", encrypted);

    decrypt(encrypted, decrypted, shift);
    printf("Decrypted: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
}

void getInputAndProcess() {
    char input[MAX];
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Strip newline character

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    shift = shift % 26; // Wrap around shift value

    caesarCipher(input, shift);
}

int main() {
    printf("======== Caesar Cipher ========\n");
    getInputAndProcess();
    printf("======== End of Program ========\n");
    return 0;
}