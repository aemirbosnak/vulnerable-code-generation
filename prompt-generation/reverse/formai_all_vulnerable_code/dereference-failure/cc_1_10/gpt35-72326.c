//FormAI DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX_PATH 1024

void sync_files(char* src_dir, char* dest_dir) {
    DIR* src_ptr = opendir(src_dir);
    DIR* dest_ptr = opendir(dest_dir);
    struct dirent *entry;
    struct stat st_src, st_dest;
    char src_path[MAX_PATH], dest_path[MAX_PATH];

    while(entry = readdir(src_ptr)) {
        strcpy(src_path, src_dir);
        strcat(src_path, "/");
        strcat(src_path, entry->d_name);
        strcpy(dest_path, dest_dir);
        strcat(dest_path, "/");
        strcat(dest_path, entry->d_name);

        if(stat(src_path, &st_src) < 0) {
            printf("Could not read file attributes of '%s'\n", src_path);
            continue;
        }

        if(stat(dest_path, &st_dest) < 0) {
            if(errno == ENOENT) {
                // File does not exist in destination folder, copy it over
                char command[2*MAX_PATH + 10];
                snprintf(command, sizeof(command), "cp %s %s", src_path, dest_path);
                system(command);
                printf("Copied file '%s' to '%s'!\n", src_path, dest_path);
            } else {
                printf("Could not read file attributes of '%s'\n", dest_path);
                continue;
            }
        } else {
            if(st_src.st_mtime > st_dest.st_mtime) {
                // Source file is more recent, copy it over
                char command[2*MAX_PATH + 10];
                snprintf(command, sizeof(command), "cp %s %s", src_path, dest_path);
                system(command);
                printf("Updated file '%s' in '%s'!\n", src_path, dest_dir);
            }
        }

        // If source file is a directory, sync it's files also
        if(S_ISDIR(st_src.st_mode) && strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
            char subdir[MAX_PATH];
            strcpy(subdir, src_path);
            sync_files(subdir, dest_path);
        }
    }
    closedir(src_ptr);
    closedir(dest_ptr);
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("USAGE: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }
    char* src_dir = argv[1];
    char* dest_dir = argv[2];
    printf("Starting synchronization of %s with %s...\n", src_dir, dest_dir);
    sync_files(src_dir, dest_dir);
    printf("Synchronization completed!\n");
    return 0;
}