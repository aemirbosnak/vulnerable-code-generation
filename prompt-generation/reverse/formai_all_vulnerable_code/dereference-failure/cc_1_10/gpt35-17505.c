//FormAI DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void sync_files(char* source_dir, char* dest_dir, int* file_count) {
    DIR* source = opendir(source_dir);
    DIR* dest = opendir(dest_dir);

    if (!source || !dest) {
        fprintf(stderr, "Error: Cannot open directory\n");
        return;
    }

    struct dirent* source_dirent;
    while ((source_dirent = readdir(source)) != NULL) {
        // Ignore hidden files/directories and parent directories (. and ..)
        if (source_dirent->d_name[0] == '.') {
            continue;
        }

        char source_path[1024];
        char dest_path[1024];
        sprintf(source_path, "%s/%s", source_dir, source_dirent->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, source_dirent->d_name);

        struct stat source_stat;
        if (stat(source_path, &source_stat) == -1) {
            fprintf(stderr, "Error: Cannot get file stats\n");
            continue;
        }

        if (S_ISREG(source_stat.st_mode)) {
            struct stat dest_stat;
            if (stat(dest_path, &dest_stat) == -1) {
                // File doesn't exist in destination directory
                *file_count = *file_count + 1;
                if (unlink(dest_path) == -1) {
                    fprintf(stderr, "Error: Cannot delete file\n");
                    continue;
                }
                if (link(source_path, dest_path) == -1) {
                    fprintf(stderr, "Error: Cannot create link\n");
                    continue;
                }
            } else if (source_stat.st_mtime > dest_stat.st_mtime) {
                // File exists in both directories but is newer in source directory
                *file_count = *file_count + 1;
                if (unlink(dest_path) == -1) {
                    fprintf(stderr, "Error: Cannot delete file\n");
                    continue;
                }
                if (link(source_path, dest_path) == -1) {
                    fprintf(stderr, "Error: Cannot create link\n");
                    continue;
                }
            }
        } else if (S_ISDIR(source_stat.st_mode)) {
            // Recursively sync subdirectories
            sync_files(source_path, dest_path, file_count);
        }
    }

    closedir(source);
    closedir(dest);

}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        return 1;
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    int file_count = 0;
    sync_files(source_dir, dest_dir, &file_count);

    printf("Synced %d files\n", file_count);
    
    return 0;
}