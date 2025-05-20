//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

typedef struct {
    char *path;
    long size;
} file_info;

int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;

    return fb->size - fa->size;
}

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH];
    DIR *dir;
    struct dirent *entry;
    file_info *files;
    int num_files = 0;
    long total_size = 0;

    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(path, argv[1], MAX_PATH_LENGTH);
    path[MAX_PATH_LENGTH - 1] = '\0';

    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        struct stat statbuf;
        file_info file;

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
        if (lstat(full_path, &statbuf) == -1) {
            fprintf(stderr, "Error getting file info: %s\n", strerror(errno));
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            continue;
        }

        file.path = strdup(full_path);
        file.size = statbuf.st_size;

        files = realloc(files, (num_files + 1) * sizeof(file_info));
        files[num_files++] = file;

        total_size += file.size;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(file_info), compare_file_info);

    for (int i = 0; i < num_files; i++) {
        printf("%20ld %s\n", files[i].size, files[i].path);
        free(files[i].path);
    }

    free(files);

    printf("Total size: %ld\n", total_size);

    return EXIT_SUCCESS;
}