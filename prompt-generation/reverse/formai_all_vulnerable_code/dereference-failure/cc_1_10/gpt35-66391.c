//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void backup_directory(char *source, char *destination);

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: %s source_dir destination_dir\n", argv[0]);
        return -1;
    }

    backup_directory(argv[1], argv[2]);

    return 0;
}

void backup_directory(char *source, char *destination) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char source_path[PATH_MAX];
    char destination_path[PATH_MAX];
    char timestamp[20];
    time_t current_time = time(NULL);
    strftime(timestamp, 20, "%Y%m%d-%H%M%S", localtime(&current_time));

    if((dir = opendir(source)) == NULL) {
        printf("Error opening source directory\n");
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, PATH_MAX, "%s/%s", source, entry->d_name);
        snprintf(destination_path, PATH_MAX, "%s/%s-%s", destination, entry->d_name, timestamp);

        if(lstat(source_path, &file_stat) == -1) {
            printf("Error getting file stats\n");
            continue;
        }

        if(S_ISDIR(file_stat.st_mode)) {
            // This is a directory, so we need to create a new one in the destination directory and copy files recursively
            mkdir(destination_path, S_IRWXU | S_IRWXG | S_IRWXO);
            backup_directory(source_path, destination_path);
        } else {
            // This is a file, so we can just copy it
            FILE *source_file = fopen(source_path, "rb");
            FILE *destination_file = fopen(destination_path, "wb");
            if(source_file == NULL || destination_file == NULL) {
                printf("Error opening file\n");
                continue;
            }

            char buffer[1024];
            size_t bytes_read;
            while((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, bytes_read, destination_file);
            }

            fclose(source_file);
            fclose(destination_file);
        }
    }

    closedir(dir);
}