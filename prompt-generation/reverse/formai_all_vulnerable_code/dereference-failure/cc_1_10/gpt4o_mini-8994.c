//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_VIRUS_SIG 256
#define MAX_FILE_SIZE 4096

// Function to check for virus signatures in a file
int contains_virus_signature(const char *file_content) {
    const char *virus_signatures[] = {
        "VIRUS1_SIGNATURE",
        "VIRUS2_SIGNATURE",
        "MALWARE_SIGNATURE",
        NULL
    };

    for (int i = 0; virus_signatures[i] != NULL; i++) {
        if (strstr(file_content, virus_signatures[i]) != NULL) {
            return 1; // Virus signature found
        }
    }
    return 0; // No virus signature found
}

// Function to scan a file for viruses
void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char file_content[MAX_FILE_SIZE];
    fread(file_content, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    if (contains_virus_signature(file_content)) {
        printf("Warning: Virus found in file: %s\n", file_path);
    } else {
        printf("File is clean: %s\n", file_path);
    }
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            scan_file(file_path);
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory to scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}