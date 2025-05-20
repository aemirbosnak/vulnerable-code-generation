//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 1024

typedef struct {
    char name[1024];
    unsigned long long size;
} file_t;

file_t *files = NULL;
unsigned long long total_size = 0;
unsigned long long total_files = 0;

void add_file(const char *path, const struct statvfs *statvfs) {
    unsigned long long size = statvfs->f_blocks * statvfs->f_frsize;
    if (total_files >= MAX_FILES) {
        printf("Maximum number of files reached!\n");
        return;
    }
    files = realloc(files, sizeof(file_t) * (total_files + 1));
    strncpy(files[total_files].name, path, sizeof(files[total_files].name) - 1);
    files[total_files].size = size;
    total_size += size;
    total_files++;
}

void print_files(void) {
    printf("Total files: %llu\n", total_files);
    printf("Total size: %llu bytes\n", total_size);
    printf("File\t\tSize\n");
    for (unsigned int i = 0; i < total_files; i++) {
        printf("%s\t\t%llu bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char path[1024];
    strcpy(path, argv[1]);
    strcat(path, "/");
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory!\n");
        return 1;
    }
    struct statvfs statvfs;
    if (fstatvfs(dirfd(dir), &statvfs)!= 0) {
        printf("Error getting disk space!\n");
        closedir(dir);
        return 1;
    }
    closedir(dir);
    char *ptr = path + strlen(path);
    while (*ptr!= '/') {
        ptr--;
        *ptr = '\0';
        add_file(path, &statvfs);
        strcat(path, "../");
    }
    print_files();
    return 0;
}