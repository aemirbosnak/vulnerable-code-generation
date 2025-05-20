//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
// This program is a unique C file backup system that creates a protected backup of a file
// It uses the SHA-256 hashing algorithm for data integrity
// It creates a backup file with the same name as the original file, but with an added ".backup" extension

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    rewind(file);

    // Allocate buffer for file data and read file contents
    char *buffer = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    size_t bytes_read;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;

    SHA256_Init(&sha256_ctx);

    // Read and hash file data
    while((bytes_read = fread(buffer, 1, BUFFER_SIZE, file))) {
        SHA256_Update(&sha256_ctx, buffer, bytes_read);
    }
    fclose(file);

    SHA256_Final(hash, &sha256_ctx);

    // Convert hash to string
    char hash_string[2 * SHA256_DIGEST_LENGTH + 1];
    int i;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&(hash_string[i * 2]), "%02x", hash[i]);
    }

    // Create backup filename
    char *backup_filename = (char*) malloc(sizeof(char) * (strlen(filename) + 8));
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".backup");

    // Write backup file
    FILE *backup_file = fopen(backup_filename, "wb");
    if(!backup_file) {
        printf("Error: Could not create backup file.\n");
        return 1;
    }

    // Write hash and file data to backup file
    fwrite(hash_string, 1, strlen(hash_string), backup_file);
    fwrite("\n", 1, 1, backup_file);
    file = fopen(filename, "rb");
    while((bytes_read = fread(buffer, 1, BUFFER_SIZE, file))) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    return 0;
}