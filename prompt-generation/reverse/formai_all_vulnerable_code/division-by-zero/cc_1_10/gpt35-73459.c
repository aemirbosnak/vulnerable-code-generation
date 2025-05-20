//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 256

void encrypt(char* filename, char* key) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Find the file's size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the file into memory
    char* buffer = (char*)malloc(file_size);
    fread(buffer, file_size, 1, file);

    fclose(file);

    // Encrypt the file using the key
    int key_length = 0;
    while (key[key_length] != '\0') {
        key_length++;
    }

    for (int i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ key[i % key_length]; // XOR encryption with repeating key
    }

    // Write the encrypted data back to the file
    file = fopen(filename, "w");
    fwrite(buffer, file_size, 1, file);
    fclose(file);

    free(buffer);

    printf("File %s encrypted with key %s\n", filename, key);
}

int main() {
    // Get the filename and key from the user
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(filename, key);

    return 0;
}