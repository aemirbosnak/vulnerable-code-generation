//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    long long size;
    int is_file;
} Entry;

void add_entry(Entry *entries, int *num_entries, const char *path, const struct stat *stat_buf) {
    if (*num_entries >= MAX_PATH) {
        printf("Error: Too many entries.\n");
        exit(1);
    }

    Entry entry = {0};
    strncpy(entry.path, path, MAX_PATH);
    entry.size = stat_buf->st_size;
    entry.is_file = S_ISREG(stat_buf->st_mode);

    entries[*num_entries] = entry;
    (*num_entries)++;
}

void print_entries(Entry *entries, int num_entries) {
    printf("Path\tSize\tIs File\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%lld\t%s\n", entries[i].path, entries[i].size, entries[i].is_file? "Yes" : "No");
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    Entry entries[MAX_PATH];
    int num_entries = 0;

    struct dirent *dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_REG || dirent->d_type == DT_LNK) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "%s/%s", argv[1], dirent->d_name);

            struct stat stat_buf;
            if (stat(path, &stat_buf) == -1) {
                printf("Error: Could not stat file.\n");
                closedir(dir);
                return 1;
            }

            add_entry(entries, &num_entries, path, &stat_buf);
        }
    }

    closedir(dir);

    print_entries(entries, num_entries);

    return 0;
}