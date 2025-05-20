//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd, bytes_read, bytes_written;
    char buffer[4096];
    struct stat st;
    DIR *dir;
    struct dirent *entry;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (stat(entry->d_name, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            printf("Directory: %s\n", entry->d_name);
        } else {
            printf("File: %s\n", entry->d_name);
        }

        bytes_read = read(STDOUT_FILENO, buffer, 4096);
        bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            perror("write");
            return 1;
        }
    }

    closedir(dir);

    return 0;
}