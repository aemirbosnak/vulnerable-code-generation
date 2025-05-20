//FormAI DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 4096

bool check_directory(char path[MAX_PATH_LEN]) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void copy_file(char source[MAX_PATH_LEN], char destination[MAX_PATH_LEN]) {
    FILE *source_file, *destination_file;
    char ch;

    source_file = fopen(source, "r");
    if(!source_file) {
        printf("Unable to open source file: %s\n", source);
        exit(EXIT_FAILURE);
    }

    destination_file = fopen(destination, "w");
    if(!destination_file) {
        printf("Unable to open destination file: %s\n", destination);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(source_file)) != EOF)
        fputc(ch, destination_file);

    fclose(source_file);
    fclose(destination_file);
}

void synchronize_files(char source_dir[MAX_PATH_LEN], char destination_dir[MAX_PATH_LEN]) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(source_dir);
    if(!dir) {
        printf("Unable to open directory: %s\n", source_dir);
        exit(EXIT_FAILURE);
    }

    while((entry = readdir(dir)) != NULL) {
        char source_path[MAX_PATH_LEN], destination_path[MAX_PATH_LEN];

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(source_path, MAX_PATH_LEN, "%s/%s", source_dir, entry->d_name);
        snprintf(destination_path, MAX_PATH_LEN, "%s/%s", destination_dir, entry->d_name);

        if(check_directory(source_path)) {
            if(!check_directory(destination_path)) {
                // Create the destination directory
                mkdir(destination_path, 0777);
            }
            synchronize_files(source_path, destination_path);
        } else {
            if(access(destination_path, F_OK) == -1) {
                // Destination file does not exist, copy the source file
                copy_file(source_path, destination_path);
            } else {
                // Destination file exists, check if it needs to be updated
                struct stat source_stat, destination_stat;
                stat(source_path, &source_stat);
                stat(destination_path, &destination_stat);
                if(source_stat.st_mtime > destination_stat.st_mtime) {
                    copy_file(source_path, destination_path);
                    printf("Updated file: %s\n", destination_path);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Synchronizer Program!\n");

    if(argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char source_dir[MAX_PATH_LEN], destination_dir[MAX_PATH_LEN];

    realpath(argv[1], source_dir);
    realpath(argv[2], destination_dir);

    if(!check_directory(source_dir)) {
        printf("Not a directory: %s\n", source_dir);
        exit(EXIT_FAILURE);
    }

    if(!check_directory(destination_dir)) {
        printf("Not a directory: %s\n", destination_dir);
        exit(EXIT_FAILURE);
    }

    printf("Synchronizing files...\n");
    synchronize_files(source_dir, destination_dir);
    printf("Done.\n");

    return 0;
}