//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_DEPTH 10
#define MAX_FILE_NAME_LENGTH 1024
#define MAX_PATH_LENGTH (1024 + MAX_FILE_NAME_LENGTH)

void search_directory(const char *path, const char *extension, int depth);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory_path> <file_extension>\n", argv[0]);
        return 1;
    }

    const char *dir_path = argv[1];
    const char *extension = argv[2];

    search_directory(dir_path, extension, 0);
    return 0;
}

void search_directory(const char *path, const char *extension, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        if (depth > MAX_DEPTH) {
            printf("Max depth reached. Skipping directory: %s\n", path);
            closedir(dir);
            return;
        }

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            search_directory(full_path, extension, depth + 1);
            continue;
        }

        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
        if (lstat(full_path, &file_stat) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            char *file_extension = strrchr(entry->d_name, '.');
            if (file_extension != NULL && strcmp(file_extension, extension) == 0) {
                printf("Found file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}