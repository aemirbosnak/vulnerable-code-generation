//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Global variables
long long total_size = 0; // Total size of all files in bytes
long long num_files = 0; // Number of files
long long num_dirs = 0; // Number of directories

// Recursive function to traverse directory tree
void analyze_dir(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // Ignore current and parent directories
            continue;
        }

        char full_path[1024];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            exit(1);
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Directory
            num_dirs++;
            analyze_dir(full_path);
        } else if (S_ISREG(statbuf.st_mode)) {
            // Regular file
            num_files++;
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *path = argv[1];

    analyze_dir(path);

    printf("Directory: %s\n", path);
    printf("Total size: %lld bytes\n", total_size);
    printf("Number of files: %lld\n", num_files);
    printf("Number of directories: %lld\n", num_dirs);

    return 0;
}