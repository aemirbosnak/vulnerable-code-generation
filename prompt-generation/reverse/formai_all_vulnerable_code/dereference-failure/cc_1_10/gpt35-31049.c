//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: expert-level
/*
 * This program implements a unique cryptographic hash function, using SHA256 algorithm,
 * that takes an input file path and calculates its hash value. The resulting hash is returned 
 * as a hexadecimal string.
 *
 * Author: [Your Name]
 * Date created: [Current Date]
 * Last modified: [Current Date]
 *
 * Usage: ./unique_hash input_file_path
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_BUFFER_SIZE  1024    // Maximum buffer size for reading input file

/**
 * Calculates hash value of given input file using SHA256 algorithm.
 *
 * @param input_file_path   Path of input file whose hash value needs to be calculated
 *
 * @return                  Character array containing hexadecimal hash value of input file
 */
char* calculate_hash(char* input_file_path) {
    FILE* input_file = fopen(input_file_path, "rb");    // Open input file in binary read mode
    if (input_file == NULL) {
        printf("Error: Unable to open input file\n");
        exit(EXIT_FAILURE);
    }

    // Initialize SHA256 context structure
    SHA256_CTX sha256_context;
    SHA256_Init(&sha256_context);

    // Calculate hash value of input file
    unsigned char* buffer = malloc(MAX_BUFFER_SIZE);   // Allocate buffer for reading input file
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0) {
        SHA256_Update(&sha256_context, buffer, bytes_read);    // Update SHA256 context with buffer data
    }
    free(buffer);
    unsigned char hash[SHA256_DIGEST_LENGTH];    // Allocate buffer for holding calculated hash value
    SHA256_Final(hash, &sha256_context);    // Finalize SHA256 context and output hash value to buffer

    // Convert binary hash value to hexadecimal string
    char* hash_string = malloc((SHA256_DIGEST_LENGTH * 2) + 1);    // Allocate buffer for holding hexadecimal hash string
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_string[i * 2], "%02x", hash[i]);    // Convert each byte of binary hash to 2-digit hexadecimal string and append to hash string
    }
    hash_string[SHA256_DIGEST_LENGTH * 2] = '\0';    // Append null terminator to end of hash string

    fclose(input_file);    // Close input file
    return hash_string;
}
 
int main(int argc , char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* input_file_path = argv[1];
    char* hash = calculate_hash(input_file_path);
    printf("Hash value of input file '%s': %s\n", input_file_path, hash);
    free(hash);    // Free dynamically allocated memory for hash value buffer
    return 0;
}