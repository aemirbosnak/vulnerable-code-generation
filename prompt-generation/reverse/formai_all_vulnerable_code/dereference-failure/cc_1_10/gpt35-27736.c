//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encrypt(char *text, int shift);
char *decrypt(char *text, int shift);

int main() {
    char text[100];
    int shift, choice;

    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a shift value: ");
    scanf("%d", &shift);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Selection: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char *encrypted = encrypt(text, shift);
        printf("Encrypted text: %s\n", encrypted);
        free(encrypted);
    } else if (choice == 2) {
        char *decrypted = decrypt(text, shift);
        printf("Decrypted text: %s\n", decrypted);
        free(decrypted);
    } else {
        printf("Invalid selection.\n");
        return 1;
    }

    return 0;
}

char *encrypt(char *text, int shift) {
    int len = strlen(text);
    char *result = (char *) malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[i] = ((text[i] - 'A') + shift) % 26 + 'A';
            } else {
                result[i] = ((text[i] - 'a') + shift) % 26 + 'a';
            }
        } else {
            result[i] = text[i];
        }
    }

    result[len] = '\0';
    return result;
}

char *decrypt(char *text, int shift) {
    int len = strlen(text);
    char *result = (char *) malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result[i] = ((text[i] - 'A') - shift + 26) % 26 + 'A';
            } else {
                result[i] = ((text[i] - 'a') - shift + 26) % 26 + 'a';
            }
        } else {
            result[i] = text[i];
        }
    }

    result[len] = '\0';
    return result;
}