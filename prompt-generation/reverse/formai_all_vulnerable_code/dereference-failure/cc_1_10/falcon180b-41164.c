//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 4096

typedef struct {
    char path[MAX_PATH];
    long long size;
} file_t;

int compare_files(const void *a, const void *b) {
    const file_t *file1 = a;
    const file_t *file2 = b;

    if (file1->size > file2->size) {
        return -1;
    } else if (file1->size < file2->size) {
        return 1;
    } else {
        return 0;
    }
}

void print_files(file_t files[], int count) {
    qsort(files, count, sizeof(file_t), compare_files);

    for (int i = 0; i < count; i++) {
        printf("%s (%lld bytes)\n", files[i].path, files[i].size);
    }
}

void get_files(const char *path, file_t files[], int *count) {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            snprintf(files[*count].path, MAX_PATH, "%s/%s", path, ent->d_name);
            files[*count].size = ent->d_ino;
            (*count)++;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    file_t files[4096];
    int count = 0;

    get_files(argv[1], files, &count);
    print_files(files, count);

    return 0;
}