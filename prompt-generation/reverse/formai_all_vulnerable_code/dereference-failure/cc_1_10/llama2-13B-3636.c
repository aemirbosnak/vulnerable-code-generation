//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_DEPTH 5

void recursion(char *path) {
    struct dirent *dirp;
    char full_path[MAX_PATH];
    DIR *dp;

    if (path[0] == '\0') {
        printf("Current Directory: \n");
        return;
    }

    snprintf(full_path, MAX_PATH, "%s/", path);
    dp = opendir(full_path);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (dirp->d_name[0] == '.') {
            continue;
        }

        // Handle file
        if (dirp->d_type == DT_REG) {
            printf("%s\n", dirp->d_name);
        }

        // Recursively call for subdirectories
        else if (dirp->d_type == DT_DIR) {
            recursion(full_path);
        }
    }

    closedir(dp);
}

int main() {
    char path[MAX_PATH];

    // Set the initial path
    snprintf(path, MAX_PATH, "/home/user/Documents");

    // Recursively explore the directory
    recursion(path);

    return 0;
}