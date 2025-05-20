//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char name[256];
    int size;
} File;

void read_dir(char* path, File* files, int* count) {
    DIR* dir = opendir(path);
    struct dirent* entry;

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char* sub_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            strcpy(sub_path, path);
            strcat(sub_path, "/");
            strcat(sub_path, entry->d_name);

            read_dir(sub_path, files, count);
            free(sub_path);
        } else {
            File file;
            strcpy(file.name, entry->d_name);
            file.size = entry->d_reclen;

            if (*count >= 0) {
                files[*count] = file;
                (*count)++;
            }
        }
    }

    closedir(dir);
}

void sort_files(File* files, int count, int (*compare)(const void*, const void*)) {
    qsort(files, count, sizeof(File), compare);
}

int compare_size(const void* a, const void* b) {
    const File* file_a = (const File*)a;
    const File* file_b = (const File*)b;

    return (file_a->size > file_b->size) - (file_a->size < file_b->size);
}

void print_files(File* files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-40s %10d bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[256];
    strcpy(path, argv[1]);

    int count = 0;
    File* files = malloc(1024 * sizeof(File));

    read_dir(path, files, &count);
    sort_files(files, count, compare_size);
    print_files(files, count);

    free(files);
    return 0;
}