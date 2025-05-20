//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define SIGNATURE "VIRUS_SIGNATURE" // Example virus signature

// Function to check if a file contains the virus signature
int contains_signature(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 0; // Cannot read file
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, SIGNATURE) != NULL) {
            fclose(file);
            return 1; // Found the virus signature
        }
    }
    fclose(file);
    return 0; // Signature not found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the . and .. directories
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            
            struct stat statbuf;
            if (stat(file_path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    // It's a directory, scan it recursively
                    scan_directory(file_path);
                } else if (S_ISREG(statbuf.st_mode)) {
                    // It's a regular file, check for virus signature
                    if (contains_signature(file_path)) {
                        printf("ALERT: '%s' contains the virus signature!\n", file_path);
                    }
                }
            } else {
                perror("Could not retrieve file status");
            }
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_to_scan = argv[1];
    printf("Scanning directory: %s\n", dir_to_scan);

    scan_directory(dir_to_scan);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}