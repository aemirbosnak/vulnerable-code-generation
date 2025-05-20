//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 1024

// Virus signature database
char *sigs[MAX_SIGS];
int num_sigs;

// Load virus signatures from file
void load_sigs(char *filename) {
    FILE *fp;
    char buf[MAX_SIG_LEN];

    // Open signature file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening signature file");
        exit(1);
    }

    // Read signature lines
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        // Trim newline character
        buf[strlen(buf) - 1] = '\0';

        // Allocate memory for signature
        sigs[num_sigs] = malloc(strlen(buf) + 1);
        if (sigs[num_sigs] == NULL) {
            perror("Error allocating memory for signature");
            exit(1);
        }

        // Copy signature to array
        strcpy(sigs[num_sigs], buf);

        // Increment number of signatures
        num_sigs++;
    }

    // Close signature file
    fclose(fp);
}

// Scan file for viruses
int scan_file(char *filename) {
    FILE *fp;
    char buf[MAX_SIG_LEN];
    int i, found;

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read file into buffer
    fread(buf, 1, sizeof(buf), fp);

    // Search for virus signatures
    found = 0;
    for (i = 0; i < num_sigs; i++) {
        if (strstr(buf, sigs[i]) != NULL) {
            found = 1;
            break;
        }
    }

    // Close file
    fclose(fp);

    // Return result
    return found;
}

// Main function
int main(int argc, char **argv) {
    int i, result;

    // Check for arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signature file> <file to scan>\n", argv[0]);
        exit(1);
    }

    // Load virus signatures
    load_sigs(argv[1]);

    // Scan file
    result = scan_file(argv[2]);

    // Print result
    if (result) {
        printf("File %s is infected!\n", argv[2]);
    } else {
        printf("File %s is clean.\n", argv[2]);
    }

    // Free virus signatures
    for (i = 0; i < num_sigs; i++) {
        free(sigs[i]);
    }

    return 0;
}