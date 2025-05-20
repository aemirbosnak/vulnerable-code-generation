//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char name[256];
    off_t size;
} file_t;

off_t total_size = 0;
int num_files = 0;

void traverse_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            traverse_directory(full_path);
            continue;
        }

        if (lstat(full_path, &file_stat) == -1) {
            continue;
        }

        file_t file;
        strcpy(file.name, entry->d_name);
        file.size = file_stat.st_size;
        total_size += file.size;
        num_files++;
    }

    closedir(dir);
}

int main() {
    if (chdir("/") != 0) {
        perror("chdir");
        return 1;
    }

    traverse_directory(".");

    printf("Total size of files in root directory: %lld bytes\n", (long long) total_size);
    printf("Number of files: %d\n", num_files);

    return 0;
}