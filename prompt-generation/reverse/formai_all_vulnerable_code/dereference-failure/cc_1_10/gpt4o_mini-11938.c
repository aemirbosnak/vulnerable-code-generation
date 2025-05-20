//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void usage() {
    printf("Usage: vignere [encrypt|decrypt] <key> <input>\n");
    printf("Example: vignere encrypt MYKEY \"hello world\"\n");
}

void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void encrypt(const char *key, const char *input, char *output) {
    int keyLength = strlen(key);
    int textLength = strlen(input);
    int j = 0;

    for (int i = 0; i < textLength; i++) {
        if (isalpha(input[i])) {
            char offset = isupper(input[i]) ? 'A' : 'a';
            output[i] = (input[i] - offset + toupper(key[j % keyLength]) - 'A') % 26 + offset;
            j++;
        } else {
            output[i] = input[i];
        }
    }
    output[textLength] = '\0'; // Null terminate the output string
}

void decrypt(const char *key, const char *input, char *output) {
    int keyLength = strlen(key);
    int textLength = strlen(input);
    int j = 0;

    for (int i = 0; i < textLength; i++) {
        if (isalpha(input[i])) {
            char offset = isupper(input[i]) ? 'A' : 'a';
            output[i] = (input[i] - offset - (toupper(key[j % keyLength]) - 'A') + 26) % 26 + offset; // +26 for positive modulo
            j++;
        } else {
            output[i] = input[i];
        }
    }
    output[textLength] = '\0'; // Null terminate the output string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage();
        return 1;
    }

    char *operation = argv[1];
    char *key = argv[2];
    char *input = argv[3];
    char output[MAX_LENGTH];

    // Clean and convert key to uppercase
    to_upper_case(key);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(key, input, output);
        printf("Encrypted: %s\n", output);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(key, input, output);
        printf("Decrypted: %s\n", output);
    } else {
        usage();
        return 1;
    }

    return 0;
}