//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000  // maximum file size for encryption

// Encrypt function to encrypt the source file into destination file using XOR encryption
void encrypt_file(FILE* src, FILE* dst, char* key)
{
    int i = 0, byte;
    size_t key_len = strlen(key);

    // Read source file byte by byte and XOR with the key to encrypt
    while ((byte = fgetc(src)) != EOF) {
        fputc(byte ^ key[i % key_len], dst);
        ++i;
    }
}

int main(int argc, char *argv[])
{
    FILE* src_file, *dst_file;
    char* key;
    size_t key_len;
    
    if (argc < 4) {
        printf("Usage: %s <src_file> <dst_file> <key>\n", argv[0]);
        return 1;
    }

    src_file = fopen(argv[1], "rb");
    if (src_file == NULL) {
        printf("Error: Unable to open %s\n", argv[1]);
        return 1;
    }

    dst_file = fopen(argv[2], "wb");
    if (dst_file == NULL) {
        printf("Error: Unable to open %s\n", argv[2]);
        fclose(src_file);
        return 1;
    }

    key = argv[3];
    key_len = strlen(key);
    if (key_len == 0) {
        printf("Error: Key cannot be empty\n");
        fclose(src_file);
        fclose(dst_file);
        return 1;
    }

    if (key_len > MAX_FILE_SIZE) {
        printf("Error: Key size is too large\n");
        fclose(src_file);
        fclose(dst_file);
        return 1;
    }

    // Encrypt the file using the supplied key
    encrypt_file(src_file, dst_file, key);

    printf("Encryption successful. Encrypted file saved as %s\n", argv[2]);
    
    fclose(src_file);
    fclose(dst_file);

    return 0;
}