//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024
#define SIGNATURE_LEN 64
#define MAX_SIGNATURES 10

// Function Prototypes
int scan_file(const char *file_path);
void load_signatures(const char *filename, char signatures[][SIGNATURE_LEN], int *signature_count);
void scan_directory(const char *directory);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <signature_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    const char *signature_file = argv[2];

    // Scan the provided directory
    scan_directory(directory);

    return EXIT_SUCCESS;
}

void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char file_path[MAX_PATH_LEN];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            printf("Scanning file: %s\n", file_path);
            if (scan_file(file_path)) {
                printf("Warning: Potential virus detected in file: %s\n", file_path);
            } else {
                printf("File safe: %s\n", file_path);
            }
        } else if (entry->d_type == DT_DIR) { // Check if it's a directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir_path[MAX_PATH_LEN];
                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", directory, entry->d_name);
                scan_directory(sub_dir_path); // Recursively scan subdirectory
            }
        }
    }

    closedir(dir);
}

int scan_file(const char *file_path) {
    char signatures[MAX_SIGNATURES][SIGNATURE_LEN];
    int signature_count = 0;

    // Load virus signatures from a predefined file (in a real application, this could be dynamic)
    load_signatures("signatures.txt", signatures, &signature_count);
    
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Could not open file for scanning");
        return 0; // Assume file is safe if we can't read it
    }

    char buffer[SIGNATURE_LEN];
    while (fread(buffer, 1, SIGNATURE_LEN, file) == SIGNATURE_LEN) {
        for (int i = 0; i < signature_count; ++i) {
            if (memcmp(buffer, signatures[i], SIGNATURE_LEN) == 0) {
                fclose(file);
                return 1; // Virus detected
            }
        }
        fseek(file, 1 - SIGNATURE_LEN, SEEK_CUR); // Slide window for scanning
    }

    fclose(file);
    return 0; // No virus detected
}

void load_signatures(const char *filename, char signatures[][SIGNATURE_LEN], int *signature_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open signature file");
        *signature_count = 0;
        return;
    }

    while (*signature_count < MAX_SIGNATURES && fgets(signatures[*signature_count], SIGNATURE_LEN, file) != NULL) {
        // Remove newline character
        signatures[*signature_count][strcspn(signatures[*signature_count], "\n")] = 0;
        (*signature_count)++;
    }

    fclose(file);
}