//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

void analyze_directory(const char *dir_name, unsigned long *total_size, int level);

void analyze_directory(const char *dir_name, unsigned long *total_size, int level) {
    DIR *dir = opendir(dir_name);
    struct dirent *entry;
    char path[1024];
    struct stat statbuf;

    if (!dir) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip these entries
        }

        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
        
        if (stat(path, &statbuf) == -1) {
            fprintf(stderr, "Error getting stats for %s: %s\n", path, strerror(errno));
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursion into subdirectory
            printf("%*s-> %s:\n", level * 4, "", entry->d_name);
            analyze_directory(path, total_size, level + 1);
        } else {
            // File
            printf("%*s- %s (size: %lu bytes)\n", level * 4, "", entry->d_name, statbuf.st_size);
            *total_size += statbuf.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Program usually accepts one directory argument
    const char *start_directory = (argc > 1) ? argv[1] : ".";
    unsigned long total_size = 0;

    printf("Analyzing directory: %s\n", start_directory);
    analyze_directory(start_directory, &total_size, 0);
    
    printf("\nTotal size of files: %lu bytes\n", total_size);
    return 0;
}