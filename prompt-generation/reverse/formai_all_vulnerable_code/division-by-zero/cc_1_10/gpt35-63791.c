//FormAI DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void encryptFile(char *filename, char *key) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char buffer[MAX_BUFFER_SIZE];
    int key_size = strlen(key);

    int block_size = MAX_BUFFER_SIZE;
    if (file_size < MAX_BUFFER_SIZE) {
        block_size = file_size;
    }

    int number_of_blocks = file_size / block_size + ((file_size % block_size != 0) ? 1 : 0);
    int last_block_size = file_size % block_size;

    for (int i = 0; i < number_of_blocks; i++) {
        if (i == number_of_blocks - 1 && last_block_size != 0) {
            block_size = last_block_size;
        }

        fseek(file, i * MAX_BUFFER_SIZE, SEEK_SET);
        fread(buffer, block_size, 1, file);

        for (int j = 0; j < block_size; j++) {
            buffer[j] ^= key[j % key_size];
        }

        fseek(file, i * MAX_BUFFER_SIZE, SEEK_SET);
        fwrite(buffer, block_size, 1, file);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_BUFFER_SIZE];

    printf("Enter the filename to encrypt: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("Enter the encryption key: ");
    fgets(key, MAX_BUFFER_SIZE, stdin);
    key[strcspn(key, "\n")] = 0;

    encryptFile(filename, key);

    printf("File encrypted successfully\n");
    return 0;
}