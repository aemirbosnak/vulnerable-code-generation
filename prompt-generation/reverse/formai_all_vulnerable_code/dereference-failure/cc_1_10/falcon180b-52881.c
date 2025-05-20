//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_KEY_SIZE 16
#define CHUNK_SIZE 16

int main() {
    char file_name[MAX_FILE_NAME];
    char key[MAX_KEY_SIZE];
    int i, j, key_index;
    FILE *input_file, *output_file;
    int file_size;
    char *file_buffer;
    char encrypted_buffer[CHUNK_SIZE];

    // Get file name and key from user
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter key: ");
    scanf("%s", key);

    // Open input file
    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for file buffer
    file_buffer = (char*) malloc(file_size);
    if (file_buffer == NULL) {
        printf("Error: Could not allocate memory for file buffer.\n");
        exit(1);
    }

    // Read input file into buffer
    fread(file_buffer, file_size, 1, input_file);
    fclose(input_file);

    // Encrypt file buffer
    for (i = 0; i < file_size; i += CHUNK_SIZE) {
        key_index = 0;
        for (j = 0; j < CHUNK_SIZE && i + j < file_size; j++) {
            encrypted_buffer[j] = file_buffer[i + j] ^ key[key_index];
            key_index = (key_index + 1) % strlen(key);
        }
        fwrite(encrypted_buffer, CHUNK_SIZE, 1, output_file);
    }

    // Close output file
    fclose(output_file);

    // Free memory
    free(file_buffer);

    return 0;
}