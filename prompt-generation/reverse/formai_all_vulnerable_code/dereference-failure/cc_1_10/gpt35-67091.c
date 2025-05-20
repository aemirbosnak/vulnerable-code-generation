//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

// function to print the contents of a directory
void print_dir_contents(char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Unable to open directory %s.\n", path);
        exit(1);
    }

    printf("Contents of directory %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

// function to check if a file exists
int file_exists(char *filename) {
    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

// main function
int main(int argc, char *argv[]) {
    char path[100];
    char file[100];

    if (argc != 3) {
        printf("Usage: %s <directory> <file>\n", argv[0]);
        exit(1);
    }

    // get directory path and file name from command line arguments
    strcpy(path, argv[1]);
    strcpy(file, argv[2]);

    // check if directory exists
    if (!file_exists(path)) {
        printf("Directory %s does not exist.\n", path);
        exit(1);
    }

    // print contents of directory
    print_dir_contents(path);

    // check if file exists in directory
    if (file_exists(strcat(path, file))) {
        printf("File %s exists in directory %s.\n", file, argv[1]);
    } else {
        printf("File %s does not exist in directory %s.\n", file, argv[1]);
    }

    return 0;
}