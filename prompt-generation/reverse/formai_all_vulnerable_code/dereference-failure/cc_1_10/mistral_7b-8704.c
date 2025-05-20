//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: detailed
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
} FileOrDir;

void traverse_directory(const char *path, FileOrDir files[], int *num_files, off_t *total_size);

int main() {
    const char *root_path = "/";
    FileOrDir files[1024];
    int num_files = 0;
    off_t total_size = 0;

    traverse_directory(root_path, files, &num_files, &total_size);

    printf("\nDirectory Size Report\n");
    printf("----------------------\n");
    printf("Path                Size(Bytes)   %% of Total\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < num_files; i++) {
        if (files[i].size > 0) {
            off_t size_pct = (files[i].size * 100) / total_size;
            printf("%-18s %-18llu   %4.2f%%\n", files[i].name, files[i].size, size_pct);
        }
    }

    return 0;
}

void traverse_directory(const char *path, FileOrDir files[], int *num_files, off_t *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        traverse_directory(full_path, files, num_files, total_size);

        if (stat(full_path, &file_stat) == -1) {
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            continue;
        }

        files[*num_files].size = file_stat.st_size;
        strcpy(files[*num_files].name, entry->d_name);
        (*num_files)++;
        (*total_size) += file_stat.st_size;
    }

    closedir(dir);
}