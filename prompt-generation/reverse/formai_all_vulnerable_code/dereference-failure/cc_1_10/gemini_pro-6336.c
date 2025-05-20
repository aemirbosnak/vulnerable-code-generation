//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ENCRYPT 1
#define DECRYPT 0

// Function to encrypt or decrypt a file
int file_crypt(const char *filename, int mode) {
    FILE *fp;
    char ch;
    int key;
    
    // Open the file
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    // Generate a random key
    srand(time(NULL));
    key = rand() % 256;
    
    // Encrypt or decrypt the file
    while ((ch = fgetc(fp)) != EOF) {
        if (mode == ENCRYPT) {
            ch ^= key;
        } else if (mode == DECRYPT) {
            ch ^= key;
        }
        fputc(ch, fp);
    }
    
    // Close the file
    fclose(fp);
    
    return EXIT_SUCCESS;
}

// Function to print usage information
void usage(const char *program_name) {
    printf("Usage: %s [options] filename\n", program_name);
    printf("Options:\n");
    printf("  -e  Encrypt the file\n");
    printf("  -d  Decrypt the file\n");
    printf("  -h  Print this usage information\n");
}

// Main function
int main(int argc, char *argv[]) {
    int mode = -1;
    char *filename;
    
    // Parse command-line arguments
    if (argc < 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            mode = ENCRYPT;
        } else if (strcmp(argv[i], "-d") == 0) {
            mode = DECRYPT;
        } else if (strcmp(argv[i], "-h") == 0) {
            usage(argv[0]);
            return EXIT_SUCCESS;
        } else {
            filename = argv[i];
        }
    }
    
    // Check if a valid mode was specified
    if (mode == -1) {
        printf("Error: No mode specified\n");
        usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    // Encrypt or decrypt the file
    if (file_crypt(filename, mode) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}