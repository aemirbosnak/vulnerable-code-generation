//FormAI DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define BUF_SIZE 4096 //set buffer size for file read/write operations

//function to copy file from source to destination, returns 0 on success and -1 on failure
int copy_file(const char *src_file, const char *dst_file){

    char buf[BUF_SIZE]; //create buffer for reading/writing file
    int src_fd, dst_fd, num_read;

    //open source file with read only mode
    src_fd = open(src_file, O_RDONLY);
    if(src_fd == -1){
        printf("Failed to open source file. Error: %s\n", strerror(errno));
        return -1;
    }

    //open destination file with write only mode, if file doesn't exist create one with 0666 permission
    dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(dst_fd == -1){
        printf("Failed to create/overwrite destination file. Error: %s\n", strerror(errno));
        close(src_fd);
        return -1;
    }

    //read from source file and write to destination file, until end of file is reached
    while((num_read = read(src_fd, buf, BUF_SIZE)) > 0){
        if(write(dst_fd, buf, num_read) != num_read){
            printf("Failed to write to destination file. Error: %s\n", strerror(errno));
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }
    //close source and destination files
    close(src_fd);
    close(dst_fd);

    return 0;
}

//function to synchronize two directories, returns 0 on success and -1 on failure
int sync_directories(const char *src_dir, const char *dst_dir){

    DIR *d_src, *d_dst;
    struct dirent *dir_ent_src, *dir_ent_dst;
    struct stat st_src, st_dst;
    char src_file_name[PATH_MAX], dst_file_name[PATH_MAX], src_path[PATH_MAX], dst_path[PATH_MAX];

    //open source directory
    d_src = opendir(src_dir);
    if(d_src == NULL){
        printf("Failed to open source directory. Error: %s\n", strerror(errno));
        return -1;
    }

    //open destination directory
    d_dst = opendir(dst_dir);
    if(d_dst == NULL){
        printf("Failed to open destination directory. Error: %s\n", strerror(errno));
        closedir(d_src);
        return -1;
    }

    //traverse source directory and compare with destination directory
    while((dir_ent_src = readdir(d_src)) != NULL){

        //skip . and .. directories
        if(strcmp(dir_ent_src->d_name, ".") == 0 || strcmp(dir_ent_src->d_name, "..") == 0){
            continue;
        }

        //get the full path name of source file/directory
        snprintf(src_file_name, PATH_MAX, "%s/%s", src_dir, dir_ent_src->d_name);

        //get file status information for source file/directory
        if(stat(src_file_name, &st_src) == -1){
            printf("Failed to get file status information for source file/directory. Error: %s\n", strerror(errno));
            closedir(d_src);
            closedir(d_dst);
            return -1;
        }

        //if source file is a directory, create the directory in the destination directory if it doesn't exist
        if(S_ISDIR(st_src.st_mode)){

            //get the full path name of destination directory
            snprintf(dst_file_name, PATH_MAX, "%s/%s", dst_dir, dir_ent_src->d_name);

            //check if destination directory exists, create it if it doesn't exist
            if(stat(dst_file_name, &st_dst) == -1){
                if(errno == ENOENT){
                    if(mkdir(dst_file_name, st_src.st_mode) == -1){
                        printf("Failed to create destination directory. Error: %s\n", strerror(errno));
                        closedir(d_src);
                        closedir(d_dst);
                        return -1;
                    }
                }
                else{
                    printf("Failed to get file status information for destination directory. Error: %s\n", strerror(errno));
                    closedir(d_src);
                    closedir(d_dst);
                    return -1;
                }
            }

            //recursively synchronize the directories
            if(sync_directories(src_file_name, dst_file_name) == -1){
                closedir(d_src);
                closedir(d_dst);
                return -1;
            }
        }
        //if source file is a regular file, check if the file exists in destination directory and copy if it doesn't exist or if modification time is later than destination file
        else if(S_ISREG(st_src.st_mode)){

            //get the full path name of destination file
            snprintf(dst_file_name, PATH_MAX, "%s/%s", dst_dir, dir_ent_src->d_name);

            //check if destination file exists
            if(stat(dst_file_name, &st_dst) == -1){
                if(errno != ENOENT){
                    printf("Failed to get file status information for destination file. Error: %s\n", strerror(errno));
                    closedir(d_src);
                    closedir(d_dst);
                    return -1;
                }
                //copy source file to destination since it doesn't exist
                if(copy_file(src_file_name, dst_file_name) == -1){
                    closedir(d_src);
                    closedir(d_dst);
                    return -1;
                }
            }
            //if destination file exists, check the modification time
            else{
                //if source file has newer modification time, copy it to destination
                if(st_src.st_mtime > st_dst.st_mtime){
                    if(copy_file(src_file_name, dst_file_name) == -1){
                        closedir(d_src);
                        closedir(d_dst);
                        return -1;
                    }
                }
            }
        }
    }

    //close source and destination directories
    closedir(d_src);
    closedir(d_dst);

    return 0;
}

int main(){

    //source and destination directory paths
    char src_dir[PATH_MAX], dst_dir[PATH_MAX];

    printf("Enter the source directory path: ");
    fgets(src_dir, PATH_MAX, stdin);
    src_dir[strcspn(src_dir, "\n")] = 0; //remove trailing newline from user input

    printf("Enter the destination directory path: ");
    fgets(dst_dir, PATH_MAX, stdin);
    dst_dir[strcspn(dst_dir, "\n")] = 0; //remove trailing newline from user input

    //synchronize the directories
    if(sync_directories(src_dir, dst_dir) == -1){
        printf("Directory synchronization failed.\n");
    }
    else{
        printf("Directory synchronization successful.\n");
    }

    return 0;
}