//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

void list_directory(char* dir_path) {
    DIR* dir;
    struct dirent* entry;
    char file_path[MAX_PATH_LEN];
    char* entry_name;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(file_path, MAX_PATH_LEN, "%s/%s", dir_path, entry->d_name);
        if ((entry_name = realpath(file_path, NULL)) == NULL) {
            perror("realpath");
            exit(EXIT_FAILURE);
        }

        printf("%s\n", entry_name);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char* dir_path = argv[1];

    printf("Directory: %s\n", dir_path);

    list_directory(dir_path);

    return 0;
}