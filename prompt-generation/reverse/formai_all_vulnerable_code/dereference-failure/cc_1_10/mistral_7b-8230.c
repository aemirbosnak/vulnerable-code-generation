//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_DEPTH 3
#define BUF_SIZE 1024

typedef struct {
    char name[256];
    off_t size;
} FileInfo;

void traverse_directory(const char *path, int depth, FileInfo files[], int *num_files);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    FileInfo files[1024];
    int num_files = 0;

    traverse_directory(argv[1], 0, files, &num_files);

    printf("-------------------------------------------------\n");
    printf("| Name                 | Size (Bytes) |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_files; ++i) {
        printf("| %-25s | %10ld |\n", files[i].name, files[i].size);
    }

    printf("-------------------------------------------------\n");

    return 0;
}

void traverse_directory(const char *path, int depth, FileInfo files[], int *num_files) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[BUF_SIZE];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (depth > MAX_DEPTH) {
            continue;
        }

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            traverse_directory(full_path, depth + 1, files, num_files);
            continue;
        }

        if (lstat(full_path, &file_stat) == -1) {
            continue;
        }

        if (depth == 0) {
            for (int i = 0; i < *num_files; ++i) {
                if (strcmp(files[i].name, entry->d_name) == 0) {
                    files[i].size += file_stat.st_size;
                    continue;
                }
            }

            for (int i = *num_files; i < 1024; ++i) {
                if (i == *num_files && i < 1023) {
                    strcpy(files[i].name, entry->d_name);
                }
                files[i].size = file_stat.st_size;
                (*num_files)++;

                if (*num_files == 1024) {
                    break;
                }
            }
        }
    }

    closedir(dir);
}