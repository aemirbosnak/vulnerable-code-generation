//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH 1024
#define INDENT_LEVEL 4

void analyze_directory(const char *path, int indent);
void print_indentation(int level);
void print_file_info(const char *file_path);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat sb;
    
    if (stat(argv[1], &sb) == -1) {
        handle_error("Failed to read directory stats.");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("=== Disk Space Analyzer ===\n");
    analyze_directory(argv[1], 0);
    printf("===========================\n");

    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, int indent) {
    DIR *dir;
    struct dirent *entry;
    char full_path[MAX_PATH];
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        handle_error("Unable to open directory.");
        return;
    }

    // Print the directory being analyzed
    print_indentation(indent);
    printf("[DIR] %s\n", path);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            handle_error("Failed to retrieve file stats.");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(full_path, indent + INDENT_LEVEL);
        } else if (S_ISREG(file_stat.st_mode)) {
            print_file_info(full_path);
        }
    }

    closedir(dir);
}

void print_file_info(const char *file_path) {
    struct stat file_stat;

    if (stat(file_path, &file_stat) == -1) {
        handle_error("Failed to get file information.");
        return;
    }

    printf("File: %s, Size: %ld bytes, Permissions: %o\n", 
           file_path, 
           file_stat.st_size, 
           file_stat.st_mode & 0777);
}

void print_indentation(int level) {
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s - %s\n", message, strerror(errno));
}