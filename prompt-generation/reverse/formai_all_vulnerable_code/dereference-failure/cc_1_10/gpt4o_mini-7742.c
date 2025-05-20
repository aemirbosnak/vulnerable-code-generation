//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define FILE_SIGNATURE "badsignature" // Hypothetical malware signature

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        printf("Unable to open file %s: Error\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    // Search the file for the malware signature
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        if (memmem(buffer, bytesRead, FILE_SIGNATURE, strlen(FILE_SIGNATURE))) {
            printf("Malware signature found in file: %s\n", filename);
            fclose(file);
            return;
        }
    }

    fclose(file);
}

void scan_directory(const char *path) {
    DIR *directory = opendir(path);
    struct dirent *entry;

    if (!directory) {
        printf("Unable to open directory %s\n", path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip the '.' and '..' entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char new_path[BUFFER_SIZE];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
                scan_directory(new_path);
            }
        } else if (entry->d_type == DT_REG) {
            char file_path[BUFFER_SIZE];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
            scan_file(file_path);
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat st;
    if (stat(argv[1], &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Error: %s is not a valid directory\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    
    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}