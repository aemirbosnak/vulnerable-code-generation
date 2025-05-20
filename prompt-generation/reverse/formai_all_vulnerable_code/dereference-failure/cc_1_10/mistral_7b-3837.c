//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char path[1024];
    off_t size;
} FileInfo;

void traverse_directory(const char *path, FileInfo files[], int *num_files, off_t *total_size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    FileInfo files[1024];
    int num_files = 0;
    off_t total_size = 0;
    traverse_directory(argv[1], files, &num_files, &total_size);

    printf("Total size of %s: %lld bytes\n", argv[1], (long long)total_size);
    printf("Number of files: %d\n", num_files);

    for (int i = 0; i < num_files; i++) {
        printf("%s: %lld bytes\n", files[i].path, (long long)files[i].size);
    }

    return 0;
}

void traverse_directory(const char *path, FileInfo files[], int *num_files, off_t *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir))) {
        snprintf(files[*num_files].path, sizeof(files[*num_files].path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            traverse_directory(files[*num_files].path, files, num_files, total_size);
        } else {
            if (stat(files[*num_files].path, &file_stat) == -1) {
                perror("stat");
                continue;
            }
            files[*num_files].size = file_stat.st_size;
            (*total_size) += files[*num_files].size;
            (*num_files)++;
        }
    }

    closedir(dir);
}