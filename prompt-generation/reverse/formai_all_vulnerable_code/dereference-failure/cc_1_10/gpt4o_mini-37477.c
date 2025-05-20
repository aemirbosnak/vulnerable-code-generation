//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_usage() {
    printf("Usage: file_sync <source_directory> <target_directory>\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_files(const char *source, const char *target) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH];
    char target_path[MAX_PATH];

    if ((dir = opendir(source)) == NULL) {
        fprintf(stderr, "Error opening directory %s: %s\n", source, strerror(errno));
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target, entry->d_name);

        if (is_directory(source_path)) {
            mkdir(target_path, 0755);
            sync_files(source_path, target_path);
        } else {
            FILE *src_file = fopen(source_path, "rb");
            if (!src_file) {
                fprintf(stderr, "Error opening file %s: %s\n", source_path, strerror(errno));
                continue;
            }

            FILE *tgt_file = fopen(target_path, "wb");
            if (!tgt_file) {
                fprintf(stderr, "Error creating file %s: %s\n", target_path, strerror(errno));
                fclose(src_file);
                continue;
            }

            char buffer[BUFSIZ];
            size_t n;
            while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, n, tgt_file);
            }

            fclose(src_file);
            fclose(tgt_file);
            printf("Synced: %s to %s\n", source_path, target_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *target_dir = argv[2];

    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source %s is not a directory or does not exist.\n", source_dir);
        return EXIT_FAILURE;
    }

    if (mkdir(target_dir, 0755) && errno != EEXIST) {
        fprintf(stderr, "Error creating target directory %s: %s\n", target_dir, strerror(errno));
        return EXIT_FAILURE;
    }

    sync_files(source_dir, target_dir);
    printf("File synchronization completed from %s to %s.\n", source_dir, target_dir);
    return EXIT_SUCCESS;
}