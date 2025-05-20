//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// A "byte" is a unit of data that is typically 8 bits wide.
typedef unsigned char byte;

// A "file" is a collection of bytes that is stored on a storage device.
typedef struct {
    FILE *fp;
    char *name;
} file;

// Open a file for reading.
file open_file(char *name) {
    file f;
    f.fp = fopen(name, "rb");
    f.name = name;
    return f;
}

// Close a file.
void close_file(file f) {
    fclose(f.fp);
}

// Read a byte from a file.
byte read_byte(file f) {
    byte b;
    fread(&b, 1, 1, f.fp);
    return b;
}

// Write a byte to a file.
void write_byte(file f, byte b) {
    fwrite(&b, 1, 1, f.fp);
}

// Copy a file.
void copy_file(file src, file dst) {
    byte b;
    while ((b = read_byte(src)) != EOF) {
        write_byte(dst, b);
    }
}

// Encrypt a file.
void encrypt_file(file src, file dst, byte key) {
    byte b;
    while ((b = read_byte(src)) != EOF) {
        write_byte(dst, b ^ key);
    }
}

// Decrypt a file.
void decrypt_file(file src, file dst, byte key) {
    byte b;
    while ((b = read_byte(src)) != EOF) {
        write_byte(dst, b ^ key);
    }
}

// Main function.
int main(int argc, char *argv[]) {
    // Check the command line arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s source destination operation\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the source file.
    file src = open_file(argv[1]);
    if (src.fp == NULL) {
        fprintf(stderr, "Could not open source file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Open the destination file.
    file dst = open_file(argv[2]);
    if (dst.fp == NULL) {
        fprintf(stderr, "Could not open destination file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Perform the operation.
    if (strcmp(argv[3], "copy") == 0) {
        copy_file(src, dst);
    } else if (strcmp(argv[3], "encrypt") == 0) {
        encrypt_file(src, dst, 0x42);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decrypt_file(src, dst, 0x42);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    // Close the files.
    close_file(src);
    close_file(dst);

    return EXIT_SUCCESS;
}