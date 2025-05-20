//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char* name;
    long size;
} file_info;

int compare_file_info(const void* a, const void* b) {
    file_info* fa = (file_info*)a;
    file_info* fb = (file_info*)b;
    return fb->size - fa->size;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent* dirent;
    long total_size = 0;
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char* path = malloc(strlen(argv[1]) + strlen(dirent->d_name) + 2);
        sprintf(path, "%s/%s", argv[1], dirent->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            return EXIT_FAILURE;
        }

        file_info* file_info = malloc(sizeof(file_info));
        file_info->name = malloc(strlen(dirent->d_name) + 1);
        strcpy(file_info->name, dirent->d_name);
        file_info->size = statbuf.st_size;

        total_size += file_info->size;

        printf("%10ld %s\n", file_info->size, file_info->name);

        free(path);
        free(file_info->name);
        free(file_info);
    }

    closedir(dir);

    printf("Total size: %ld\n", total_size);

    return EXIT_SUCCESS;
}