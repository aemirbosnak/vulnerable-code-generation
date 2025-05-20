//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

typedef struct {
    char name[256];
    off_t size;
} file_t;

void traverse_directory(char *path, file_t *files, int *num_files, off_t *total_size) {
    DIR *dir;
    struct dirent *entry;
    int i;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(full_path, &st) == -1) {
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            traverse_directory(full_path, files, num_files, total_size);
        } else if (S_ISREG(st.st_mode)) {
            for (i = 0; i < *num_files; i++) {
                if (strcmp(files[i].name, entry->d_name) == 0) {
                    files[i].size += st.st_size;
                    goto next_entry;
                }
            }

            file_t new_file = {entry->d_name, st.st_size};
            if (*num_files < 100) {
                files[*num_files++] = new_file;
            } else {
                free(files);
                files = realloc(files, sizeof(file_t) * (*num_files + 1));
                files[*num_files++] = new_file;
            }

            *total_size += st.st_size;
        }

next_entry: {};
    }

    closedir(dir);
}

int main() {
    char cwd[256];
    getcwd(cwd, sizeof(cwd));

    file_t files[1000];
    int num_files = 0;
    off_t total_size = 0;

    traverse_directory(cwd, files, &num_files, &total_size);

    printf("Disk usage report for %s:\n", cwd);
    for (int i = 0; i < num_files; i++) {
        printf("%s: %lld bytes\n", files[i].name, files[i].size);
        total_size -= files[i].size;
    }

    printf("Total free space: %lld bytes\n", total_size);

    free(files);
    return 0;
}