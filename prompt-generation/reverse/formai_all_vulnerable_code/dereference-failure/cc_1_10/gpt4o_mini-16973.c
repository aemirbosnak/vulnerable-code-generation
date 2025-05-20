//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#define SIGNATURE_SIZE 8
#define MAX_PATH 1024

// List of known virus signatures
const char* virus_signatures[] = {
    "MALWARE01",
    "VIRUS02",
    "TROJAN03",
    "WORM04",
    "RANSOM05",
    NULL
};

// Function to scan a file for viruses
int scan_file(const char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    char buffer[SIGNATURE_SIZE];
    while (fread(buffer, 1, SIGNATURE_SIZE, file) == SIGNATURE_SIZE) {
        // Check if the buffer matches any of the virus signatures
        for (int i = 0; virus_signatures[i] != NULL; i++) {
            if (memcmp(buffer, virus_signatures[i], SIGNATURE_SIZE) == 0) {
                fclose(file);
                return 1; // Virus found
            }
        }
        fseek(file, 1, SEEK_SET); // Move one byte forward and continue scanning
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory
void scan_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    struct dirent* entry;

    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') { // Skip hidden files and directories
            continue;
        }
        
        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", dir_path, entry->d_name);
        
        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("Error stating file");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively scan directories
            scan_directory(full_path);
        } else {
            // Scan the file
            printf("Scanning file: %s\n", full_path);
            int result = scan_file(full_path);
            if (result == 1) {
                printf("Virus detected in file: %s\n", full_path);
            } else if (result == -1) {
                printf("Error scanning file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* directory_to_scan = argv[1];

    printf("Starting scan on directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}