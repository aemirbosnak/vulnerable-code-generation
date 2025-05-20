//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char *path;
    unsigned long long size;
} FileInfo;

int compare_files(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];

    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int num_files = 0;
    FileInfo *files = NULL;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH_LEN];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) != 0) {
            perror("stat");
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            files = realloc(files, (num_files + 1) * sizeof(FileInfo));
            files[num_files].path = strdup(path);
            files[num_files].size = statbuf.st_size;
            num_files++;
        }
    }

    qsort(files, num_files, sizeof(FileInfo), compare_files);

    printf("Top 10 Largest Files in %s:\n", directory);
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%s: %llu bytes\n", files[i].path, files[i].size);
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }
    free(files);
    closedir(dir);

    return EXIT_SUCCESS;
}