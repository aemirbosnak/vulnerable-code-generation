//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define SIGNATURE_FILE "signatures.txt"
#define BUFFER_SIZE 4096

// Function prototypes
void scan_directory(const char *dir_name);
int check_for_signature(const char *file_path);
void load_signatures(const char *signature_file, char signatures[][BUFFER_SIZE], int *num_signatures);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}

// Function to scan a directory and its files
void scan_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    char file_path[MAX_PATH];
    
    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            // Skip navigation directories
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
                scan_directory(file_path); // Recursive call for subdirectory
            }
        } else {
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            if (check_for_signature(file_path)) {
                printf("Virus detected: %s\n", file_path);
            } else {
                printf("Safe: %s\n", file_path);
            }
        }
    }

    closedir(dp);
}

// Function to check a file against loaded signatures
int check_for_signature(const char *file_path) {
    char signatures[100][BUFFER_SIZE];
    int num_signatures = 0;
    load_signatures(SIGNATURE_FILE, signatures, &num_signatures);

    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Could not open file for reading");
        return 0; // Assume safe on read error
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // Safe
}

// Function to load virus signatures from a file
void load_signatures(const char *signature_file, char signatures[][BUFFER_SIZE], int *num_signatures) {
    FILE *file = fopen(signature_file, "r");
    if (!file) {
        fprintf(stderr, "Could not open signature file: %s\n", signature_file);
        return;
    }

    while (fgets(signatures[*num_signatures], BUFFER_SIZE, file) != NULL) {
        strtok(signatures[*num_signatures], "\n"); // Remove newline character
        (*num_signatures)++;
    }

    fclose(file);
}