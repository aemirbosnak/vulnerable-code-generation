//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;
    char buf[512];
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        snprintf(buf, sizeof(buf), "%s/%s", argv[1], ent->d_name);

        if ((fd = open(buf, O_RDONLY)) == -1) {
            perror("open");
            continue;
        }

        if (read(fd, buf, sizeof(buf)) == -1) {
            perror("read");
            close(fd);
            continue;
        }

        close(fd);

        printf("%s: %s\n", ent->d_name, buf);
    }

    closedir(dir);

    return 0;
}