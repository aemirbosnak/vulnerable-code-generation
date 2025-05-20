//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 5
#define BUFFER_SIZE 1024

const char *virus_signatures[MAX_SIGNATURES] = {
    "malware_example_sig1",
    "malware_example_sig2",
    "malware_example_sig3",
    "malware_example_sig4",
    "malware_example_sig5"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (memmem(buffer, bytes_read, virus_signatures[i], strlen(virus_signatures[i])) != NULL) {
                printf("Virus signature '%s' found in: %s\n", virus_signatures[i], file_path);
                fclose(file);
                return;
            }
        }
    }
    fclose(file);
}

void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // regular file
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            scan_file(file_path);
        } else if (entry->d_type == DT_DIR && (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)) {
            char sub_directory[MAX_PATH];
            snprintf(sub_directory, sizeof(sub_directory), "%s/%s", directory, entry->d_name);
            scan_directory(sub_directory);  // Recursive scan
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];

    printf("Starting antivirus scan on directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}