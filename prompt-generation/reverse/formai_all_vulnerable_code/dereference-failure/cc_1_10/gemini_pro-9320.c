//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

unsigned char key[KEY_LENGTH] = {0};

void generate_key(char *password) {
    int i, j;

    for (i = 0; i < KEY_LENGTH; i++) {
        for (j = 0; j < strlen(password); j++) {
            key[i] ^= password[j];
        }
    }
}

void encrypt_file(char *input_file, char *output_file) {
    FILE *in, *out;
    unsigned char buffer[1024];
    int bytes_read;
    int i;

    in = fopen(input_file, "rb");
    if (in == NULL) {
        perror("fopen");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % KEY_LENGTH];
        }

        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt_file(char *input_file, char *output_file) {
    FILE *in, *out;
    unsigned char buffer[1024];
    int bytes_read;
    int i;

    in = fopen(input_file, "rb");
    if (in == NULL) {
        perror("fopen");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % KEY_LENGTH];
        }

        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <password> <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    generate_key(argv[1]);

    if (strcmp(argv[2], "encrypt") == 0) {
        encrypt_file(argv[3], argv[4]);
    } else if (strcmp(argv[2], "decrypt") == 0) {
        decrypt_file(argv[3], argv[4]);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[2]);
        exit(1);
    }

    return 0;
}