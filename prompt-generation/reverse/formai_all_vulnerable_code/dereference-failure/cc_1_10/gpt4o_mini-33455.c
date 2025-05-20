//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_EXTENSIONS 10
#define MAX_PATTERNS 50
#define BUFFER_SIZE 1024

// Malware signature patterns
const char *malware_patterns[MAX_PATTERNS] = {
    "malware_signature1",
    "malware_signature2",
    "malware_signature3",
    // Add more patterns as necessary
};

int pattern_count = 3;

// Function to check if a file contains any malware patterns
int contains_malware(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    char buffer[BUFFER_SIZE];
    int found = 0;

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Scan through file line by line
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        for (int i = 0; i < pattern_count; i++) {
            if (strstr(buffer, malware_patterns[i]) != NULL) {
                printf("Malware pattern found in file: %s\n", filepath);
                found = 1;
                break; // Exit loop if found
            }
        }
        if (found) break;
    }

    fclose(file);
    return found;
}

// Function to scan all files in a directory
void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the '.' and '..' entries
        if (entry->d_name[0] == '.') continue;

        char filepath[MAX_PATH];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);

        // Check entry type: if it's a directory, recursively scan it
        if (entry->d_type == DT_DIR) {
            scan_directory(filepath);
        } else {
            // Otherwise, check if it's a file and scan it
            printf("Scanning file: %s\n", filepath);
            if (contains_malware(filepath) == -1) {
                printf("Could not read file: %s\n", filepath);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Start scanning the directory provided by the user
    scan_directory(argv[1]);
    printf("Scanning completed.\n");

    return 0;
}