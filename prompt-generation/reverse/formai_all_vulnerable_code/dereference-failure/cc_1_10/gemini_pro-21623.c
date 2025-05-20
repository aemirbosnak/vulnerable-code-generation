//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char *name;
    long long size;
} file_info;

int compare_file_info(const void *a, const void *b) {
    const file_info *fa = a;
    const file_info *fb = b;
    return (fa->size > fb->size) - (fa->size < fb->size);
}

int main(int argc, char *argv[]) {
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
    long long total_size = 0;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", argv[1], entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        file_info *file = malloc(sizeof(file_info));
        file->name = strdup(entry->d_name);
        file->size = statbuf.st_size;

        total_size += file->size;
        num_files++;

        free(path);
    }

    closedir(dir);

    file_info *files = malloc(num_files * sizeof(file_info));
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", argv[1], entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        file_info *file = &files[i++];
        file->name = strdup(entry->d_name);
        file->size = statbuf.st_size;

        free(path);
    }

    qsort(files, num_files, sizeof(file_info), compare_file_info);

    printf("Total size: %lld bytes\n", total_size);
    printf("Number of files: %d\n", num_files);
    printf("\nTop 10 largest files:\n");
    for (i = 0; i < 10 && i < num_files; i++) {
        printf("%s: %lld bytes\n", files[i].name, files[i].size);
    }

    for (i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}