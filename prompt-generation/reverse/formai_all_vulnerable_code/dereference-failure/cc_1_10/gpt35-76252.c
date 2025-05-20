//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* file_name, char* key) {
    FILE* file_pointer = fopen(file_name, "rb");
    if (file_pointer == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Seek to the end of the file to get its size
    fseek(file_pointer, 0L, SEEK_END);
    long file_size = ftell(file_pointer);

    // Seek back to the beginning of the file
    fseek(file_pointer, 0L, SEEK_SET);

    // Allocate memory for the file contents
    char* file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(file_contents, 1, file_size, file_pointer);

    // Close the file
    fclose(file_pointer);

    // Perform encryption by XORing each character with the key
    int key_length = strlen(key);
    for (int i = 0; i < file_size; i++) {
        file_contents[i] ^= key[i % key_length];
    }

    // Write the encrypted data back to the file
    file_pointer = fopen(file_name, "wb");
    if (file_pointer == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(file_contents, 1, file_size, file_pointer);
    fclose(file_pointer);

    // Free the memory used for the file contents
    free(file_contents);

    printf("Encryption complete!\n");
}

int main() {
    char file_name[100], key[100];

    printf("Welcome to the C File Encryptor! This program will encrypt the contents of a file using a key.\n\n");

    printf("Please enter the name of the file you wish to encrypt: ");
    scanf("%s", file_name);

    printf("Please enter the key you wish to use for encryption: ");
    scanf("%s", key);

    encrypt(file_name, key);

    return 0;
}