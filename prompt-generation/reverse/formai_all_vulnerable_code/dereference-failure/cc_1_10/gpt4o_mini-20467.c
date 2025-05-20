//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TGT_DIR "target_directory"

void sync_file(const char *src_path, const char *tgt_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *tgt_file = fopen(tgt_path, "wb");

    if (!src_file || !tgt_file) {
        perror("File opening failed");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, tgt_file);
    }

    fclose(src_file);
    fclose(tgt_file);
}

int file_exists(const char *filename) {
    struct stat buffer;   
    return (stat(filename, &buffer) == 0);
}

void sync_directory(const char *src_dir, const char *tgt_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char src_path[1024];
            char tgt_path[1024];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(tgt_path, sizeof(tgt_path), "%s/%s", tgt_dir, entry->d_name);

            // If the target file does not exist or the source file is newer
            if (!file_exists(tgt_path)) {
                printf("Syncing new file: %s -> %s\n", src_path, tgt_path);
                sync_file(src_path, tgt_path);
            } else {
                struct stat src_stat, tgt_stat;
                stat(src_path, &src_stat);
                stat(tgt_path, &tgt_stat);
                
                if (src_stat.st_mtime > tgt_stat.st_mtime) {
                    printf("Updating file: %s -> %s\n", src_path, tgt_path);
                    sync_file(src_path, tgt_path);
                }
            }
        }
    }

    closedir(dp);
}

void create_target_dir() {
    struct stat st = {0};

    if (stat(TGT_DIR, &st) == -1) {
        mkdir(TGT_DIR, 0700);
        printf("Created target directory: %s\n", TGT_DIR);
    }
}

void display_help() {
    printf("Usage: sync <source_directory>\n");
    printf("Synchronizes files from the source directory to '%s'.\n", TGT_DIR);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    create_target_dir();
    sync_directory(src_directory, TGT_DIR);

    printf("Synchronization completed successfully!\n");
    return EXIT_SUCCESS;
}