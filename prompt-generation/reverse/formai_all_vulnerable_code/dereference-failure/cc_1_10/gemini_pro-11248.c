//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the encryption key
#define ENCRYPTION_KEY "my_secret_key"

// Structure to hold the file encryption data
typedef struct {
    FILE *input_file;
    FILE *output_file;
    char *buffer;
    size_t buffer_size;
} file_encryption_data;

// Function to encrypt a block of data
void *encrypt_block(void *args) {
    // Cast the arguments to the appropriate type
    file_encryption_data *data = (file_encryption_data *)args;

    // Read a block of data from the input file
    size_t bytes_read = fread(data->buffer, 1, data->buffer_size, data->input_file);

    // If there is no more data to read, return
    if (bytes_read == 0) {
        return NULL;
    }

    // Encrypt the data
    for (size_t i = 0; i < bytes_read; i++) {
        data->buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Write the encrypted data to the output file
    fwrite(data->buffer, 1, bytes_read, data->output_file);

    // Free the allocated memory
    free(data->buffer);
    free(data);

    return NULL;
}

// Function to encrypt a file
void encrypt_file(const char *input_file_path, const char *output_file_path) {
    // Open the input file
    FILE *input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open the output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    // Determine the file size
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);

    // Allocate a buffer for the data
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        return;
    }

    // Create a thread pool
    pthread_t thread_pool[4];

    // Divide the file into blocks
    size_t block_size = file_size / 4;

    // Create the file encryption data structures
    file_encryption_data data[4];
    for (int i = 0; i < 4; i++) {
        data[i].input_file = input_file;
        data[i].output_file = output_file;
        data[i].buffer = buffer + (i * block_size);
        data[i].buffer_size = block_size;
    }

    // Create the threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&thread_pool[i], NULL, encrypt_block, &data[i]);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Free the allocated memory
    free(buffer);
}

// Function to decrypt a block of data
void *decrypt_block(void *args) {
    // Cast the arguments to the appropriate type
    file_encryption_data *data = (file_encryption_data *)args;

    // Read a block of data from the input file
    size_t bytes_read = fread(data->buffer, 1, data->buffer_size, data->input_file);

    // If there is no more data to read, return
    if (bytes_read == 0) {
        return NULL;
    }

    // Decrypt the data
    for (size_t i = 0; i < bytes_read; i++) {
        data->buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Write the decrypted data to the output file
    fwrite(data->buffer, 1, bytes_read, data->output_file);

    // Free the allocated memory
    free(data->buffer);
    free(data);

    return NULL;
}

// Function to decrypt a file
void decrypt_file(const char *input_file_path, const char *output_file_path) {
    // Open the input file
    FILE *input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open the output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    // Determine the file size
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);

    // Allocate a buffer for the data
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        return;
    }

    // Create a thread pool
    pthread_t thread_pool[4];

    // Divide the file into blocks
    size_t block_size = file_size / 4;

    // Create the file encryption data structures
    file_encryption_data data[4];
    for (int i = 0; i < 4; i++) {
        data[i].input_file = input_file;
        data[i].output_file = output_file;
        data[i].buffer = buffer + (i * block_size);
        data[i].buffer_size = block_size;
    }

    // Create the threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&thread_pool[i], NULL, decrypt_block, &data[i]);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Free the allocated memory
    free(buffer);
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <operation>\n", argv[0]);
        return 1;
    }

    // Get the operation
    char *operation = argv[3];

    // Encrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(argv[1], argv[2]);
    }
    // Decrypt the file
    else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(argv[1], argv[2]);
    }
    // Invalid operation
    else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}