//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *text, char *key, char *output);
void decrypt(char *text, char *key, char *output);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *key = argv[2];
    char *input_text = argv[3];
    char output[MAX_LEN] = {0};

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input_text, key, output);
        printf("Encrypted Text: %s\n", output);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input_text, key, output);
        printf("Decrypted Text: %s\n", output);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void encrypt(char *text, char *key, char *output) {
    size_t text_len = strlen(text);
    size_t key_len = strlen(key);

    for (size_t i = 0; i < text_len; i++) {
        char key_char = key[i % key_len];
        // Simple Caesar cipher-like encryption
        output[i] = (text[i] + key_char) % 256;
    }
    output[text_len] = '\0'; // Null-terminate
}

void decrypt(char *text, char *key, char *output) {
    size_t text_len = strlen(text);
    size_t key_len = strlen(key);

    for (size_t i = 0; i < text_len; i++) {
        char key_char = key[i % key_len];
        // Simple Caesar cipher-like decryption
        output[i] = (text[i] - key_char + 256) % 256; // Ensure non-negative result
    }
    output[text_len] = '\0'; // Null-terminate
}

void print_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <key> <text>\n", program_name);
    printf("Example:\n");
    printf("  %s encrypt mysecretkey \"Hello World\"\n", program_name);
    printf("  %s decrypt mysecretkey \"EncryptedTextHere\"\n", program_name);
}