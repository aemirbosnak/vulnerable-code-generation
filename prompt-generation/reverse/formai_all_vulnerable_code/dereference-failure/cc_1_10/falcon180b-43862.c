//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char name[256];
    long long size;
} File;

void print_files(File* files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%lld bytes)\n", files[i].name, files[i].size);
    }
}

int get_files(char* path, File* files, int max_count) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    struct dirent* ent;
    int count = 0;
    while ((ent = readdir(dir))!= NULL && count < max_count) {
        if (ent->d_type == DT_REG) {
            File file;
            strncpy(file.name, ent->d_name, sizeof(file.name));
            file.size = ent->d_reclen;
            files[count] = file;
            count++;
        }
    }

    closedir(dir);
    return count;
}

void analyze_directory(char* path) {
    char buffer[BUFFER_SIZE];
    File files[100];
    int file_count = get_files(path, files, sizeof(files) / sizeof(File));
    if (file_count == 0) {
        printf("Directory is empty.\n");
        return;
    }

    long long total_size = 0;
    printf("Directory size: ");
    for (int i = 0; i < file_count; i++) {
        total_size += files[i].size;
        if (files[i].size > MAX_FILE_SIZE) {
            printf("\n");
            printf("WARNING: File '%s' is larger than 10 MB.\n", files[i].name);
        }
    }
    printf(" %lld bytes\n", total_size);
    print_files(files, file_count);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}