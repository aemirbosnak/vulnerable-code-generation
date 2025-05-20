//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define DEFAULT_START_DIR "."

void analyze_directory(const char *path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat dir_info;
    char full_path[MAX_PATH_LENGTH];
    long total_size = 0;
    
    if ((dir = opendir(path)) == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &dir_info) == -1) {
            perror("Failed to stat file");
            continue;
        }

        // Print the depth-based indentation
        printf("%*s📁 %s", depth * 4, "", entry->d_name);
        
        if (S_ISDIR(dir_info.st_mode)) {
            printf(" [Opened the treasure chest]\n");
            analyze_directory(full_path, depth + 1);
        } else {
            printf(" (Size: %ld bytes)\n", dir_info.st_size);
            total_size += dir_info.st_size;
        }
    }

    closedir(dir);
    
    // Print total size of files in the current directory
    if (depth > 0) {
        printf("%*s🏴‍☠️ Total Treasure Found: %ld bytes\n", (depth - 1) * 4, "", total_size);
    }
}

int main(int argc, char *argv[]) {
    const char *start_dir;

    // Get starting directory from argument or use default
    if (argc > 1) {
        start_dir = argv[1];
    } else {
        start_dir = DEFAULT_START_DIR;
    }

    printf("🗺️ Treasure Finder - Disk Space Analyzer 🗺️\n");
    printf("Starting the adventure in: %s\n", start_dir);
    printf("Let's dive into the wild seas of directories...\n\n");

    analyze_directory(start_dir, 0);

    printf("\n🦜 Adventure Completed! 🦜\n");
    return 0;
}