//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUF_SIZE 8192

typedef struct file_info {
    char name[MAX_PATH];
    off_t size;
} file_info;

void traverse_directory(const char *path, file_info files[], int *num_files) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(files[*num_files].name, MAX_PATH, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            traverse_directory(files[*num_files].name, files, num_files);
        } else {
            if (lstat(files[*num_files].name, &file_stat) == -1) {
                perror("lstat");
                continue;
            }

            files[*num_files].size = file_stat.st_size;
            (*num_files)++;
        }
    }

    closedir(dir);
}

int main() {
    file_info files[1024];
    int num_files = 0;

    traverse_directory(".", files, &num_files);

    if (num_files > 1024) {
        fprintf(stderr, "Too many files in the directory\n");
        return 1;
    }

    printf("Name\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%-20s\t%lld bytes\n", files[i].name, files[i].size);
    }

    return 0;
}