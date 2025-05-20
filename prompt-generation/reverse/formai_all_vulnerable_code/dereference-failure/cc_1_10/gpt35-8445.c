//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <dirent.h> 

void analyze(char *path, int depth) {
    struct dirent *dir;
    struct stat statbuf;
    int size = 0;

    DIR *d = opendir(path);
    if (!d) return;

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        char *fullpath = malloc(strlen(path) + strlen(dir->d_name) + 2);
        sprintf(fullpath, "%s/%s", path, dir->d_name);

        if (lstat(fullpath, &statbuf) < 0) {
            printf("Error: Could not stat %s\n", fullpath);
            free(fullpath);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze(fullpath, depth + 1);
        } else {
            size += statbuf.st_size;
        }

        free(fullpath);
    }

    closedir(d);

    char indent[depth * 2 + 1];
    memset(indent, ' ', depth * 2);
    indent[depth * 2] = 0;

    printf("%s%s (%d bytes)\n", indent, path, size);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    printf("Analyzing disk space usage in %s\n", path);

    struct stat statbuf;
    if (lstat(path, &statbuf) < 0) {
        printf("Error: Could not stat %s\n", path);
        return 1;
    }

    if (!S_ISDIR(statbuf.st_mode)) {
        printf("Error: %s is not a directory\n", path);
        return 1;
    }

    analyze(path, 0);

    return 0;
}