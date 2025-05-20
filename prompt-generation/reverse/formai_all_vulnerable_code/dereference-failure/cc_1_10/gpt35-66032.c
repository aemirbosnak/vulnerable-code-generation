//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void synchronize(char *source, char *destination);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./file_sync <source_directory> <destination_directory>\n");
        exit(1);
    }

    char *source = argv[1];
    char *destination = argv[2];

    synchronize(source, destination);

    printf("Code synchronization complete!\n");

    return 0;
}

void synchronize(char *source, char *destination) {
    DIR *dir;
    struct dirent *entry;
    struct stat source_stat, destination_stat;
    int file_exists = 0;

    if (!(dir = opendir(source))) {
        printf("Unable to open directory %s!\n", source);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[1024], destination_path[1024];
        sprintf(source_path, "%s/%s", source, entry->d_name);
        sprintf(destination_path, "%s/%s", destination, entry->d_name);

        if (stat(source_path, &source_stat) == -1) {
            printf("Unable to get information about %s\n", source_path);
            continue;
        }

        if (S_ISDIR(source_stat.st_mode)) {
            mkdir(destination_path, source_stat.st_mode);
            synchronize(source_path, destination_path);
        } else {
            if (stat(destination_path, &destination_stat) == 0) {
                file_exists = 1;

                if (source_stat.st_mtime > destination_stat.st_mtime) {
                    printf("Sending my love, to the destination directory %s!\n", destination_path);
                    FILE *source_file = fopen(source_path, "rb");
                    FILE *destination_file = fopen(destination_path, "wb");

                    if (!source_file) {
                        printf("Unable to open source file %s\n", source_path);
                        continue;
                    }

                    if (!destination_file) {
                        printf("Unable to open destination file %s\n", destination_path);
                        continue;
                    }

                    char buffer[1024];
                    size_t bytes_read = 0;

                    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                        fwrite(buffer, 1, bytes_read, destination_file);
                    }

                    fclose(source_file);
                    fclose(destination_file);
                }
            }

            if (file_exists == 0) {
                printf("Oh, how shall I transfer this file to thee, my love %s?\n", destination_path);
                FILE *source_file = fopen(source_path, "rb");
                FILE *destination_file = fopen(destination_path, "wb");

                if (!source_file) {
                    printf("Unable to open source file %s\n", source_path);
                    continue;
                }

                if (!destination_file) {
                    printf("Unable to open destination file %s\n", destination_path);
                    continue;
                }

                char buffer[1024];
                size_t bytes_read = 0;

                while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                    fwrite(buffer, 1, bytes_read, destination_file);
                }

                fclose(source_file);
                fclose(destination_file);
            }

            file_exists = 0;
        }
    }

    closedir(dir);
}