//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SIG_FILE "virus_signatures.txt"
#define BUFFER_SIZE 4096

// Structure to hold virus signatures
typedef struct {
    char **signatures;
    size_t count;
} VirusSignatures;

// Function to load virus signatures from a file
VirusSignatures load_signatures(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open signature file");
        exit(EXIT_FAILURE);
    }

    VirusSignatures vs;
    vs.signatures = NULL;
    vs.count = 0;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove newline character from the buffer
        buffer[strcspn(buffer, "\n")] = 0;

        // Resize signature array
        vs.signatures = realloc(vs.signatures, (vs.count + 1) * sizeof(char *));
        vs.signatures[vs.count] = strdup(buffer);
        vs.count++;
    }

    fclose(file);
    return vs;
}

// Function to check if a file contains any virus signature
int file_is_infected(const char *file_path, VirusSignatures vs) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < vs.count; i++) {
            if (strstr((const char *)buffer, vs.signatures[i]) != NULL) {
                fclose(file);
                return 1; // Infected
            }
        }
    }

    fclose(file);
    return 0; // Not infected
}

// Function to scan a directory for infected files
void scan_directory(const char *dir_path, VirusSignatures vs) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

            struct stat statbuf;
            if (stat(full_path, &statbuf) == 0) {
                // Check if it's a directory, then scan recursively
                if (S_ISDIR(statbuf.st_mode)) {
                    scan_directory(full_path, vs);
                } else if (S_ISREG(statbuf.st_mode)) {
                    // Check for viruses
                    if (file_is_infected(full_path, vs)) {
                        printf("Warning: Infected file found: %s\n", full_path);
                    }
                }
            }
        }
    }

    closedir(dir);
}

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load virus signatures
    VirusSignatures vs = load_signatures(SIG_FILE);

    // Scan the directory
    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1], vs);

    // Free memory used for signatures
    for (size_t i = 0; i < vs.count; i++) {
        free(vs.signatures[i]);
    }
    free(vs.signatures);

    printf("Scan complete!\n");
    return EXIT_SUCCESS;
}