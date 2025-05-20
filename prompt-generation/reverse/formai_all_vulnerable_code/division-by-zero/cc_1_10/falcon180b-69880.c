//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 64
#define MAX_INPUT_LEN 1024

int main() {
    char key[MAX_KEY_LEN];
    char input[MAX_INPUT_LEN];
    char output[MAX_INPUT_LEN];
    int i, j, n, len;
    int key_len;

    // Get key from user
    printf("Enter key: ");
    if (fgets(key, MAX_KEY_LEN, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return 1;
    }
    key_len = strlen(key);

    // Get input from user
    printf("Enter text: ");
    if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return 1;
    }
    len = strlen(input);

    // Encrypt input using key
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j] = ((input[i] - 'A' + key_len - 1) % key_len) + 'A';
            } else {
                output[j] = ((input[i] - 'a' + key_len - 1) % key_len) + 'a';
            }
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

    // Print encrypted text
    printf("Encrypted text: %s\n", output);

    return 0;
}