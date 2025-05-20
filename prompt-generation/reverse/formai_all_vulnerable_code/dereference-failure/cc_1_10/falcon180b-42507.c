//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[1024];
    long size;
} FileInfo;

int compare(const void *a, const void *b) {
    return (*(long *)b - *(long *)a);
}

void get_files_in_directory(const char *path, FileInfo *files) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        while ((dir = readdir(d))!= NULL) {
            if (dir->d_type == DT_REG) {
                sprintf(files->path, "%s/%s", path, dir->d_name);
                if (stat(files->path, &files->size) == 0) {
                    files->size /= 1024;
                    files->size *= 1024;
                } else {
                    files->size = 0;
                }
                files++;
            }
        }
        closedir(d);
    }
}

void print_files(FileInfo *files, int count) {
    qsort(files, count, sizeof(FileInfo), compare);
    printf("Files sorted by size:\n");
    for (int i = 0; i < count; i++) {
        printf("%20s %10ld KB\n", files[i].path, files[i].size);
    }
}

void analyze_disk_space(const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        printf("Total space: %ld KB\n", buf.f_blocks * buf.f_frsize / 1024);
        printf("Free space: %ld KB\n", buf.f_bavail * buf.f_frsize / 1024);
    } else {
        printf("Error getting disk space information.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    FileInfo files[1024];
    int count = 0;

    get_files_in_directory(argv[1], files);
    count = sizeof(files) / sizeof(FileInfo);

    print_files(files, count);

    analyze_disk_space(argv[1]);

    return 0;
}