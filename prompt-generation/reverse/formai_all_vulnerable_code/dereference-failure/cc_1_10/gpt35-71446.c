//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_KEY_SIZE 32

int main(int argc, char *argv[]) {
    // Check if there is a filename and key provided
    if (argc != 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *key = argv[2];

    // Check if the key is longer than the maximum allowed key size
    if (strlen(key) > MAX_KEY_SIZE) {
        printf("Key length is too long, maximum key size is %d\n", MAX_KEY_SIZE);
        return 1;
    }

    // Open the input file for reading
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Open the output file for writing
    char output_filename[strlen(filename) + 5];
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: Could not create output file %s\n", output_filename);
        return 1;
    }

    // Generate the key schedule from the key string
    int key_schedule[MAX_KEY_SIZE];
    for (int i = 0; i < strlen(key); i++) {
        key_schedule[i] = (int) key[i];
    }

    // Read the input file in chunks and apply the encryption algorithm to each chunk
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file))) {
        // Apply the encryption algorithm to the chunk
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ key_schedule[i % strlen(key)];
        }

        // Write the encrypted chunk to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Cleanup
    fclose(input_file);
    fclose(output_file);

    printf("File %s has been encrypted and saved as %s\n", filename, output_filename);

    return 0;
}