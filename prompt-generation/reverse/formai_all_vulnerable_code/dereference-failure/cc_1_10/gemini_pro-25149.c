//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    int size;
} file_t;

int compare_size(const void *a, const void *b) {
    file_t *fa = (file_t *)a;
    file_t *fb = (file_t *)b;
    return fb->size - fa->size;
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

    struct dirent *ent;
    int num_files = 0;
    int total_size = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char path[strlen(argv[1]) + strlen(ent->d_name) + 2];
        sprintf(path, "%s/%s", argv[1], ent->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        file_t file;
        file.name = strdup(ent->d_name);
        file.size = st.st_size;

        num_files++;
        total_size += st.st_size;
    }

    closedir(dir);

    file_t *files = malloc(sizeof(file_t) * num_files);
    int i = 0;
    dir = opendir(argv[1]);
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char path[strlen(argv[1]) + strlen(ent->d_name) + 2];
        sprintf(path, "%s/%s", argv[1], ent->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        files[i].name = strdup(ent->d_name);
        files[i].size = st.st_size;

        i++;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(file_t), compare_size);

    printf("Total size: %d bytes\n", total_size);
    printf("Number of files: %d\n", num_files);
    printf("\n");
    printf("Largest files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s %d bytes\n", files[i].name, files[i].size);
    }

    for (i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}