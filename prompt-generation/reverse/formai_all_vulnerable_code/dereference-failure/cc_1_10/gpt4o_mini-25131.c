//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform XOR encryption
void xor_encrypt(char *data, char *key, size_t data_len, size_t key_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] = data[i] ^ key[i % key_len];
    }
}

// Function to read data from a file
char *read_file(const char *filename, size_t *data_len) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening input file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *data_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = (char *)malloc(*data_len);
    if (!data) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(data, 1, *data_len, file);
    fclose(file);
    return data;
}

// Function to write data to a file
int write_file(const char *filename, char *data, size_t data_len) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening output file");
        return -1;
    }

    fwrite(data, 1, data_len, file);
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <encryption_key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    char *key = argv[3];

    size_t data_len;
    char *data = read_file(input_file, &data_len);
    if (!data) {
        return EXIT_FAILURE;
    }

    size_t key_len = strlen(key);
    xor_encrypt(data, key, data_len, key_len);

    if (write_file(output_file, data, data_len) != 0) {
        free(data);
        return EXIT_FAILURE;
    }

    printf("Data encrypted successfully!\n");
    free(data);
    return EXIT_SUCCESS;
}