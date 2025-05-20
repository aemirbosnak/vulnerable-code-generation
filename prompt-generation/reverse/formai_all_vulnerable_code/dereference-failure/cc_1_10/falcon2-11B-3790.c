//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file, *output_file;
    char file_name[100];
    char encrypted_file_name[100];

    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    strcpy(file_name, argv[1]);
    strcpy(encrypted_file_name, argv[2]);
    strcat(encrypted_file_name, ".enc");

    int bytes_read, bytes_written;
    int encrypted_bytes = 0;
    char buffer[MAX_FILE_SIZE];

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, input_file)) > 0) {
        encrypted_bytes += bytes_read;
        if (encrypted_bytes > MAX_FILE_SIZE) {
            fprintf(stderr, "File is too large to encrypt\n");
            fclose(output_file);
            fclose(input_file);
            return 1;
        }

        memset(buffer, 0, MAX_FILE_SIZE);
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ 0x42; // XOR with a constant value to encrypt
        }

        bytes_written = fwrite(buffer, sizeof(char), bytes_read, output_file);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing encrypted file\n");
            fclose(output_file);
            fclose(input_file);
            return 1;
        }
    }

    fclose(input_file);
    fclose(output_file);
    printf("File encrypted successfully!\n");
    return 0;
}