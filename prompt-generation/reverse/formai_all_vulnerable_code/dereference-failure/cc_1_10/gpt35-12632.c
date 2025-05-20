//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    long long total_size = 0;

    // check if the directory path is provided
    if (argc != 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the directory
    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error opening directory %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("------------------------\n");
    printf("C Disk Space Analyzer\n");
    printf("------------------------\n");

    //iterate through the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) {
            continue;
        }

        char *file_name = entry->d_name;
        char *file_path = malloc(strlen(argv[1]) + strlen(file_name) + 2);

        sprintf(file_path, "%s/%s", argv[1], file_name);

        if (stat(file_path, &file_stat) != -1) {
            printf("%-30s %10lld bytes\n", entry->d_name, file_stat.st_size);
            total_size += file_stat.st_size;
        }

        free(file_path);
    }

    printf("------------------------\n");
    printf("Total Size: %lld bytes\n", total_size);
    printf("------------------------\n");

    closedir(dir);
    exit(EXIT_SUCCESS);
}