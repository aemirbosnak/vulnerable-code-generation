//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct dir_entry {
    char *name;
    struct stat st;
} dir_entry;

int compare_dir_entries(const void *a, const void *b) {
    const dir_entry *da = (const dir_entry *)a;
    const dir_entry *db = (const dir_entry *)b;
    return strcmp(da->name, db->name);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *dirent;
    size_t dir_entries_count = 0;
    size_t dir_entries_capacity = 1024;
    dir_entry *dir_entries = malloc(dir_entries_capacity * sizeof(*dir_entries));
    if (dir_entries == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(argv[1]) + strlen(dirent->d_name) + 2);
        if (path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(path, "%s/%s", argv[1], dirent->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(st.st_mode)) {
            continue;
        }

        if (dir_entries_count == dir_entries_capacity) {
            dir_entries_capacity *= 2;
            dir_entries = realloc(dir_entries, dir_entries_capacity * sizeof(*dir_entries));
            if (dir_entries == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        dir_entries[dir_entries_count].name = path;
        dir_entries[dir_entries_count].st = st;
        dir_entries_count++;
    }

    closedir(dir);

    qsort(dir_entries, dir_entries_count, sizeof(*dir_entries), compare_dir_entries);

    for (size_t i = 0; i < dir_entries_count; i++) {
        printf("%s: %ld bytes\n", dir_entries[i].name, dir_entries[i].st.st_size);
        free(dir_entries[i].name);
    }

    free(dir_entries);

    return EXIT_SUCCESS;
}