//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[1024];
    int size;
} FileInfo;

void get_file_info(const char *path, FileInfo *file) {
    struct stat statbuf;
    stat(path, &statbuf);
    file->size = statbuf.st_size;
    strncpy(file->path, path, 1023);
    file->path[1023] = '\0';
}

int compare_files(const void *a, const void *b) {
    const FileInfo *file1 = a;
    const FileInfo *file2 = b;
    return file1->size - file2->size;
}

void print_file_info(const FileInfo *file) {
    printf("%s - %d bytes\n", file->path, file->size);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", argv[1]);
        return 1;
    }

    int num_files = 0;
    FileInfo *files = malloc(sizeof(FileInfo) * 1024);
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (num_files >= 1024) {
                printf("Error: Too many files in directory\n");
                closedir(dir);
                free(files);
                return 1;
            }
            char path[1024];
            sprintf(path, "%s/%s", argv[1], ent->d_name);
            get_file_info(path, &files[num_files]);
            num_files++;
        }
    }

    closedir(dir);

    qsort(files, num_files, sizeof(FileInfo), compare_files);

    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    free(files);
    return 0;
}