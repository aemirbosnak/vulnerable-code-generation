//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH 256

// Function to compare two files
int file_compare(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "rb");
    FILE* f2 = fopen(file2, "rb");

    if (f1 == NULL || f2 == NULL) {
        return -1;
    }

    char buffer1[1024];
    char buffer2[1024];

    while (fread(buffer1, 1, sizeof(buffer1), f1) == sizeof(buffer1)) {
        if (fread(buffer2, 1, sizeof(buffer2), f2)!= sizeof(buffer2)) {
            return -1;
        }

        int result = memcmp(buffer1, buffer2, sizeof(buffer1));
        if (result!= 0) {
            return result;
        }
    }

    if (ferror(f1)) {
        return -1;
    }

    if (ferror(f2)) {
        return -1;
    }

    return 0;
}

// Function to synchronize files between two directories
void sync_files(const char* dir1, const char* dir2) {
    DIR* d1 = opendir(dir1);
    DIR* d2 = opendir(dir2);

    if (d1 == NULL || d2 == NULL) {
        printf("Error: One or both of the directories do not exist.\n");
        return;
    }

    struct dirent* dirent1;
    struct dirent* dirent2;

    while ((dirent1 = readdir(d1))!= NULL) {
        char path1[MAX_PATH];
        snprintf(path1, MAX_PATH, "%s/%s", dir1, dirent1->d_name);

        while ((dirent2 = readdir(d2))!= NULL) {
            char path2[MAX_PATH];
            snprintf(path2, MAX_PATH, "%s/%s", dir2, dirent2->d_name);

            if (strcmp(dirent1->d_name, dirent2->d_name) == 0) {
                if (file_compare(path1, path2)!= 0) {
                    printf("File '%s' needs to be synchronized.\n", dirent1->d_name);
                }
            }
        }
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}