//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_SIZE 1000000

int main() {
    char key[MAX_KEY_LENGTH];
    char filename[100];
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    FILE *input_file, *output_file;
    int key_length, file_size;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open the input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the file size
    fseek(input_file, 0L, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    // Read the file into memory
    fread(input_buffer, 1, file_size, input_file);

    // Encrypt the file
    for (int i = 0; i < file_size; i++) {
        char c = toupper(input_buffer[i]);
        char k = toupper(key[i % key_length]);
        output_buffer[i] = (c + k - 65) % 26 + 65;
    }

    // Write the encrypted file to disk
    output_file = fopen("encrypted_file.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    fwrite(output_buffer, 1, file_size, output_file);
    fclose(output_file);

    // Print the encryption key
    printf("Encryption key: %s\n", key);

    return 0;
}