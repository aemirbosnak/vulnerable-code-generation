//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *dir_path, long long *total_size, int level) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Print current directory name
    printf("%*s[%s]\n", level * 2, "", dir_path);

    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        
        // Get file statistics
        if (stat(full_path, &statbuf) == 0) {
            // Add to total size for files only
            if (S_ISREG(statbuf.st_mode)) {
                *total_size += statbuf.st_size;
                printf("%*s- %s (File, Size: %lld bytes)\n", level * 2 + 2, "", entry->d_name, statbuf.st_size);
            } else if (S_ISDIR(statbuf.st_mode)) {
                // Recursive call for directories
                analyze_directory(full_path, total_size, level + 1);
            }
        } else {
            perror("stat");
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *start_dir;

    // Determine the starting directory
    if (argc != 2) {
        start_dir = ".";
    } else {
        start_dir = argv[1];
    }

    long long total_size = 0;

    printf("Analyzing directory: %s\n", start_dir);
    analyze_directory(start_dir, &total_size, 0);
    printf("Total size of files in '%s': %lld bytes\n", start_dir, total_size);

    return 0;
}