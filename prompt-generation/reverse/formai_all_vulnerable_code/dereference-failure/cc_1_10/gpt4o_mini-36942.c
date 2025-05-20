//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path, int depth);

void print_spaces(int level) {
    for(int i = 0; i < level; i++) {
        printf("    ");
    }
}

void analyze_directory(const char *dir_path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    if (!(dir = opendir(dir_path))) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        print_spaces(depth);
        printf("%s: ", entry->d_name);
        if (S_ISDIR(file_stat.st_mode)) {
            printf("(Directory)");
            printf(" - size: %ld bytes\n", file_stat.st_size);
            // Recursively analyze the sub-directory
            analyze_directory(full_path, depth + 1);
        } else {
            printf("(File) - size: %ld bytes\n", file_stat.st_size);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    printf("🌟 Welcome to the Disk Space Analyzer! 🌟\n");
    const char *directory_path = argv[1];
    printf("Analyzing directory: %s\n\n", directory_path);
    analyze_directory(directory_path, 0);
    
    printf("\n🎉 Analysis Complete! Happy File Managing! 🎉\n");
    
    return 0;
}