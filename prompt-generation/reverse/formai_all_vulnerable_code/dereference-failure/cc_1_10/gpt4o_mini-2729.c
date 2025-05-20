//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to read the contents of a file
int read_file(const char *file_path, char *buffer, size_t buffer_size) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }
    size_t bytes_read = fread(buffer, 1, buffer_size - 1, file);
    buffer[bytes_read] = '\0'; // Null-terminate the string
    fclose(file);
    return bytes_read;
}

// Function to check if a substring exists in a file content
int contains_pattern(const char *content, const char *pattern) {
    return strstr(content, pattern) != NULL;
}

// Function to scan a single file for malware signatures
void scan_file(const char *file_path, const char **signatures, int sig_count) {
    char buffer[8192]; // Buffer to store file content
    int bytes_read = read_file(file_path, buffer, sizeof(buffer));
    if (bytes_read < 0) return;

    for (int i = 0; i < sig_count; i++) {
        if (contains_pattern(buffer, signatures[i])) {
            printf("ALERT: %s is infected with signature '%s'\n", file_path, signatures[i]);
            return;
        }
    }
    printf("Safe: %s is clean\n", file_path);
}

// Function to scan a directory recursively
void scan_directory(const char *dir_path, const char **signatures, int sig_count) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }
    struct dirent *entry;
    char path[512];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            struct stat statbuf;
            if (stat(path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    scan_directory(path, signatures, sig_count); // Recursive call
                } else if (S_ISREG(statbuf.st_mode)) {
                    scan_file(path, signatures, sig_count); // Scan file
                }
            }
        }
    }
    closedir(dir);
}

// Main function that drives the antivirus scanner
int main(int argc, char **argv) {
    // Sample malware signatures to search for
    const char *signatures[] = {
        "malware_signature_1",
        "malware_signature_2",
        "virus_pattern_XYZ",
        "trojan_signature_abc",
        "ransomware_key_123"
    };
    int sig_count = sizeof(signatures) / sizeof(signatures[0]);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting antivirus scanner...\n");
    scan_directory(argv[1], signatures, sig_count);
    printf("Scanning complete.\n");

    return EXIT_SUCCESS;
}