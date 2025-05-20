//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define MAX_DIR_SIZE 4096
#define MAX_FILE_SIZE 1024
#define MAX_LINE_SIZE 256

void print_dir(char *dir, int level, char *prefix)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char path[MAX_DIR_SIZE];
    int i;

    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        lstat(path, &statbuf);

        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s%s\n", prefix, entry->d_name);
            print_dir(path, level + 1, prefix);
        } else if (S_ISREG(statbuf.st_mode)) {
            printf("%s%s\n", prefix, entry->d_name);
        } else {
            printf("%s%s\n", prefix, entry->d_name);
        }
    }

    closedir(dp);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_dir(argv[1], 0, "");

    return EXIT_SUCCESS;
}