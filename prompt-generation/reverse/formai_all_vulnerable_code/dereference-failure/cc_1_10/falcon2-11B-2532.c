//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 256
#define MAX_SUBDIRS 10

int get_subdirs(char *path, struct dirent **entries, int num_entries, struct stat *st) {
    int i, j;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i]->d_name, ".")!= 0 && strcmp(entries[i]->d_name, "..")!= 0) {
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, entries[i]->d_name);
            if (stat(full_path, st) == 0) {
                if (st->st_nlink > MAX_SUBDIRS) {
                    continue;
                }
                get_subdirs(full_path, entries, num_entries, st);
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(1);
    }

    char path[MAX_PATH_LEN];
    strncpy(path, argv[1], MAX_PATH_LEN);

    struct stat st;
    int num_entries;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent **entries = malloc(sizeof(struct dirent*) * MAX_SUBDIRS);
    for (int i = 0; i < MAX_SUBDIRS; i++) {
        entries[i] = NULL;
    }
    num_entries = scandir(path, &entries, NULL, alphasort);
    if (num_entries < 0) {
        perror("scandir");
        exit(1);
    }

    get_subdirs(path, entries, num_entries, &st);

    free(entries);

    printf("Total disk space used: %lu bytes\n", st.st_size);

    return 0;
}