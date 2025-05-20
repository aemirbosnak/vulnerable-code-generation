//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Structure to store virus signatures
typedef struct VirusSignature {
    char *name;
    char *signature;
    int signature_length;
} VirusSignature;

// Array of virus signatures
VirusSignature virus_signatures[] = {
    { "Virus A", "0x1234567890abcdef", 16 },
    { "Virus B", "0xabcdef1234567890", 16 },
    { "Virus C", "0x1234567890abcdeffedcba0987654321", 32 }
};

// Number of virus signatures
int num_virus_signatures = sizeof(virus_signatures) / sizeof(VirusSignature);
int scan_file(FILE *fp, VirusSignature *virus_signature);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Read each file in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Open the file
        char *filename = entry->d_name;
        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
            perror("fopen");
            continue;
        }

        // Scan the file for viruses
        int infected = 0;
        for (int i = 0; i < num_virus_signatures; i++) {
            if (scan_file(fp, &virus_signatures[i])) {
                infected = 1;
                break;
            }
        }

        // Close the file
        fclose(fp);

        // Print the results
        if (infected) {
            printf("%s is infected!\n", filename);
        } else {
            printf("%s is clean.\n", filename);
        }
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}

int scan_file(FILE *fp, VirusSignature *virus_signature) {
    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *buffer = malloc(file_size);
    fread(buffer, 1, file_size, fp);

    // Search for the virus signature in the buffer
    char *found = strstr(buffer, virus_signature->signature);
    free(buffer);

    // Return 1 if the virus signature was found, 0 otherwise
    return found != NULL;
}