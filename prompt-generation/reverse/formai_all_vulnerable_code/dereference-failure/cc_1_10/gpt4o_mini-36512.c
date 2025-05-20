//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_NAME 256

void print_usage(const char *prog_name) {
    printf("Disk Usage Analyzer (DUA) - Retro Style\n");
    printf("Usage: %s <directory>\n", prog_name);
    printf("Analyzes the specified directory and prints disk usage for files and subdirectories.\n");
}

void analyze_directory(const char *path, int level) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char fullpath[MAX_PATH];
    
    if ((dir = opendir(path)) == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if (stat(fullpath, &statbuf) == -1) {
            perror("Could not read stats");
            continue;
        }

        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        if (S_ISDIR(statbuf.st_mode)) {
            printf("[DIR ] %s (Size: %ld bytes)\n", entry->d_name, (long)statbuf.st_size);
            analyze_directory(fullpath, level + 1);
        } else {
            printf("[FILE] %s (Size: %ld bytes)\n", entry->d_name, (long)statbuf.st_size);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    struct stat initial_stat;
    if (stat(argv[1], &initial_stat) == -1) {
        perror("Could not access the specified path");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(initial_stat.st_mode)) {
        printf("The specified path is not a directory.\n");
        return EXIT_FAILURE;
    }

    printf("Analyzing directory: %s\n", argv[1]);
    analyze_directory(argv[1], 0);
    printf("Analysis completed!\n");

    return EXIT_SUCCESS;
}