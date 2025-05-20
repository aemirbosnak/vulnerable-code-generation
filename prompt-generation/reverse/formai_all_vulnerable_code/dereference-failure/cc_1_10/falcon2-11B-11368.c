//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>

// Function to get disk usage of a file
void get_disk_usage(char *path, struct stat *st) {
    int fd;
    if ((fd = open(path, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
    fstat(fd, st);
    close(fd);
}

// Function to get disk usage of a directory
void get_disk_usage_dir(char *path, struct stat *st) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(1);
    }
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_name[0] == '.')
            continue;
        char new_path[1024];
        sprintf(new_path, "%s/%s", path, ent->d_name);
        get_disk_usage(new_path, st);
    }
    closedir(dir);
}

// Function to get disk usage of a path
void get_disk_usage_path(char *path, struct stat *st) {
    get_disk_usage(path, st);
}

int main() {
    char *path = "/";
    struct stat st;

    get_disk_usage_path(path, &st);
    printf("Total disk usage: %ld bytes\n", st.st_size);

    get_disk_usage_dir(path, &st);
    printf("Disk usage in %s: %ld bytes\n", path, st.st_size);

    return 0;
}