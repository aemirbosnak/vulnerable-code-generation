//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

typedef struct {
    char *name;
    long long size;
    time_t mtime;
} file_info;

int compare_files(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fa->size - fb->size;
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
    file_info *files = NULL;
    size_t files_size = 0;
    size_t files_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, entry->d_name);

        struct stat st;
        if (lstat(path, &st) != 0) {
            perror("lstat");
            free(path);
            continue;
        }

        if (S_ISREG(st.st_mode)) {
            files = realloc(files, (files_size + 1) * sizeof(file_info));
            files[files_size].name = strdup(entry->d_name);
            files[files_size].size = st.st_size;
            files[files_size].mtime = st.st_mtime;
            files_size++;
            files_count++;
        }

        free(path);
    }

    closedir(dir);

    qsort(files, files_size, sizeof(file_info), compare_files);

    printf("Largest files:\n");
    for (size_t i = files_size - 1; i >= files_size - 10 && i >= 0; i--) {
        printf("%s: %lld bytes\n", files[i].name, files[i].size);
    }

    printf("\nSmallest files:\n");
    for (size_t i = 0; i < 10 && i < files_size; i++) {
        printf("%s: %lld bytes\n", files[i].name, files[i].size);
    }

    printf("\nOldest files:\n");
    for (size_t i = 0; i < 10 && i < files_size; i++) {
        printf("%s: %s\n", files[i].name, ctime(&files[i].mtime));
    }

    printf("\nNewest files:\n");
    for (size_t i = files_size - 1; i >= files_size - 10 && i >= 0; i--) {
        printf("%s: %s\n", files[i].name, ctime(&files[i].mtime));
    }

    for (size_t i = 0; i < files_size; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}