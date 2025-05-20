//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/wait.h>

int is_executable(char *filename)
{
    struct stat buffer;
    if (stat(filename, &buffer) == -1) {
        return -1;
    }
    return S_ISREG(buffer.st_mode) && S_IXUSR & buffer.st_mode;
}

void scan_dir(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir))!= NULL) {
        if (!strcmp(entry->d_name, ".") ||!strcmp(entry->d_name, "..")) {
            continue;
        }

        if (is_executable(path + strlen(path) + strlen(entry->d_name) + 1)) {
            printf("%s is an executable file.\n", entry->d_name);
        } else {
            printf("%s is not an executable file.\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    scan_dir(argv[1]);

    return 0;
}