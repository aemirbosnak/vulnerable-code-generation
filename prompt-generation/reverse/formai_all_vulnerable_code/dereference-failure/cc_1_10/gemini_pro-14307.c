//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cipher key
static const unsigned char key[] = { 0x42, 0x69, 0x6e, 0x61, 0x72, 0x79, 0x20, 0x69,
                                      0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6b, 0x65,
                                      0x79, 0x20, 0x74, 0x6f, 0x20, 0x65, 0x6e, 0x63,
                                      0x72, 0x79, 0x70, 0x74, 0x20, 0x74, 0x68, 0x69,
                                      0x73, 0x20, 0x66, 0x69, 0x6c, 0x65, 0x2e };

// Encrypt a file
int encrypt(char *filename) {
    FILE *fp;
    unsigned char buffer[1024];
    int i;

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file into a buffer
    i = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (i < 0) {
        perror("fread");
        fclose(fp);
        return -1;
    }

    // Encrypt the buffer
    for (i = 0; i < sizeof(buffer); i++) {
        buffer[i] ^= key[i % sizeof(key)];
    }

    // Write the encrypted buffer to a file
    fp = fopen("encrypted.txt", "wb");
    if (fp == NULL) {
        perror("fopen");
        fclose(fp);
        return -1;
    }

    i = fwrite(buffer, sizeof(char), sizeof(buffer), fp);
    if (i < 0) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }

    // Close the files
    fclose(fp);
    fclose(fp);

    return 0;
}

// Decrypt a file
int decrypt(char *filename) {
    FILE *fp;
    unsigned char buffer[1024];
    int i;

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file into a buffer
    i = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (i < 0) {
        perror("fread");
        fclose(fp);
        return -1;
    }

    // Decrypt the buffer
    for (i = 0; i < sizeof(buffer); i++) {
        buffer[i] ^= key[i % sizeof(key)];
    }

    // Write the decrypted buffer to a file
    fp = fopen("decrypted.txt", "wb");
    if (fp == NULL) {
        perror("fopen");
        fclose(fp);
        return -1;
    }

    i = fwrite(buffer, sizeof(char), sizeof(buffer), fp);
    if (i < 0) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }

    // Close the files
    fclose(fp);
    fclose(fp);

    return 0;
}

// Usage: encryptor [encrypt|decrypt] filename
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: encryptor [encrypt|decrypt] filename\n");
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        return encrypt(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        return decrypt(argv[2]);
    } else {
        printf("Invalid command\n");
        return 1;
    }
}