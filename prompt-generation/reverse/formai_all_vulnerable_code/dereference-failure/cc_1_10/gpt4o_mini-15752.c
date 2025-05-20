//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

// List of known virus signatures (for demonstration purposes)
const char *virus_signatures[] = {
    "virus_signature_1",
    "malware_signature_2",
    "ransomware_signature_3",
    NULL
};

// Function to read a file and check for virus signatures
int scan_file(const char *filepath) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }
    
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (const char **sig = virus_signatures; *sig; sig++) {
            if (strstr(buffer, *sig)) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }
    
    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory
void scan_directory(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];

    dir = opendir(dirname);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            struct stat st;
            if (stat(path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    // Recursively scan subdirectory
                    scan_directory(path);
                } else if (S_ISREG(st.st_mode)) {
                    // Scan file for viruses
                    if (scan_file(path)) {
                        printf("Virus found in: %s\n", path);
                    }
                }
            }
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}