//FormAI DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256 // max path length for files/folders 
#define BUF_SIZE 1024 // buffer size for file I/O 

int main(int argc, char *argv[]) {
    if (argc != 3) { // check if correct number of arguments have been provided
        printf("Usage: %s <source dir> <destination dir>\n", argv[0]);
        return 1;
    }

    char *src_path = argv[1]; // source directory path
    char *dest_path = argv[2]; // destination directory path

    DIR *src_dir = opendir(src_path); // open source directory
    DIR *dest_dir = opendir(dest_path); // open destination directory

    if (src_dir == NULL || dest_dir == NULL) { // check if directories were opened successfully
        printf("Error opening directories.\n");
        return 1;
    }

    struct dirent *curr_file; // current file/folder in directory
    struct stat curr_stat; // current file/folder status

    while ((curr_file = readdir(src_dir)) != NULL) { // iterate through files/folders in source directory
        char src_file_path[MAX_PATH_LENGTH]; // path to current file/folder in source directory
        char dest_file_path[MAX_PATH_LENGTH]; // path to current file/folder in destination directory
        if (strcmp(curr_file->d_name, ".") == 0 || strcmp(curr_file->d_name, "..") == 0) {
            continue; // skip "." and ".." folders
        }
        sprintf(src_file_path, "%s/%s", src_path, curr_file->d_name); // create path to current file/folder in source directory
        sprintf(dest_file_path, "%s/%s", dest_path, curr_file->d_name); // create path to current file/folder in destination directory
        if (stat(src_file_path, &curr_stat) == -1) { // get statistics for current file/folder
            printf("Error getting file stats.\n");
            continue; // skip this file/folder and move on to next
        }
        if (S_ISREG(curr_stat.st_mode)) { // if current file is regular file
            FILE *src_file = fopen(src_file_path, "r"); // open source file for reading
            FILE *dest_file = fopen(dest_file_path, "r"); // open destination file for reading
            if (dest_file == NULL || curr_stat.st_mtime > stat(dest_file_path, &curr_stat) || (src_file != NULL && curr_stat.st_mtime > stat(src_file_path, &curr_stat))) { // check if destination file needs updating 
                char buf[BUF_SIZE]; // buffer for file I/O
                FILE *dest_file_new = fopen(dest_file_path, "w"); // open new destination file for writing
                while (fgets(buf, BUF_SIZE, src_file) != NULL) { // read source file line by line
                    fputs(buf, dest_file_new); // write line to destination file
                }
                fclose(dest_file_new); // close destination file
            }
            if (src_file != NULL) {
                fclose(src_file); // close source file
            }
            if (dest_file != NULL) {
                fclose(dest_file); // close destination file
            }
        }
        else if (S_ISDIR(curr_stat.st_mode)) { // if current file is directory
            if (mkdir(dest_file_path, curr_stat.st_mode) != 0) { // create directory in destination directory if it doesn't already exist
                printf("Error creating directory.\n");
            }
            char *src_subdir_path = (char *) malloc(strlen(src_file_path) + 1); // path to current subdirectory in source directory
            char *dest_subdir_path = (char *) malloc(strlen(dest_file_path) + 1); // path to current subdirectory in destination directory
            strcpy(src_subdir_path, src_file_path);
            strcpy(dest_subdir_path, dest_file_path);
            if (mkdir(dest_subdir_path, curr_stat.st_mode) != 0) { // create subdirectory in destination directory if it doesn't already exist
                printf("Error creating subdirectory.\n");
            }
            struct dirent *curr_sub_file; // current file/folder in subdirectory
            DIR *src_subdir = opendir(src_subdir_path); // open subdirectory in source directory
            DIR *dest_subdir = opendir(dest_subdir_path); // open subdirectory in destination directory
            if (src_subdir == NULL || dest_subdir == NULL) { // check if subdirectories were opened successfully
                printf("Error opening subdirectories.\n");
                continue; // skip this subdirectory and move on to next
            }
            while ((curr_sub_file = readdir(src_subdir)) != NULL) { // iterate through files/folders in subdirectory
                char sub_src_file_path[MAX_PATH_LENGTH]; // path to current file/folder in subdirectory in source directory
                char sub_dest_file_path[MAX_PATH_LENGTH]; // path to current file/folder in subdirectory in destination directory
                if (strcmp(curr_sub_file->d_name, ".") == 0 || strcmp(curr_sub_file->d_name, "..") == 0) {
                    continue; // skip "." and ".." folders
                }
                sprintf(sub_src_file_path, "%s/%s", src_subdir_path, curr_sub_file->d_name); // create path to current file/folder in subdirectory in source directory
                sprintf(sub_dest_file_path, "%s/%s", dest_subdir_path, curr_sub_file->d_name); // create path to current file/folder in subdirectory in destination directory
                if (stat(sub_src_file_path, &curr_stat) == -1) { // get statistics for current file/folder
                    printf("Error getting file stats.\n");
                    continue; // skip this file/folder and move on to next
                }
                if (S_ISREG(curr_stat.st_mode)) { // if current file is regular file
                    FILE *src_file = fopen(sub_src_file_path, "r"); // open source file for reading
                    FILE *dest_file = fopen(sub_dest_file_path, "r"); // open destination file for reading
                    if (dest_file == NULL || curr_stat.st_mtime > stat(sub_dest_file_path, &curr_stat) || (src_file != NULL && curr_stat.st_mtime > stat(sub_src_file_path, &curr_stat))) { // check if destination file needs updating 
                        char buf[BUF_SIZE]; // buffer for file I/O
                        FILE *dest_file_new = fopen(sub_dest_file_path, "w"); // open new destination file for writing
                        while (fgets(buf, BUF_SIZE, src_file) != NULL) { // read source file line by line
                            fputs(buf, dest_file_new); // write line to destination file
                        }
                        fclose(dest_file_new); // close destination file
                    }
                    if (src_file != NULL) {
                        fclose(src_file); // close source file
                    }
                    if (dest_file != NULL) {
                        fclose(dest_file); // close destination file
                    }
                }
                else if (S_ISDIR(curr_stat.st_mode)) { // if current file is directory
                    if (mkdir(sub_dest_file_path, curr_stat.st_mode) != 0) { // create subdirectory in destination directory if it doesn't already exist
                        printf("Error creating subdirectory.\n");
                    }
                    // add subdirectory to stack for further processing
                }
            }
            closedir(src_subdir); // close subdirectory in source directory
            closedir(dest_subdir); // close subdirectory in destination directory
        }
    }
    closedir(src_dir); // close source directory
    closedir(dest_dir); // close destination directory
    return 0;
}