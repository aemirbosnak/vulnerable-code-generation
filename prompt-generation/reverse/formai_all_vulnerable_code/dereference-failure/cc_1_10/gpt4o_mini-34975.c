//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define SIGNATURE "VIRUS1234"
#define BUFFER_SIZE 1024

// Function to check file for the virus signature
int check_for_virus(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, SIGNATURE) != NULL) {
            fclose(file);
            return 1; // Virus signature found
        }
    }
    
    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    
    if (!(dir = opendir(dir_path))) {
        perror("Could not open directory");
        return;
    }

    printf("Scanning directory: %s\n", dir_path);
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip special directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full path of the file
        char path[BUFFER_SIZE];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        
        // Check if it's a file
        if (entry->d_type == DT_REG) {
            printf("Scanning file: %s\n", path);
            int result = check_for_virus(path);
            if (result == 1) {
                printf("Virus detected in: %s\n", path);
            } else if (result == 0) {
                printf("No virus found in: %s\n", path);
            }
        } else if (entry->d_type == DT_DIR) {
            // Recursively scan subdirectory
            scan_directory(path);
        }
    }
    
    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("🦠 Welcome to the Whimsical Antivirus Scanner! 🦠\n");
    scan_directory(argv[1]);
    printf("🔍 Scan complete! Stay safe! 🔍\n");

    return EXIT_SUCCESS;
}