//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 2048

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}

int is_directory(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISDIR(st.st_mode));
}

void create_directory_if_not_exists(const char *dir) {
    mkdir(dir, 0755);
}

void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");

    if (!src || !dest) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied %s to %s\n", source_file, dest_file);
}

void synchronize_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    create_directory_if_not_exists(dest_dir);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files and . or ..

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (is_directory(src_path)) {
            synchronize_directories(src_path, dest_path); // Recursive call for directories
        } else {
            copy_file(src_path, dest_path); // Copy file
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *source_directory = argv[1];
    char *destination_directory = argv[2];

    if (!is_directory(source_directory)) {
        fprintf(stderr, "Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    synchronize_directories(source_directory, destination_directory);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}