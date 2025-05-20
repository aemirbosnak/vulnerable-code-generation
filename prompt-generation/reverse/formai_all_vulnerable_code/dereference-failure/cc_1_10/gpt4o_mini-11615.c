//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define SIGNATURE_COUNT 3
#define MAX_FILE_PATH 1024

// Define known virus signatures
const char *virus_signatures[SIGNATURE_COUNT] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "VIRUS-SIGNATURE-1",
    "VIRUS-SIGNATURE-2"
};

// Function to check if a file contains any virus signature
int contains_virus(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 0;
    }
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }
    
    fclose(file);
    return 0; // No virus found
}

// Function to recursively scan a directory for malicious files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat entry_stat;
    DIR *directory = opendir(dir_path);
    
    if (directory == NULL) {
        perror("Could not open directory");
        return;
    }
    
    while ((entry = readdir(directory)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char full_path[MAX_FILE_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        stat(full_path, &entry_stat);

        // If entry is a directory, recurse into it
        if (S_ISDIR(entry_stat.st_mode)) {
            scan_directory(full_path);
        } 
        // If entry is a regular file, check for viruses
        else if (S_ISREG(entry_stat.st_mode)) {
            if (contains_virus(full_path)) {
                printf("Virus found in file: %s\n", full_path);
            }
        }
    }
    
    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *directory_to_scan = argv[1];
    scan_directory(directory_to_scan);
    
    return EXIT_SUCCESS;
}