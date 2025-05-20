//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds-style error handling
#define HANDLE_ERROR(msg)                                     \
    do {                                                        \
        fprintf(stderr, "%s: %s\n", __func__, msg);             \
        exit(EXIT_FAILURE);                                     \
    } while (0)

// Custom error codes
enum {
    ERR_INVALID_ARGUMENTS = 1,
    ERR_MALLOC_FAILED,
    ERR_FOPEN_FAILED,
    ERR_FREAD_FAILED,
    ERR_FCLOSE_FAILED,
};

// Maximum signature size
#define MAX_SIGNATURE_SIZE 1024

// Maximum number of signatures
#define MAX_SIGNATURES 100

// Signature database
struct signature {
    char *name;
    char *signature;
    unsigned int size;
};

struct signature signatures[MAX_SIGNATURES];

// Number of signatures in the database
unsigned int num_signatures = 0;

// Load the signature database from a file
int load_signatures(const char *filename)
{
    FILE *fp;
    char line[MAX_SIGNATURE_SIZE];
    char *name, *signature;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        HANDLE_ERROR("fopen failed");
    }

    // Read the signatures
    while (fgets(line, MAX_SIGNATURE_SIZE, fp) != NULL) {
        // Parse the line
        name = strtok(line, ":");
        signature = strtok(NULL, "\n");
        if (name == NULL || signature == NULL) {
            HANDLE_ERROR("invalid signature format");
        }

        // Allocate memory for the signature
        signatures[num_signatures].name = strdup(name);
        signatures[num_signatures].signature = strdup(signature);
        signatures[num_signatures].size = strlen(signature);

        // Increment the number of signatures
        num_signatures++;
    }

    // Close the file
    if (fclose(fp) != 0) {
        HANDLE_ERROR("fclose failed");
    }

    return 0;
}

// Scan a file for viruses
int scan_file(const char *filename)
{
    FILE *fp;
    unsigned char buffer[MAX_SIGNATURE_SIZE];
    unsigned int i;

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        HANDLE_ERROR("fopen failed");
    }

    // Read the file into the buffer
    if (fread(buffer, 1, MAX_SIGNATURE_SIZE, fp) != MAX_SIGNATURE_SIZE) {
        HANDLE_ERROR("fread failed");
    }

    // Close the file
    if (fclose(fp) != 0) {
        HANDLE_ERROR("fclose failed");
    }

    // Scan the buffer for viruses
    for (i = 0; i < num_signatures; i++) {
        if (memcmp(buffer, signatures[i].signature, signatures[i].size) == 0) {
            printf("Virus found: %s\n", signatures[i].name);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    int i;

    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signature file> <file1> [file2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load the signature database
    if (load_signatures(argv[1]) != 0) {
        exit(EXIT_FAILURE);
    }

    // Scan the files
    for (i = 2; i < argc; i++) {
        if (scan_file(argv[i]) != 0) {
            printf("File %s is infected.\n", argv[i]);
        } else {
            printf("File %s is clean.\n", argv[i]);
        }
    }

    return 0;
}