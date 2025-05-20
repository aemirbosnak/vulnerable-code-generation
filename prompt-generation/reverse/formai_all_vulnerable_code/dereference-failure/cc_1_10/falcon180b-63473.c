//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    unsigned long long size;
} FileInfo;

void find_files(const char* path, FileInfo* files, int count, int* total_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (count >= MAX_PATH) {
                printf("Too many files found.\n");
                exit(1);
            }

            char file_path[MAX_PATH];
            sprintf(file_path, "%s/%s", path, ent->d_name);

            struct stat st;
            if (stat(file_path, &st)!= 0) {
                printf("Failed to stat file: %s\n", file_path);
                exit(1);
            }

            files[count].size = st.st_size;
            strcpy(files[count++].name, ent->d_name);
        }
    }

    closedir(dir);
}

void print_files(FileInfo* files, int count) {
    printf("Name\t\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%llu bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    FileInfo files[MAX_PATH];
    int total_files = 0;

    find_files(argv[1], files, 0, &total_files);
    print_files(files, total_files);

    return 0;
}