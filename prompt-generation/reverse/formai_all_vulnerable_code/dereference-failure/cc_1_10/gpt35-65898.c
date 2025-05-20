//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void recursive_admin(const char* path, int depth) {
    char* indent = calloc(depth + 1, sizeof(char));
    memset(indent, '\t', depth);
    printf("%s%s\n", indent, path);

    struct stat st;
    if (stat(path, &st) == -1) {
        printf("Error: Could not stat directory %s\n", path);
        return;
    }

    if (S_ISDIR(st.st_mode)) {
        DIR* dir = opendir(path);
        if (dir == NULL) {
            printf("Error: Could not open directory %s\n", path);
            return;
        }

        struct dirent* dp;
        while ((dp = readdir(dir)) != NULL) {
            char* name = dp->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
                continue;
            }

            char* nextpath = calloc(strlen(path) + strlen(name) + 2, sizeof(char));
            sprintf(nextpath, "%s/%s", path, name);
            recursive_admin(nextpath, depth + 1);
            free(nextpath);
        }

        closedir(dir);
    }

    free(indent);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    recursive_admin(argv[1], 0);

    return 0;
}