//GEMINI-pro DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    int fd;
    struct dirent *dent;
    DIR *dir;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((dent = readdir(dir)) != NULL) {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }

        if ((fd = open(dent->d_name, O_RDONLY)) == -1) {
            perror("open");
            continue;
        }

        char buf[1024];
        int n;

        while ((n = read(fd, buf, sizeof(buf))) > 0) {
            write(STDOUT_FILENO, buf, n);
        }

        if (n == -1) {
            perror("read");
        }

        close(fd);
    }

    closedir(dir);

    return EXIT_SUCCESS;
}