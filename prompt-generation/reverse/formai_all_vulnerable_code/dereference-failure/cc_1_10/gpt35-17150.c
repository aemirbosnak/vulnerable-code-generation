//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 128
#define BUF_SIZE 1024

void print_usage() {
    printf("Usage: file_encryptor <algorithm> <key> <input_file> <output_file>\n");
}

void xor_encrypt(char* input_buf, int input_len, char* key, int key_len, char* output_buf) {
    int i;
    for (i = 0; i < input_len; i++) {
        output_buf[i] = input_buf[i] ^ key[i % key_len];
    }
}

void encrypt_file(char* algorithm, char* key, char* input_file, char* output_file) {
    FILE* input_fp;
    FILE* output_fp;
    int key_len = strlen(key);
    char input_buf[BUF_SIZE];
    char output_buf[BUF_SIZE];
    
    // Open files
    input_fp = fopen(input_file, "rb");
    if (!input_fp) {
        printf("Error opening input file %s\n", input_file);
        exit(1);
    }
    
    output_fp = fopen(output_file, "wb");
    if (!output_fp) {
        printf("Error creating output file %s\n", output_file);
        exit(1);
    }
    
    // Read input file in chunks and encrypt each chunk
    while (!feof(input_fp)) {
        int bytes_read = fread(input_buf, sizeof(char), BUF_SIZE, input_fp);
        xor_encrypt(input_buf, bytes_read, key, key_len, output_buf);
        fwrite(output_buf, sizeof(char), bytes_read, output_fp);
    }
    
    // Close files
    fclose(input_fp);
    fclose(output_fp);
    
    printf("File encrypted using %s algorithm with key %s\n", algorithm, key);
}

int main(int argc, char** argv) {
    if (argc != 5) {
        print_usage();
        return 1;
    }
    
    // Parse command-line arguments
    char* algorithm = argv[1];
    char* key = argv[2];
    char* input_file = argv[3];
    char* output_file = argv[4];
    
    // Ensure key length is valid
    int key_len = strlen(key);
    if (key_len > MAX_KEY_LEN) {
        printf("Key length exceeds maximum length of %d\n", MAX_KEY_LEN);
        return 1;
    }
    
    // Encrypt file
    encrypt_file(algorithm, key, input_file, output_file);
    
    return 0;
}