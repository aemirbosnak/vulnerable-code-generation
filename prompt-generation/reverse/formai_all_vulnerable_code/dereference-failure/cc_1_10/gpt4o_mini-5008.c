//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATTERN_LENGTH 256

// A simple structure to hold virus signatures
typedef struct {
    char name[256];
    char pattern[MAX_PATTERN_LENGTH];
} VirusSignature;

// Sample virus signatures
VirusSignature virus_signatures[] = {
    {"ExampleVirus", "THIS_IS_A_VIRUS_SIGNATURE"},
    {"AnotherVirus", "ANOTHER_VIRUS_SIGNATURE"}
};

int signature_count = sizeof(virus_signatures) / sizeof(VirusSignature);

// Function to read the contents of a file into a buffer
int read_file(const char *filepath, char *buffer, size_t buffer_size) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    fread(buffer, sizeof(char), buffer_size, file);
    fclose(file);
    return 0;
}

// Function to check if a file contains a virus signature
int contains_virus_signature(const char *buffer, const char *pattern) {
    return strstr(buffer, pattern) != NULL;
}

// Function to scan a single file for viruses
void scan_file(const char *filepath) {
    char buffer[BUFFER_SIZE] = {0};
    if (read_file(filepath, buffer, BUFFER_SIZE) == -1) return;

    for (int i = 0; i < signature_count; i++) {
        if (contains_virus_signature(buffer, virus_signatures[i].pattern)) {
            printf("Virus detected! Filename: %s, Virus: %s\n", filepath, virus_signatures[i].name);
        }
    }
}

// Function to recursively scan directories
void scan_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);

    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            // Regular file
            char filepath[PATH_MAX];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            scan_file(filepath);
        } else if (entry->d_type == DT_DIR) {
            // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subdirpath[PATH_MAX];
                snprintf(subdirpath, sizeof(subdirpath), "%s/%s", dirpath, entry->d_name);
                scan_directory(subdirpath);
            }
        }
    }
    closedir(dp);
}

// Entry point of the antivirus scanner
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dirpath = argv[1];
    printf("Scanning directory: %s\n", dirpath);
    scan_directory(dirpath);
    printf("Scanning complete.\n");

    return EXIT_SUCCESS;
}