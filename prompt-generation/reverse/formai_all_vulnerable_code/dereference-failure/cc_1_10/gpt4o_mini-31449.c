//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a file is an executable
int is_executable(const struct stat *file_stat) {
    return (file_stat->st_mode & S_IXUSR) || (file_stat->st_mode & S_IXGRP) || (file_stat->st_mode & S_IXOTH);
}

// Function to simulate virus signature detection
int contains_virus_signature(const char *file_path) {
    const char *virus_signature = "VIRUS123";  // Sample virus signature for demonstration
    FILE *file = fopen(file_path, "rb");
    char buffer[256];
    int found_signature = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", file_path);
        return 0;
    }

    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        if (strstr(buffer, virus_signature) != NULL) {
            found_signature = 1;
            break;
        }
    }

    fclose(file);
    return found_signature;
}

// Function to scan a directory for executables
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    struct stat file_stat;
    
    if (dir == NULL) {
        fprintf(stderr, "Error: Cannot open directory %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode) && is_executable(&file_stat)) {
                    printf("Scanning file: %s\n", full_path);
                    if (contains_virus_signature(full_path)) {
                        printf("Alert! Virus signature found in: %s\n", full_path);
                    } else {
                        printf("No virus signature found in: %s\n", full_path);
                    }
                } else if (S_ISDIR(file_stat.st_mode)) {
                    // Recurse into subdirectory
                    scan_directory(full_path);
                }
            } else {
                fprintf(stderr, "Error: Cannot stat file %s\n", full_path);
            }
        }
    }
    closedir(dir);
}

// Main function to initiate scanning
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan complete.\n");
    
    return EXIT_SUCCESS;
}