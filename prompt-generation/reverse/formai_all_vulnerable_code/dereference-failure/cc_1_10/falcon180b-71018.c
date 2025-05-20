//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

// Function to get the size of a directory
long long getDirectorySize(char* path) {
    long long size = 0;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                char subPath[MAX_PATH_LENGTH];
                strcpy(subPath, path);
                strcat(subPath, "/");
                strcat(subPath, ent->d_name);

                if (ent->d_type == DT_DIR) {
                    size += getDirectorySize(subPath);
                } else {
                    struct stat st;
                    stat(subPath, &st);
                    size += st.st_size;
                }
            }
        }
        closedir(dir);
    }

    return size;
}

// Function to print the disk space usage
void printDiskSpaceUsage(long long size, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%s:\t%lld bytes\n", "Total", size);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char* directory = argv[1];
    long long size = getDirectorySize(directory);

    printDiskSpaceUsage(size, 0);

    return 0;
}