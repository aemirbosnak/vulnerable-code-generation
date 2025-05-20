//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 10

// Structure to hold virus signatures.
typedef struct {
    char name[50];
    char signature[100];
} VirusSignature;

// List of known virus signatures
VirusSignature virus_signatures[MAX_SIGNATURES] = {
    {"EICAR", "X5O!P%PGDp0EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"}, 
    {"RedLining", "Generic:Redline"},
    {"Pirate", "This program cannot be modified to run any other commands!"}
};

// Function to check if a file contains a known virus signature.
int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char buffer[1024];
    size_t bytes_read;
    int found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i].signature) != NULL) {
                printf("Virus found in file: %s (Virus: %s)\n", file_path, virus_signatures[i].name);
                found = 1;
                break;
            }
        }
        
        if (found) break;
    }

    fclose(file);
    return found;
}

// Recursive function to scan directories for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            struct stat path_stat;
            stat(full_path, &path_stat);
            
            if (S_ISDIR(path_stat.st_mode)) {
                // Call recursively if the entry is a directory
                scan_directory(full_path);
            } else {
                // Scan the file for viruses
                scan_file(full_path);
            }
        }
    }
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}