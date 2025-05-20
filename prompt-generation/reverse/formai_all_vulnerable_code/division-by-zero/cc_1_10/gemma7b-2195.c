//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encrypt_file(char *filename) {
    FILE *fp;
    char *buffer;
    int file_size, i, key, offset;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer
    buffer = malloc(file_size);

    // Read the file into the buffer
    fread(buffer, file_size, 1, fp);

    // Close the file
    fclose(fp);

    // Generate the key
    key = rand() % 1000;

    // Calculate the offset
    offset = (key * file_size) % file_size;

    // Encrypt the file
    for (i = 0; i < file_size; i++) {
        buffer[i] ^= (offset + i) % file_size;
    }

    // Write the encrypted file to disk
    fp = fopen(filename, "w");
    fwrite(buffer, file_size, 1, fp);
    fclose(fp);

    // Free the memory
    free(buffer);
}

int main() {
    encrypt_file("my_file.txt");
    return 0;
}