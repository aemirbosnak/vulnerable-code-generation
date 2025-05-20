//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define KEY_LENGTH 32

void encrypt(char *input, char *output, char *key);
void decrypt(char *input, char *output, char *key);
void generate_key(char *key, int key_length);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *key = argv[2];
    char *input_file_name = argv[3];
    char output_file_name[MAX_LENGTH];

    if (strcmp(operation, "encrypt") == 0) {
        snprintf(output_file_name, MAX_LENGTH, "%s.enc", input_file_name);
    } else if (strcmp(operation, "decrypt") == 0) {
        snprintf(output_file_name, MAX_LENGTH, "%s.dec", input_file_name);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, input_file) != NULL) {
        if (strcmp(operation, "encrypt") == 0) {
            char encrypted[MAX_LENGTH];
            encrypt(buffer, encrypted, key);
            fputs(encrypted, output_file);
        } else {
            char decrypted[MAX_LENGTH];
            decrypt(buffer, decrypted, key);
            fputs(decrypted, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
    printf("Operation %s completed successfully!\n", operation);
    return EXIT_SUCCESS;
}

void encrypt(char *input, char *output, char *key) {
    int key_length = strlen(key);
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[i] = '\0'; // Null terminate the output string
}

void decrypt(char *input, char *output, char *key) {
    int key_length = strlen(key);
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[i] = '\0'; // Null terminate the output string
}

void print_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <key> <input_file>\n", program_name);
    printf("Examples:\n");
    printf("  To encrypt: %s encrypt mysecretkey input.txt\n", program_name);
    printf("  To decrypt: %s decrypt mysecretkey input.txt.enc\n", program_name);
}