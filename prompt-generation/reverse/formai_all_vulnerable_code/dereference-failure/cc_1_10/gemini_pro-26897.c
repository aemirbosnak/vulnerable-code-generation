//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

// XOR encryption/decryption function
void xor_encrypt_decrypt(byte* data, size_t data_len, byte* key, size_t key_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

// Generate a random key of the specified length
byte* generate_key(size_t key_len) {
    byte* key = malloc(key_len);
    for (size_t i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Read a file into a buffer
byte* read_file(char* filename, size_t* file_len) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *file_len = ftell(file);
    rewind(file);

    byte* buffer = malloc(*file_len);
    if (buffer == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, *file_len, file);
    if (bytes_read != *file_len) {
        perror("fread");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

// Write a buffer to a file
int write_file(char* filename, byte* data, size_t data_len) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }

    size_t bytes_written = fwrite(data, 1, data_len, file);
    if (bytes_written != data_len) {
        perror("fwrite");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <key length> <input file> <output file>\n", argv[0]);
        return 1;
    }

    size_t key_len = atoi(argv[1]);
    if (key_len <= 0) {
        printf("Key length must be greater than 0\n");
        return 1;
    }

    byte* key = generate_key(key_len);
    if (key == NULL) {
        perror("generate_key");
        return 1;
    }

    size_t file_len;
    byte* data = read_file(argv[2], &file_len);
    if (data == NULL) {
        perror("read_file");
        free(key);
        return 1;
    }

    xor_encrypt_decrypt(data, file_len, key, key_len);

    if (write_file(argv[3], data, file_len) != 0) {
        perror("write_file");
        free(key);
        free(data);
        return 1;
    }

    printf("File encrypted successfully with key length %zu\n", key_len);
    free(key);
    free(data);
    return 0;
}