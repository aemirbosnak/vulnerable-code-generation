//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char name[256];
    off_t size;
} File;

typedef struct {
    char name[256];
    off_t size;
    int is_directory;
} Directory;

void process_directory(char *path, int *total_size, int *num_files, int *num_dirs) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            (*num_dirs)++;
            process_directory(full_path, total_size, num_files, num_dirs);
        } else {
            stat(full_path, &file_stat);
            (*num_files)++;
            *total_size += file_stat.st_size;
        }
    }

    closedir(dir);
}

int main() {
    char cwd[256];
    off_t total_size = 0;
    int num_files = 0;
    int num_dirs = 0;

    getcwd(cwd, sizeof(cwd));

    process_directory(cwd, &total_size, &num_files, &num_dirs);

    printf("Total size: %lld bytes\n", (long long)total_size);
    printf("Number of files: %d\n", num_files);
    printf("Number of directories: %d\n", num_dirs);

    return 0;
}