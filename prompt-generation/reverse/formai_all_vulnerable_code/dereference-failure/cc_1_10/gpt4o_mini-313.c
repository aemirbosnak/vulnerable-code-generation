//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_SIZE 1048576 // 1 MB
#define SIGNATURE_SIZE 16

const char *virus_signature = "VIRUS_SIGNATURE_16";  // Surprise! This is a dummy virus signature.

void scan_file(const char *file_path);
void scan_directory(const char *directory_path);
int check_for_virus(const char *buffer, size_t size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Surprise! Please provide a directory to scan for viruses.\n");
        return EXIT_FAILURE;
    }

    printf("Starting virus scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed! Stay safe!\n");

    return EXIT_SUCCESS;
}

void scan_directory(const char *directory_path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *directory = opendir(directory_path);

    if (!directory) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);

        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(file_path, &file_stat) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // It's a directory, let's scan it
            printf("Scanning directory: %s\n", file_path);
            scan_directory(file_path);
        } else if (S_ISREG(file_stat.st_mode)) {
            // It's a file, let's scan it
            printf("Scanning file: %s\n", file_path);
            scan_file(file_path);
        }
    }

    closedir(directory);
}

void scan_file(const char *file_path) {
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        close(fd);
        return;
    }

    ssize_t bytes_read = read(fd, buffer, MAX_FILE_SIZE);
    if (bytes_read == -1) {
        perror("Failed to read file");
        free(buffer);
        close(fd);
        return;
    }

    // Check if the file contains a virus signature
    if (check_for_virus(buffer, bytes_read)) {
        printf("Warning! Virus detected in file: %s\n", file_path);
    } else {
        printf("File is clean: %s\n", file_path);
    }

    free(buffer);
    close(fd);
}

int check_for_virus(const char *buffer, size_t size) {
    // Surprise! This checks for a hardcoded virus signature
    if (size < SIGNATURE_SIZE) {
        return 0; // File too small to contain the signature
    }

    for (size_t i = 0; i <= size - SIGNATURE_SIZE; i++) {
        if (memcmp(buffer + i, virus_signature, SIGNATURE_SIZE) == 0) {
            return 1; // Virus signature found
        }
    }

    return 0; // No virus signature found
}