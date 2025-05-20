//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

// define a struct to hold information about files/directories
struct file_info {
    char name[MAX_PATH_LENGTH];
    int is_directory;
    time_t last_modification;
};

// function to get information about a file/directory
void get_file_info(char* path, struct file_info* info) {
    struct stat stat_buf;
    stat(path, &stat_buf);
    strcpy(info->name, path);
    info->is_directory = S_ISDIR(stat_buf.st_mode);
    info->last_modification = stat_buf.st_mtime;
}

// function to check if two file_infos are the same
int same_file_info(struct file_info* info1, struct file_info* info2) {
    if (strcmp(info1->name, info2->name) != 0) return 0;
    if (info1->is_directory != info2->is_directory) return 0;
    if (info1->last_modification != info2->last_modification) return 0;
    return 1;
}

// function to sync two directories
void sync_directories(char* src_dir, char* dest_dir) {
    DIR* src_dp = opendir(src_dir);
    DIR* dest_dp = opendir(dest_dir);
    if (src_dp == NULL || dest_dp == NULL) {
        printf("Could not open directory.\n");
        return;
    }
    struct dirent* src_dirent;
    struct dirent* dest_dirent;
    char src_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];
    while ((src_dirent = readdir(src_dp)) != NULL) {
        // skip . and ..
        if (strcmp(src_dirent->d_name, ".") == 0 || strcmp(src_dirent->d_name, "..") == 0) continue;
        // generate paths for this file/directory in both src and dest directories
        sprintf(src_path, "%s/%s", src_dir, src_dirent->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, src_dirent->d_name);
        // get information for this file/directory in both src and dest directories
        struct file_info src_info;
        struct file_info dest_info;
        get_file_info(src_path, &src_info);
        get_file_info(dest_path, &dest_info);
        // if this file/directory doesn't exist in the dest directory, copy it over
        if (dest_info.name[0] == 0) {
            if (src_info.is_directory) {
                mkdir(dest_path, src_info.last_modification);
            } else {
                char buffer[BUFSIZ];
                size_t size;
                FILE* src_file = fopen(src_path, "r");
                FILE* dest_file = fopen(dest_path, "w");
                while ((size = fread(buffer, 1, BUFSIZ, src_file)) > 0) {
                    fwrite(buffer, 1, size, dest_file);
                }
                fclose(src_file);
                fclose(dest_file);
                chmod(dest_path, src_info.last_modification);
            }
        // if this file/directory exists in the dest directory and is different, update it
        } else if (!same_file_info(&src_info, &dest_info)) {
            if (src_info.is_directory) {
                sync_directories(src_path, dest_path);
            } else {
                char buffer[BUFSIZ];
                size_t size;
                FILE* src_file = fopen(src_path, "r");
                FILE* dest_file = fopen(dest_path, "w");
                while ((size = fread(buffer, 1, BUFSIZ, src_file)) > 0) {
                    fwrite(buffer, 1, size, dest_file);
                }
                fclose(src_file);
                fclose(dest_file);
                chmod(dest_path, src_info.last_modification);
            }
        }
    }
    // delete any files/directories in the dest directory that don't exist in the src directory
    while ((dest_dirent = readdir(dest_dp)) != NULL) {
        // skip . and ..
        if (strcmp(dest_dirent->d_name, ".") == 0 || strcmp(dest_dirent->d_name, "..") == 0) continue;
        // generate path for this file/directory in dest directory
        sprintf(dest_path, "%s/%s", dest_dir, dest_dirent->d_name);
        // get information for this file/directory in dest directory
        struct file_info dest_info;
        get_file_info(dest_path, &dest_info);
        // if this file/directory doesn't exist in the src directory, delete it
        if (dest_info.name[0] != 0) continue;
        if (dest_info.is_directory) {
            rmdir(dest_path);
        } else {
            unlink(dest_path);
        }
    }
    closedir(src_dp);
    closedir(dest_dp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return 1;
    }
    sync_directories(argv[1], argv[2]);
    return 0;
}