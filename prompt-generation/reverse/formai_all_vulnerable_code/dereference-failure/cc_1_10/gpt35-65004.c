//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_dir(const char *path, int depth, long *total_size);
void print_spaces(int depth);
long get_size(const char *path);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long total_size = 0;
    analyze_dir(argv[1], 0, &total_size);
    printf("\nTotal size of directory %s: %ld bytes\n", argv[1], total_size);

    return EXIT_SUCCESS;
}

void analyze_dir(const char *path, int depth, long *total_size) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory %s!\n", path);
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {

            print_spaces(depth);
            printf("%s/\n", entry->d_name);
            analyze_dir(full_path, depth + 1, total_size);

        } else if (entry->d_type == DT_REG) {

            long size = get_size(full_path);
            total_size += size;
            print_spaces(depth);
            printf("%s (%ld bytes)\n", entry->d_name, size);

        }
    }

    closedir(dir);
}

void print_spaces(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
}

long get_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        fprintf(stderr, "Failed to get file stats for %s!\n", path);
        exit(EXIT_FAILURE);
    }

    return st.st_size;
}