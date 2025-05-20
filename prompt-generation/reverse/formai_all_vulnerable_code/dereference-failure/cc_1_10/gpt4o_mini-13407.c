//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_BUFFER 256
#define SIGNATURE_LEN 256
#define MAX_FILES 1000

// Virus definitions - just for demonstration
const char *virus_signatures[] = {
    "malicious_code_1",
    "malicious_code_2",
    "malicious_code_3"
};

const int num_signatures = sizeof(virus_signatures) / sizeof(virus_signatures[0]);

typedef struct {
    char filename[MAX_BUFFER];
    char filepath[MAX_BUFFER];
    int infected;
} FileScanResult;

void scan_file(const char *filepath, FileScanResult *result) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Unable to open file for scanning");
        return;
    }

    char buffer[SIGNATURE_LEN];
    size_t read_size;
    result->infected = 0;
    strcpy(result->filepath, filepath);
    strncpy(result->filename, strrchr(filepath, '/') + 1, MAX_BUFFER);
    
    while ((read_size = fread(buffer, 1, SIGNATURE_LEN, file)) > 0) {
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                result->infected = 1;
                break;
            }
        }
        if (result->infected) break;
    }
    
    fclose(file);
}

void print_result(FileScanResult *results, int count) {
    for (int i = 0; i < count; i++) {
        if (results[i].infected) {
            printf("Warning: Infected file detected: %s\n", results[i].filepath);
        } else {
            printf("Clean file: %s\n", results[i].filepath);
        }
    }
}

void scan_directory(const char *dir_path, FileScanResult *results, int *count) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_BUFFER];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (stat(full_path, &file_stat) == -1) {
                perror("Unable to get file status");
                continue;
            }
            
            if (S_ISDIR(file_stat.st_mode)) {
                scan_directory(full_path, results, count); // Recursive scan
            } else {
                scan_file(full_path, &results[*count]);
                (*count)++;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileScanResult results[MAX_FILES];
    int file_count = 0;

    scan_directory(argv[1], results, &file_count);
    print_result(results, file_count);
    
    return EXIT_SUCCESS;
}