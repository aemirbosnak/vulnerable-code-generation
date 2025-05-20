//FormAI DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // Define the size of our buffer for reading and writing files

void encryptFile(char* file_path, int key);
void decryptFile(char* file_path, int key);

int main(int argc, char **argv) {
    if(argc < 4) {
        printf("Usage: file_encryption.exe <e/d> <input_file_path> <output_file_path> <key>");
        return EXIT_FAILURE;
    }

    char* mode = argv[1];
    char* input_file_path = argv[2];
    char* output_file_path = argv[3];
    int key = atoi(argv[4]);

    if(mode[0] == 'e') {
        encryptFile(input_file_path, key);
    } else if(mode[0] == 'd') {
        decryptFile(input_file_path, key);
    } else {
        printf("Unsupported mode. Usage: file_encryption.exe <e/d> <input_file_path> <output_file_path> <key>");
        return EXIT_FAILURE;
    }

    printf("File %s successfully %sed and saved as %s.\n", input_file_path, mode, output_file_path);
    return EXIT_SUCCESS;
}

void encryptFile(char* file_path, int key) {
    FILE* input_file = fopen(file_path, "rb");
    if(input_file == NULL) {
        printf("Failed to open input file.\n");
        return;
    }

    char output_file_path[BUFFER_SIZE];
    sprintf(output_file_path, "%s.encrypted", file_path);
    FILE* output_file = fopen(output_file_path, "wb");
    if(output_file == NULL) {
        printf("Failed to create output file.\n");
        fclose(input_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    int read_count = 0;
    while((read_count = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for(int i = 0; i < read_count; i++) {
            buffer[i] = buffer[i] + key; // Simple shift cipher encryption
        }
        fwrite(buffer, 1, read_count, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decryptFile(char* file_path, int key) {
    FILE* input_file = fopen(file_path, "rb");
    if(input_file == NULL) {
        printf("Failed to open input file.\n");
        return;
    }

    char output_file_path[BUFFER_SIZE];
    sprintf(output_file_path, "%s.decrypted", file_path);
    FILE* output_file = fopen(output_file_path, "wb");
    if(output_file == NULL) {
        printf("Failed to create output file.\n");
        fclose(input_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    int read_count = 0;
    while((read_count = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for(int i = 0; i < read_count; i++) {
            buffer[i] = buffer[i] - key; // Simple shift cipher decryption
        }
        fwrite(buffer, 1, read_count, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}