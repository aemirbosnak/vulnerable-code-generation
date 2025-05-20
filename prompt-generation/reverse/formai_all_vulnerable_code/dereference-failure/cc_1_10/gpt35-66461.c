//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    
#include <dirent.h>    
#include <unistd.h>    
#include <errno.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <time.h>      

void synchronize(char *src_dir, char *dest_dir) {
    DIR *src_dp = opendir(src_dir);
    DIR *dest_dp = opendir(dest_dir);
    if(src_dp == NULL || dest_dp == NULL) {
        printf("Error: unable to open specified directory.\n");
        return;
    }
    else {
        struct dirent *src_entry;
        while((src_entry = readdir(src_dp)) != NULL) {
            if(strcmp(src_entry->d_name, ".") == 0 ||
               strcmp(src_entry->d_name, "..") == 0) 
               continue;
            char src_path[1000];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_entry->d_name);
            char dest_path[1000];
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, src_entry->d_name);
            if(src_entry->d_type == DT_DIR) {
                mkdir(dest_path, 0777);
                synchronize(src_path, dest_path);
            }
            else {
                struct stat src_stat, dest_stat;
                if(stat(src_path, &src_stat) == -1 || 
                   stat(dest_path, &dest_stat) == -1) {
                    printf("Error: unable to get file statistics.\n");
                    return;
                }
                if(difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                    int src_fd = open(src_path, O_RDONLY);
                    int dest_fd = open(dest_path, O_WRONLY|O_TRUNC);
                    if(src_fd == -1 || dest_fd == -1) {
                        printf("Error: unable to open file.\n");
                        return;
                    }
                    else {
                        int bytes_read, bytes_written;
                        char buffer[1000];
                        while((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
                            bytes_written = write(dest_fd, buffer, bytes_read);
                            if(bytes_written != bytes_read) {
                                printf("Error: file write error.\n");
                                return;
                            }
                        }
                        close(src_fd);
                        close(dest_fd);
                        printf("Synchronizing File: %s\n", src_entry->d_name);
                    }
                }
            }
        }
        closedir(src_dp);
        closedir(dest_dp);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 0;
    }
    printf("File Synchronization started.\n");
    synchronize(argv[1], argv[2]);
    printf("File Synchronization complete.\n");
    return 0;
}