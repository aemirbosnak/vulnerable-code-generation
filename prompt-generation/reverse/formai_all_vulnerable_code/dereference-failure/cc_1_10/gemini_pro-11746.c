//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 1024
#define MAX_SIG_LEN 1024

// Signature database
struct signature {
    char *name;
    char *pattern;
    int len;
};

struct signature signatures[MAX_SIGS];
int num_sigs = 0;

// Load signatures from a file
int load_sigs(const char *filename) {
    FILE *fp;
    char line[MAX_SIG_LEN];
    char *name, *pattern;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(line, MAX_SIG_LEN, fp) != NULL) {
        // Parse the line
        name = strtok(line, ":");
        pattern = strtok(NULL, "\n");

        // Add the signature to the database
        signatures[num_sigs].name = strdup(name);
        signatures[num_sigs].pattern = strdup(pattern);
        signatures[num_sigs].len = strlen(pattern);
        num_sigs++;
    }

    fclose(fp);

    return 0;
}

// Scan a file for viruses
int scan_file(const char *filename) {
    FILE *fp;
    char buffer[MAX_SIG_LEN];
    int i, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    while (fread(buffer, 1, MAX_SIG_LEN, fp) != 0) {
        // Scan the buffer for signatures
        for (i = 0; i < num_sigs; i++) {
            for (j = 0; j < MAX_SIG_LEN - signatures[i].len; j++) {
                if (memcmp(buffer + j, signatures[i].pattern, signatures[i].len) == 0) {
                    // Found a virus!
                    fclose(fp);
                    return 1;
                }
            }
        }
    }

    fclose(fp);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    int i;

    // Load the signature database
    if (load_sigs("signatures.txt") != 0) {
        fprintf(stderr, "Error loading signature database\n");
        return 1;
    }

    // Scan the files specified on the command line
    for (i = 1; i < argc; i++) {
        if (scan_file(argv[i]) != 0) {
            printf("File %s is infected\n", argv[i]);
        } else {
            printf("File %s is clean\n", argv[i]);
        }
    }

    return 0;
}