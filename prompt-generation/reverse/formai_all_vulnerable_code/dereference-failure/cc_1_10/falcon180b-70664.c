//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

struct dirent *readdir(DIR *dir) {
    struct dirent *d;
    if (dir == NULL) {
        d = NULL;
    } else {
        d = readdir(dir);
    }
    return d;
}

void medieval_disk_space_analyzer(char *path) {
    DIR *dir;
    struct dirent *d;
    dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        return;
    }

    printf("Medieval Disk Space Analyzer\n");
    printf("Directory: %s\n", path);
    printf("Files:\n");

    while ((d = readdir(dir))!= NULL) {
        printf("File: %s\n", d->d_name);
    }

    closedir(dir);
}

void print_file_size(char *path) {
    struct statvfs buf;
    statvfs(path, &buf);

    printf("File size: %ld bytes\n", buf.f_frsize * buf.f_blocks);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s directory file\n", argv[0]);
        return 1;
    }

    medieval_disk_space_analyzer(argv[1]);

    if (strcmp(argv[2], "-s") == 0) {
        print_file_size(argv[1]);
    }

    return 0;
}