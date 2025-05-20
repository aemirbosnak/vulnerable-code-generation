//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1024

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
} file_t;

int compare_files(const void *a, const void *b) {
    const file_t *file_a = a;
    const file_t *file_b = b;

    return strcmp(file_a->name, file_b->name);
}

int get_file_size(const char *path) {
    struct statvfs statvfs_buf;
    statvfs(path, &statvfs_buf);

    return (int) statvfs_buf.f_bsize * statvfs_buf.f_blocks;
}

void get_files(const char *path, file_t *files) {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }

    struct dirent *dirent = NULL;
    int count = 0;

    while ((dirent = readdir(dir))!= NULL) {
        if (count >= MAX_FILE_NAME) {
            break;
        }

        if (dirent->d_type == DT_REG) {
            strncpy(files[count].name, dirent->d_name, MAX_FILE_NAME - 1);
            files[count].name[MAX_FILE_NAME - 1] = '\0';
            files[count].size = get_file_size(dirent->d_name);
            count++;
        }
    }

    closedir(dir);
}

void print_files(file_t *files, int count) {
    qsort(files, count, sizeof(file_t), compare_files);

    for (int i = 0; i < count; i++) {
        printf("%-20s %10d bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    file_t files[MAX_FILE_NAME];
    int count = 0;

    get_files(argv[1], files);
    print_files(files, count);

    return 0;
}