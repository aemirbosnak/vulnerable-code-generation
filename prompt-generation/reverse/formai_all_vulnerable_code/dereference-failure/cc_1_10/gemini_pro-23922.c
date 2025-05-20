//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file_info {
    char *name;
    long size;
};

int compare_files(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;
    return fb->size - fa->size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *dir = argv[1];
    DIR *d = opendir(dir);
    if (d == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    int num_files = 0;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", dir, entry->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            free(path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        num_files++;
    }

    closedir(d);

    struct file_info *files = malloc(sizeof(struct file_info) * num_files);
    int i = 0;
    d = opendir(dir);
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", dir, entry->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            free(path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        files[i].name = strdup(entry->d_name);
        files[i].size = st.st_size;
        i++;
    }

    closedir(d);

    qsort(files, num_files, sizeof(struct file_info), compare_files);

    for (i = 0; i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].name, files[i].size);
        free(files[i].name);
    }

    free(files);

    return EXIT_SUCCESS;
}