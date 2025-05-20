//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define SUSPICIOUS_PATTERN "malware_signature"

void scan_file(const char *filename);
void scan_directory(const char *directory_path);
int contains_suspicious_pattern(const char *buffer);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    scan_directory(directory_path);

    return EXIT_SUCCESS;
}

void scan_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *dp = opendir(directory_path);

    if (dp == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip "." and ".."
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Construct the full path for the file
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recurse into directories
            printf("Scanning directory: %s\n", filepath);
            scan_directory(filepath);
        } else if (entry->d_type == DT_REG) {
            // Scan regular files
            printf("Scanning file: %s\n", filepath);
            scan_file(filepath);
        }
    }

    closedir(dp);
}

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen failed");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (contains_suspicious_pattern(buffer)) {
            printf("Suspicious pattern found in file: %s\n", filename);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No issues found in file: %s\n", filename);
    }

    fclose(file);
}

int contains_suspicious_pattern(const char *buffer) {
    // Simple heuristic: check if buffer contains the suspicious pattern
    return strstr(buffer, SUSPICIOUS_PATTERN) != NULL;
}