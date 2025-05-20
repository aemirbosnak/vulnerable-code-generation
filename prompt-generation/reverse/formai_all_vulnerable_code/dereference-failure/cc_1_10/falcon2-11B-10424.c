//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void analyze_disk_space(const char *path) {
    struct stat st;
    DIR *dir;
    struct dirent *dent;

    if (stat(path, &st)!= 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    while ((dent = readdir(dir))!= NULL) {
        char *file_path = malloc(strlen(path) + strlen(dent->d_name) + 1);
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, dent->d_name);

        struct stat st_file;
        if (stat(file_path, &st_file)!= 0) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        if (S_ISDIR(st_file.st_mode)) {
            analyze_disk_space(file_path);
        } else {
            printf("%s: %ld bytes\n", dent->d_name, st_file.st_size);
        }

        free(file_path);
    }

    closedir(dir);
}

int main() {
    const char *path = "/path/to/directory";
    analyze_disk_space(path);

    return 0;
}