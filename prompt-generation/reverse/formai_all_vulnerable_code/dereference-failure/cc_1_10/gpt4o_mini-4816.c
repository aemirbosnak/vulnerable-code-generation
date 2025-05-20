//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: file_encryptor <source_file> <target_file> <key>\n");
    printf("This program encrypts the contents of source_file and writes it to target_file using a simple XOR encryption method with the provided key.\n");
}

void encrypt_file(const char* source_filename, const char* target_filename, const char* key) {
    int source_fd, target_fd;
    char buffer[BUFFER_SIZE];
    size_t key_length = strlen(key);
    size_t bytes_read, i;

    // Open the source file for reading
    source_fd = open(source_filename, O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Create the target file for writing
    target_fd = open(target_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (target_fd < 0) {
        perror("Error opening target file");
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    // Read from source file and encrypt
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length];  // Simple XOR encryption
        }

        // Write the encrypted buffer to the target file
        if (write(target_fd, buffer, bytes_read) < 0) {
            perror("Error writing to target file");
            close(source_fd);
            close(target_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Close files
    close(source_fd);
    close(target_fd);
}

void decrypt_file(const char* source_filename, const char* target_filename, const char* key) {
    // Decrypting is essentially the same as encrypting in XOR encryption
    encrypt_file(source_filename, target_filename, key);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    const char* source_file = argv[1];
    const char* target_file = argv[2];
    const char* key = argv[3];

    encrypt_file(source_file, target_file, key);
    
    printf("Encryption complete: '%s' has been encrypted to '%s'.\n", source_file, target_file);
    
    // Optionally, you can decrypt the file back to another target file
    // decrypt_file(target_file, "decrypted_output.txt", key); 
    // printf("Decryption complete: '%s' has been decrypted to 'decrypted_output.txt'.\n", target_file);

    return EXIT_SUCCESS;
}