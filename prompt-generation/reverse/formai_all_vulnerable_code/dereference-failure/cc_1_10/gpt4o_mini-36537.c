//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void analyze_directory(const char *path, long *total_size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        long total_size = 0;
        
        printf("\nAnalyzing directory: %s\n", argv[i]);
        analyze_directory(argv[i], &total_size);
        
        printf("Total size of '%s': %ld bytes\n", argv[i], total_size);
    }

    return 0;
}

void analyze_directory(const char *path, long *total_size) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        struct stat file_stat;

        if (stat(full_path, &file_stat) < 0) {
            perror("Could not stat file");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // If it's a directory, recursively analyze it
            analyze_directory(full_path, total_size);
        } else {
            // If it's a file, add its size to the total
            *total_size += file_stat.st_size;
        }
    }

    closedir(dir);
}