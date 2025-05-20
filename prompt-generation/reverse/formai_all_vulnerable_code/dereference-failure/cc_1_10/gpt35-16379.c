//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 65536

void encrypt_file(char* filename, char* key) {
    FILE* in_file = fopen(filename, "rb");
    if (!in_file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    size_t filename_length = strlen(filename);
    char out_filename[MAX_FILENAME_LENGTH];
    strncpy(out_filename, filename, filename_length - 4);
    strcat(out_filename, "_enc.bin");

    FILE* out_file = fopen(out_filename, "wb");
    if (!out_file) {
        printf("Could not create encrypted file %s\n", out_filename);
        fclose(in_file);
        return;
    }

    unsigned char buffer[MAX_BUFFER_SIZE];
    int key_length = strlen(key);
    int key_index = 0;
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, in_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[key_index++];
            if (key_index >= key_length) {
                key_index = 0;
            }
        }
        fwrite(buffer, 1, bytes_read, out_file);
    }

    fclose(in_file);
    fclose(out_file);

    printf("File %s encrypted to %s with key %s.\n", filename, out_filename, key);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* key = argv[2];

    encrypt_file(filename, key);

    return 0;
}