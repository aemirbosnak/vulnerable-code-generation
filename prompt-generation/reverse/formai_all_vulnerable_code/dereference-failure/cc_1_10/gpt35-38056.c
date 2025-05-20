//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void synchronize(char *src_dir_path, char *dest_dir_path);
void copy_file(char *src_path, char *dest_path);
void copy_dir(char *src_path, char *dest_path);

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 0;
    }
    synchronize(argv[1], argv[2]);
    printf("Synchronization complete!\n");
    return 0;
}

void synchronize(char *src_dir_path, char *dest_dir_path) {
    DIR *src_dir = opendir(src_dir_path);
    if(!src_dir) {
        perror("Failed to open source directory");
        return;
    }

    DIR *dest_dir = opendir(dest_dir_path);
    if(!dest_dir) {
        printf("Destination directory does not exist. Creating directory...");
        mkdir(dest_dir_path, 0700);
        dest_dir = opendir(dest_dir_path);
    }

    struct dirent *file;
    char file_src_path[1024];
    char file_dest_path[1024];
    while((file = readdir(src_dir))) {
        if(strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {
            sprintf(file_src_path, "%s/%s", src_dir_path, file->d_name);
            sprintf(file_dest_path, "%s/%s", dest_dir_path, file->d_name);

            struct stat src_stat;
            stat(file_src_path, &src_stat);

            struct stat dest_stat;
            if(stat(file_dest_path, &dest_stat) == 0) {
                if(S_ISDIR(src_stat.st_mode) && S_ISDIR(dest_stat.st_mode)) {
                    // If the file is a directory and already exists in the destination,
                    // synchronize the directories
                    synchronize(file_src_path, file_dest_path);
                } else if(S_ISREG(src_stat.st_mode) && S_ISREG(dest_stat.st_mode)) {
                    // If the file is a regular file and already exists in the destination,
                    // compare modification times and copy file if necessary
                    if(src_stat.st_mtime > dest_stat.st_mtime) {
                        copy_file(file_src_path, file_dest_path);
                    }
                } else {
                    // If the file in the destination is not of the same type as the one
                    // in the source, replace it with the one in the source
                    unlink(file_dest_path);
                    copy_file(file_src_path, file_dest_path);
                }
            } else {
                // If the file does not exist in the destination, create it
                if(S_ISDIR(src_stat.st_mode)) {
                    copy_dir(file_src_path, file_dest_path);
                } else if(S_ISREG(src_stat.st_mode)) {
                    copy_file(file_src_path, file_dest_path);
                } else {
                    printf("Unsupported file type\n");
                }
            }
        }
    }
    closedir(src_dir);
    closedir(dest_dir);
}

void copy_file(char *src_path, char *dest_path) {
    FILE *src_file = fopen(src_path, "r");
    FILE *dest_file = fopen(dest_path, "w");
    if(!src_file) {
        printf("Failed to open source file\n");
        return;
    }
    if(!dest_file) {
        printf("Failed to open destination file\n");
        return;
    }
    char buffer[1024];
    size_t buffer_size;
    while((buffer_size = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, buffer_size, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
}

void copy_dir(char *src_path, char *dest_path) {
    mkdir(dest_path, 0700);
    DIR *src_dir = opendir(src_path);
    struct dirent *file;
    char file_src_path[1024];
    char file_dest_path[1024];
    while((file = readdir(src_dir))) {
        if(strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {
            sprintf(file_src_path, "%s/%s", src_path, file->d_name);
            sprintf(file_dest_path, "%s/%s", dest_path, file->d_name);
            struct stat src_stat;
            stat(file_src_path, &src_stat);
            if(S_ISDIR(src_stat.st_mode)) {
                copy_dir(file_src_path, file_dest_path);
            } else if(S_ISREG(src_stat.st_mode)) {
                copy_file(file_src_path, file_dest_path);
            } else {
                printf("Unsupported file type\n");
            }
        }
    }
    closedir(src_dir);
}