//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

typedef struct _File {
    char *name;
    size_t size;
    time_t modified;
} File;

void print_file(File *file) {
    printf("%s %ld %s\n", file->name, file->size, ctime(&file->modified));
}

int compare_files(const void *a, const void *b) {
    File *fa = (File *)a;
    File *fb = (File *)b;
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

    struct dirent *ent;
    size_t total_size = 0;
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

        File *file = malloc(sizeof(File));
        file->name = strdup(ent->d_name);
        file->size = st.st_size;
        file->modified = st.st_mtime;

        total_size += file->size;

        print_file(file);
    }

    closedir(dir);

    printf("Total size: %ld\n", total_size);

    return EXIT_SUCCESS;
}