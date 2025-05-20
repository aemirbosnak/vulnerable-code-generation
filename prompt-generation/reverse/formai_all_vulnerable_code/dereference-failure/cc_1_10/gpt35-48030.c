//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFSIZE 1024

// Function to get file size
int get_file_size(FILE *file) {
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}

// Function to check if a file exists
int exists(char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to copy a file
void copy_file(char *src, char *dst) {
    FILE *fp_src = fopen(src, "rb");
    FILE *fp_dst = fopen(dst, "wb");
    
    // get file size
    int file_size = get_file_size(fp_src);
    
    char buf[BUFSIZE];
    int read_size = 0;
    int total_size = 0;
    
    //copy until EOF
    while ((read_size = fread(buf, 1, BUFSIZE, fp_src)) > 0) {
        fwrite(buf, 1, read_size, fp_dst);
        total_size += read_size;
        
        //check if copied full file
        if(total_size == file_size) break;
    }
    fclose(fp_src);
    fclose(fp_dst);
}

// Function to recursively sync directories
void sync_dir(char *src_dir, char *dst_dir) {
    DIR *dirp_src, *dirp_dst;
    struct dirent *dp_src, *dp_dst;
    char src_path[BUFSIZE], dst_path[BUFSIZE];
    struct stat statbuf_src, statbuf_dst;
    
    //open src and dst directories
    dirp_src = opendir(src_dir);
    if(dirp_src != NULL) {
        dirp_dst = opendir(dst_dir);
        if(dirp_dst != NULL) {
            
            while((dp_src = readdir(dirp_src)) != NULL) {
                
                if(strcmp(dp_src->d_name, ".") != 0 && strcmp(dp_src->d_name, "..") != 0) {
                    
                    // build src and dst paths
                    snprintf(src_path, BUFSIZE, "%s/%s", src_dir, dp_src->d_name);
                    snprintf(dst_path, BUFSIZE, "%s/%s", dst_dir, dp_src->d_name);
                    
                    // get file status
                    lstat(src_path, &statbuf_src);
                    lstat(dst_path, &statbuf_dst);
                    
                    if(S_ISREG(statbuf_src.st_mode)) {
                        // source is a regular file
                        if(!exists(dst_path)) {
                            // target does not exist, copy file
                            printf("Copying file '%s' to '%s'\n", src_path, dst_path);
                            copy_file(src_path, dst_path);
                        }
                        else {
                            // target exists, check if different
                            if(statbuf_src.st_mtime > statbuf_dst.st_mtime) {
                                printf("Updating file '%s'\n", dst_path);
                                copy_file(src_path, dst_path);
                            }
                        }
                    }
                    else if(S_ISDIR(statbuf_src.st_mode)) {
                        // source is a directory
                        if(!exists(dst_path)) {
                            // target does not exist, create directory
                            printf("Creating directory '%s'\n", dst_path);
                            mkdir(dst_path, statbuf_src.st_mode);
                            sync_dir(src_path, dst_path);
                        }
                        else {
                            // target exists, sync directory
                            sync_dir(src_path, dst_path);
                        }
                    }
                }
            }
            
            closedir(dirp_dst);
        }
        else {
            printf("Error: could not open directory '%s'\n", dst_dir);
        }
        
        closedir(dirp_src);
    }
    else {
        printf("Error: could not open directory '%s'\n", src_dir);
    }
}

int main(int argc, char **argv) {
    // check for command line arguments
    if (argc == 3) {
        // get source and destination directories
        char *src_dir = argv[1];
        char *dst_dir = argv[2];
        
        // sync directories recursively
        sync_dir(src_dir, dst_dir);
    }
    else {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}