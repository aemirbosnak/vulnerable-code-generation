//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 100

int sync_files(const char *source_dir, const char *destination_dir){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(source_dir);

    if(dir == NULL){
        printf("Error: Unable to open directory.\n");
        return -1;
    }

    while((entry = readdir(dir)) != NULL){
        if(entry->d_type == DT_DIR){
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                continue;
            }

            char new_source_path[MAX_PATH_LENGTH];
            char new_destination_path[MAX_PATH_LENGTH];

            snprintf(new_source_path, MAX_PATH_LENGTH, "%s/%s", source_dir, entry->d_name);
            snprintf(new_destination_path, MAX_PATH_LENGTH, "%s/%s", destination_dir, entry->d_name);

            struct stat st = {0};

            if(stat(new_destination_path, &st) == -1){
                mkdir(new_destination_path, 0700);
            }

            sync_files(new_source_path, new_destination_path);
        } else {
            char source_path[MAX_PATH_LENGTH];
            char destination_path[MAX_PATH_LENGTH];

            snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source_dir, entry->d_name);
            snprintf(destination_path, MAX_PATH_LENGTH, "%s/%s", destination_dir, entry->d_name);

            struct stat source_stat, destination_stat;

            if(stat(source_path, &source_stat) == -1){
                printf("Error: Unable to get file info for %s. Skipping file.\n", source_path);
                continue;
            }

            if(stat(destination_path, &destination_stat) == -1){
                printf("Copying file %s to %s.\n", source_path, destination_path);
                copy_file(source_path, destination_path);

            } else {
                if(source_stat.st_mtime > destination_stat.st_mtime){
                    printf("Updating file %s to %s.\n", source_path, destination_path);
                    copy_file(source_path, destination_path);
                }
            }
        }
    }

    closedir(dir);
    return 0;
}

int copy_file(const char *source_path, const char *destination_path){
    FILE *source_file, *destination_file;

    if((source_file = fopen(source_path, "r")) == NULL){
        return -1;
    }

    if((destination_file = fopen(destination_path, "w")) == NULL){
        return -1;
    }

    char buffer[BUFSIZ];
    size_t size;

    while((size = fread(buffer, 1, BUFSIZ, source_file)) != 0){
        fwrite(buffer, 1, size, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
    return 0;
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("Usage: synchonizer <source> <destination>\n");
        return -1;
    }

    int result = sync_files(argv[1], argv[2]);

    if(result == -1){
        printf("Error: Failed to synchronize files.\n");
        return -1;
    }

    printf("Files have been synchronized.\n");
    return 0;
}