//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(const char *input, const char *output, int key);
void decrypt(const char *input, const char *output, int key);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1]; // "encrypt" or "decrypt"
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    int key = atoi(argv[4]);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input_file, output_file, key);
        printf("File encrypted successfully and saved as '%s'.\n", output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input_file, output_file, key);
        printf("File decrypted successfully and saved as '%s'.\n", output_file);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void encrypt(const char *input, const char *output, int key) {
    FILE *in_file = fopen(input, "r");
    FILE *out_file = fopen(output, "w");
    if (!in_file || !out_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, in_file)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = 'A' + (buffer[i] - 'A' + key) % 26;
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = 'a' + (buffer[i] - 'a' + key) % 26;
            }
        }
        fputs(buffer, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

void decrypt(const char *input, const char *output, int key) {
    FILE *in_file = fopen(input, "r");
    FILE *out_file = fopen(output, "w");
    if (!in_file || !out_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, in_file)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = 'A' + (buffer[i] - 'A' - key + 26) % 26;
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = 'a' + (buffer[i] - 'a' - key + 26) % 26;
            }
        }
        fputs(buffer, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <mode> <input_file> <output_file> <key>\n", prog_name);
    printf("Modes:\n");
    printf("  encrypt: Encrypt the input file\n");
    printf("  decrypt: Decrypt the input file\n");
}