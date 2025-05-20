//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_usage(const char *prog_name) {
    printf("Usage: %s [source_directory] [destination_directory]\n", prog_name);
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    
    if (!src) {
        perror("Error opening source file");
        return;
    }
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (is_directory(src_path)) {
            mkdir(dest_path, 0755);
            sync_directory(src_path, dest_path);
        } else {
            sync_file(src_path, dest_path);
        }
    }

    closedir(dir);
}

void create_directory(const char *dir_path) {
    if (mkdir(dir_path, 0755) == -1) {
        perror("Error creating directory");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    if (!is_directory(src_dir)) {
        fprintf(stderr, "Source path is not a directory: %s\n", src_dir);
        return EXIT_FAILURE;
    }

    if (!is_directory(dest_dir)) {
        create_directory(dest_dir);
    }

    sync_directory(src_dir, dest_dir);
    
    printf("Synchronization complete from %s to %s\n", src_dir, dest_dir);
    return EXIT_SUCCESS;
}