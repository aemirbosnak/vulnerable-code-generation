//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 64
#define MAX_FILE_COUNT 100

char* files[MAX_FILE_COUNT];
int file_count = 0;

int sync_files(char* source_directory, char* destination_directory) {
    DIR* source_dir = opendir(source_directory);
    if (source_dir == NULL) {
        printf("Error opening source directory.\n");
        return -1;
    }

    DIR* destination_dir = opendir(destination_directory);
    if (destination_dir == NULL) {
        mkdir(destination_directory, 0700);
        destination_dir = opendir(destination_directory);
    }

    struct dirent* file;

    while ((file = readdir(source_dir)) != NULL) {
        if (file->d_type == DT_REG) {
            char source_file[MAX_PATH_LENGTH];
            sprintf(source_file, "%s/%s", source_directory, file->d_name);

            char destination_file[MAX_PATH_LENGTH];
            sprintf(destination_file, "%s/%s", destination_directory, file->d_name);

            files[file_count++] = strdup(destination_file);

            struct stat source_file_info, destination_file_info;
            stat(source_file, &source_file_info);
            stat(destination_file, &destination_file_info);

            if (source_file_info.st_mtime > destination_file_info.st_mtime) {
                FILE* source = fopen(source_file, "rb");
                FILE* destination = fopen(destination_file, "wb");

                char buffer[1024];
                size_t bytes_read;

                while ((bytes_read = fread(buffer, 1, sizeof(buffer), source))) {
                    fwrite(buffer, 1, bytes_read, destination);
                }

                fclose(source);
                fclose(destination);
            }
        }
    }

    closedir(source_dir);

    for (int i = 0; i < file_count; i++) {
        char destination_file[MAX_PATH_LENGTH];
        sprintf(destination_file, "%s", files[i]);

        if (access(destination_file, F_OK) != 0) {
            char directory[MAX_PATH_LENGTH];
            char* filename = strrchr(destination_file, '/');
            *filename = '\0';
            sprintf(directory, "%s", destination_file);
            *filename = '/';

            mkdir(directory, 0700);
        }
    }

    for (int i = 0; i < file_count; i++) {
        char source_file[MAX_PATH_LENGTH];
        sprintf(source_file, "%s", files[i]);

        char destination_file[MAX_PATH_LENGTH];
        sprintf(destination_file, "%s/%s", destination_directory, strrchr(files[i], '/') + 1);

        struct stat source_file_info, destination_file_info;
        stat(source_file, &source_file_info);
        stat(destination_file, &destination_file_info);

        if (source_file_info.st_mtime > destination_file_info.st_mtime) {
            FILE* source = fopen(source_file, "rb");
            FILE* destination = fopen(destination_file, "wb");

            char buffer[1024];
            size_t bytes_read;

            while ((bytes_read = fread(buffer, 1, sizeof(buffer), source))) {
                fwrite(buffer, 1, bytes_read, destination);
            }

            fclose(source);
            fclose(destination);
        }
    }

    closedir(destination_dir);

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return -1;
    }

    if (sync_files(argv[1], argv[2]) == 0) {
        printf("Files synchronized successfully.\n");
    } else {
        printf("Files failed to synchronize.\n");
    }

    return 0;
}