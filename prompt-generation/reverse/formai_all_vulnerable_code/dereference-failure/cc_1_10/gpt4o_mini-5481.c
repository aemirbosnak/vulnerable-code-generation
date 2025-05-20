//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_size(double size) {
    const char *sizes[] = { "B", "KB", "MB", "GB", "TB" };
    int index = 0;
    
    while (size >= 1024 && index < 4) {
        size /= 1024;
        index++;
    }
    
    printf("%.2f %s\n", size, sizes[index]);
}

void analyze_directory(const char *dir_path, double *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    char path[MAX_PATH];
    DIR *directory = opendir(dir_path);

    if (directory == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (stat(path, &file_stat) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(path, total_size);
        } else if (S_ISREG(file_stat.st_mode)) {
            *total_size += file_stat.st_size;
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double total_size = 0;
    
    analyze_directory(argv[1], &total_size);

    printf("Total disk space used: ");
    print_size(total_size);

    return EXIT_SUCCESS;
}