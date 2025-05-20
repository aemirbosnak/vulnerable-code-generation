//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_DIR_NAME_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char name[MAX_DIR_NAME_LENGTH];
    long long size;
} Directory;

long long get_directory_size(const char* path) {
    Directory dir;
    dir.size = 0;
    DIR* d = opendir(path);
    if (d == NULL) {
        return -1;
    }
    struct dirent* ent;
    while ((ent = readdir(d))!= NULL) {
        if (ent->d_type == DT_DIR) {
            strncpy(dir.name, ent->d_name, MAX_DIR_NAME_LENGTH - 1);
            dir.name[MAX_DIR_NAME_LENGTH - 1] = '\0';
            long long subdir_size = get_directory_size(ent->d_name);
            if (subdir_size == -1) {
                continue;
            }
            dir.size += subdir_size;
        } else {
            strncpy(dir.name, ent->d_name, MAX_FILE_NAME_LENGTH - 1);
            dir.name[MAX_FILE_NAME_LENGTH - 1] = '\0';
            struct stat st;
            if (stat(ent->d_name, &st) == -1) {
                continue;
            }
            dir.size += st.st_size;
        }
    }
    closedir(d);
    return dir.size;
}

void print_directory_size(const char* path) {
    long long size = get_directory_size(path);
    if (size == -1) {
        printf("Error: Failed to get directory size.\n");
        return;
    }
    printf("Directory size: %lld bytes\n", size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    print_directory_size(argv[1]);
    return 0;
}