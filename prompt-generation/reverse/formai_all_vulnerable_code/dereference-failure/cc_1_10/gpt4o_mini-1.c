//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define a structure to represent a signature
typedef struct {
    char *name;
    char *pattern;
} VirusSignature;

// List of hypothetical virus signatures
VirusSignature signatures[] = {
    {"EvilCode", "ABCD"},
    {"MaliciousTrojan", "1234"},
    {"WormAttack", "XYZ"},
    {"AdwareFlare", "ADAD"},
    {NULL, NULL}
};

// Function to check if a file contains a known virus signature
int check_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1; // File could not be opened
    }

    unsigned char buffer[16];
    size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    for (int i = 0; signatures[i].name != NULL; i++) {
        if (bytesRead >= strlen(signatures[i].pattern) && 
            memcmp(buffer, signatures[i].pattern, strlen(signatures[i].pattern)) == 0) {
            printf("Virus detected in file: '%s' (Signature: %s)\n", filename, signatures[i].name);
            return 1; // Virus found
        }
    }

    return 0; // No virus found
}

// Function to scan a directory recursively
void scan_directory(const char *path) {
    struct dirent *entry;
    struct stat entry_info;
    DIR *dp = opendir(path);
  
    if (!dp) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char fullpath[1024];

        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the entry
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get information about the entry
        if (stat(fullpath, &entry_info) == -1) {
            fprintf(stderr, "Could not stat file: %s\n", fullpath);
            continue;
        }

        // If it's a directory, scan it recursively
        if (S_ISDIR(entry_info.st_mode)) {
            scan_directory(fullpath);
        } 
        // Check if it's a file and scan for viruses
        else if (S_ISREG(entry_info.st_mode)) {
            int result = check_file(fullpath);
            if (result == -1) {
                fprintf(stderr, "Error reading file: %s\n", fullpath);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    // Check if a directory was provided as an argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the provided directory
    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    
    printf("Scan finished.\n");
    return EXIT_SUCCESS;
}