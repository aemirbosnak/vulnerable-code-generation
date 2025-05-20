//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ZombieApocalypse2021!"

void encrypt(char *data, int length) {
    int i;
    for (i = 0; i < length; i++) {
        data[i] = data[i] ^ KEY[i % strlen(KEY)];
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename;
    char *data;
    int length, i;

    // Check for correct usage
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the file contents
    file = fopen(argv[1], "rb");
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    data = malloc(length);
    rewind(file);

    // Read the file contents into the buffer
    fread(data, 1, length, file);
    fclose(file);

    // Encrypt the data
    encrypt(data, length);

    // Overwrite the original file with the encrypted data
    file = fopen(argv[1], "wb");
    fwrite(data, 1, length, file);
    fclose(file);

    // Free the allocated memory
    free(data);

    printf("File '%s' has been SHOCKED with our CUSTOM encryption algorithm!\n", argv[1]);

    return 0;
}