//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path, long long *total_size);

void print_size(long long size) {
    if (size < 1024) {
        printf("%lld B\n", size);
    } else if (size < 1048576) {
        printf("%.2f KB\n", size / 1024.0);
    } else if (size < 1073741824) {
        printf("%.2f MB\n", size / 1048576.0);
    } else {
        printf("%.2f GB\n", size / 1073741824.0);
    }
}

void analyze_directory(const char *dir_path, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char path[MAX_PATH];

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            long long dir_size = 0;
            analyze_directory(path, &dir_size);
            printf("Directory: %s Size: ", path);
            print_size(dir_size);
            *total_size += dir_size; // Add directory size to total
        } else {
            *total_size += statbuf.st_size; // Add file size to total
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    long long total_size = 0;
    char *path = "."; // Default to current directory

    if (argc > 1) {
        path = argv[1]; // Get path from command line argument
    }

    printf("Analyzing disk space of directory: %s\n", path);
    analyze_directory(path, &total_size);
    
    printf("\nTotal Size of Directory \"%s\": ", path);
    print_size(total_size);

    return 0;
}