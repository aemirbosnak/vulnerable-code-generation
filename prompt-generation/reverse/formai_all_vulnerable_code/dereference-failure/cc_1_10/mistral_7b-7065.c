//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 256

void encrypt_file(const char* input_file, const char* output_file, int key) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    char plaintext[KEY_LENGTH];
    char ciphertext[KEY_LENGTH];

    while (fgets(plaintext, KEY_LENGTH, input) != NULL) {
        for (int i = 0; plaintext[i] != '\0'; ++i) {
            if (isalpha(plaintext[i])) {
                if (isupper(plaintext[i])) {
                    ciphertext[i] = (char)(((int)plaintext[i] + key - 65) % 26 + 65);
                } else {
                    ciphertext[i] = (char)(((int)plaintext[i] + key - 97) % 26 + 97);
                }
            } else {
                ciphertext[i] = plaintext[i];
            }
        }

        fputs(ciphertext, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int key = atoi(argv[3]);

    encrypt_file(argv[1], argv[2], key);

    return EXIT_SUCCESS;
}