//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    long size;
} file_t;

int compare_files(const void *a, const void *b) {
    return ((file_t *)a)->size - ((file_t *)b)->size;
}

int main(void) {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *dent;
    long total_size = 0;
    while ((dent = readdir(dir)) != NULL) {
        if (dent->d_type == DT_REG) {
            char *path = malloc(strlen(dent->d_name) + 2);
            strcpy(path, "./");
            strcat(path, dent->d_name);

            struct stat st;
            if (stat(path, &st) == -1) {
                perror("stat");
                return EXIT_FAILURE;
            }

            file_t *file = malloc(sizeof(file_t));
            file->name = malloc(strlen(dent->d_name) + 1);
            strcpy(file->name, dent->d_name);
            file->size = st.st_size;

            total_size += file->size;

            free(path);
        }
    }

    closedir(dir);

    file_t *files = malloc(sizeof(file_t) * total_size);
    int i = 0;
    dir = opendir(".");
    while ((dent = readdir(dir)) != NULL) {
        if (dent->d_type == DT_REG) {
            char *path = malloc(strlen(dent->d_name) + 2);
            strcpy(path, "./");
            strcat(path, dent->d_name);

            struct stat st;
            if (stat(path, &st) == -1) {
                perror("stat");
                return EXIT_FAILURE;
            }

            files[i].name = malloc(strlen(dent->d_name) + 1);
            strcpy(files[i].name, dent->d_name);
            files[i].size = st.st_size;

            i++;

            free(path);
        }
    }

    closedir(dir);

    qsort(files, total_size, sizeof(file_t), compare_files);

    for (i = 0; i < total_size; i++) {
        printf("%s %ld\n", files[i].name, files[i].size);
        free(files[i].name);
    }

    free(files);

    return EXIT_SUCCESS;
}