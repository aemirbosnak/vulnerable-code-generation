//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MB(bytes) ((bytes) / 1024 / 1024)

struct dir_size {
    char *dir_name;
    size_t total_bytes;
};

int cmp(const void *a, const void *b) {
    struct dir_size *num_a = (struct dir_size*) a;
    struct dir_size *num_b = (struct dir_size*) b;

    return num_b->total_bytes - num_a->total_bytes;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    struct dir_size dir_sizes[1000];
    size_t num_dirs = 0;
    dir_sizes[0].dir_name = "/";

    dir = opendir("/");

    if (!dir) {
        printf("Error opening / directory");
        exit(1);
    }

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            snprintf(path, sizeof(path), "%s/%s", "/", entry->d_name);
            DIR *subdir = opendir(path);

            if (!subdir) {
                printf("Error opening %s directory\n", path);
                continue;
            }

            size_t bytes = 0;
            struct dirent *sub_entry;

            while ((sub_entry = readdir(subdir))) {
                if (sub_entry->d_type == DT_REG) {
                    char sub_path[256];
                    snprintf(sub_path, sizeof(sub_path), "%s/%s", path, sub_entry->d_name);

                    FILE *file = fopen(sub_path, "rb");

                    if (file == NULL) {
                        printf("Error opening %s file\n", sub_path);
                    } else {
                        fseek(file, 0L, SEEK_END);
                        size_t file_size = ftell(file);
                        fclose(file);
                        bytes += file_size;
                    }
                }
            }

            closedir(subdir);

            dir_sizes[num_dirs].dir_name = entry->d_name;
            dir_sizes[num_dirs].total_bytes = bytes;

            num_dirs++;
        }
    }

    closedir(dir);

    qsort(dir_sizes, num_dirs, sizeof(struct dir_size), cmp);

    printf("Disk space usage:\n\n");

    for (size_t i = 0; i < num_dirs; i++) {
        printf("%s: %lu MB\n", dir_sizes[i].dir_name, MB(dir_sizes[i].total_bytes));
    }

    return 0;
}