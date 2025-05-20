//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze(char *path, int depth) {
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    int total_size = 0;
    char subpath[100];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        sprintf(subpath, "%s/%s", path, dp->d_name);

        if (lstat(subpath, &st) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        total_size += st.st_size;

        if (S_ISDIR(st.st_mode)) {
            analyze(subpath, depth+1);
        }
    }

    closedir(dir);

    for (int i = 0; i < depth; i++) {
        printf("\t");
    }

    printf("Total Size of %s: %d\n", path, total_size);
}

int main(int argc, char *argv[]) {
    char *path = ".";

    if (argc > 1) {
        path = argv[1];
    }

    printf("Analyzing Disk Space of %s\n", path);
    analyze(path, 0);
    return 0;
}