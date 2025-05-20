//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char *path;
    size_t size;
} File;

int compare_files(const void *a, const void *b) {
    const File *fa = a;
    const File *fb = b;
    return (fa->size - fb->size);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    size_t total_size = 0;
    size_t num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) != 0) {
            perror("lstat");
            free(path);
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            File file = {path, statbuf.st_size};
            total_size += file.size;
            num_files++;
        } else if (S_ISDIR(statbuf.st_mode)) {
            printf("%s:\n", path);
            int rc = main(path, argv[0]);
            if (rc != EXIT_SUCCESS) {
                return rc;
            }
        }
    }

    closedir(dir);

    if (num_files > 0) {
        File *files = malloc(num_files * sizeof(File));
        size_t i = 0;
        rewinddir(dir);
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
            strcpy(path, argv[1]);
            strcat(path, "/");
            strcat(path, entry->d_name);

            struct stat statbuf;
            if (lstat(path, &statbuf) != 0) {
                perror("lstat");
                free(path);
                continue;
            }

            if (S_ISREG(statbuf.st_mode)) {
                files[i].path = path;
                files[i].size = statbuf.st_size;
                i++;
            } else if (S_ISDIR(statbuf.st_mode)) {
                free(path);
            }
        }
        closedir(dir);

        qsort(files, num_files, sizeof(File), compare_files);

        printf("Total size: %zu bytes\n", total_size);
        printf("Number of files: %zu\n", num_files);
        for (size_t i = 0; i < num_files; i++) {
            printf("%s: %zu bytes\n", files[i].path, files[i].size);
            free(files[i].path);
        }
        free(files);
    }

    return EXIT_SUCCESS;
}