//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024
#define MAX_EXTENSIONS 100

typedef struct {
    char extension[10];
    size_t size;
} ExtensionSize;

void analyze_directory(const char *path, size_t *total_size, ExtensionSize *ext_sizes, int *ext_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char full_path[MAX_PATH];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, total_size, ext_sizes, ext_count); // Recursive call
        } else if (S_ISREG(statbuf.st_mode)) {
            *total_size += statbuf.st_size;

            // Get file extension
            const char *dot = strrchr(entry->d_name, '.');
            if (dot) {
                dot++; // Move past the dot
                for (int i = 0; i < *ext_count; i++) {
                    if (strcmp(ext_sizes[i].extension, dot) == 0) {
                        ext_sizes[i].size += statbuf.st_size;
                        break;
                    }
                }
                // If extension not found, create new entry
                if (*ext_count < MAX_EXTENSIONS) {
                    strcpy(ext_sizes[*ext_count].extension, dot);
                    ext_sizes[*ext_count].size = statbuf.st_size;
                    (*ext_count)++;
                }
            }
        }
    }

    closedir(dir);
}

void print_summary(size_t total_size, ExtensionSize *ext_sizes, int ext_count) {
    printf("Total Disk Space Used: %zu bytes\n", total_size);
    printf("Size by File Extension:\n");
    for (int i = 0; i < ext_count; i++) {
        printf(".%s: %zu bytes\n", ext_sizes[i].extension, ext_sizes[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    size_t total_size = 0;
    ExtensionSize ext_sizes[MAX_EXTENSIONS];
    int ext_count = 0;

    analyze_directory(directory_path, &total_size, ext_sizes, &ext_count);
    print_summary(total_size, ext_sizes, ext_count);

    return EXIT_SUCCESS;
}