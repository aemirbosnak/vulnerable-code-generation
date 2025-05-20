//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define MALWARE_SIGNATURE "malware_signature" // Replace with actual malware signatures
#define MAX_PATH 1024

typedef struct {
    char *file_path;
    int infected;
} ScanResult;

void scan_file(const char *file_path, ScanResult *result) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Could not read file");
        result->infected = 0;
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    result->infected = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (memmem(buffer, bytesRead, MALWARE_SIGNATURE, strlen(MALWARE_SIGNATURE)) != NULL) {
            result->infected = 1;
            break;
        }
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    struct stat file_stat;

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directories
        }

        char file_full_path[MAX_PATH];
        snprintf(file_full_path, MAX_PATH, "%s/%s", dir_path, entry->d_name);

        if (stat(file_full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                scan_directory(file_full_path); // Recursive call for directories
            }
            else if (S_ISREG(file_stat.st_mode)) {
                ScanResult result;
                result.file_path = file_full_path;
                scan_file(file_full_path, &result);

                if (result.infected) {
                    printf("Infected file found: %s\n", result.file_path);
                }
            }
        } else {
            perror("Could not get file status");
        }
    }

    closedir(dir);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <directory-path>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    scan_directory(directory_path);
    return EXIT_SUCCESS;
}