//FormAI DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILENAME_LEN 1024

void sync_files(char* source_dir, char* target_dir){
    char source_path[MAX_FILENAME_LEN];
    char target_path[MAX_FILENAME_LEN];
    struct dirent* entry;
    DIR* source_ptr = opendir(source_dir);
    DIR* target_ptr = opendir(target_dir);
    
    //Ensure that the source and target directories are valid
    if(source_ptr == NULL)
        return;
    if(target_ptr == NULL){
        mkdir(target_dir, 0700);
        target_ptr = opendir(target_dir);
    }
    
    //Sync files from the source directory to the target directory
    while((entry = readdir(source_ptr)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(source_path, MAX_FILENAME_LEN, "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, MAX_FILENAME_LEN, "%s/%s", target_dir, entry->d_name);
        struct stat source_stat, target_stat;
        stat(source_path, &source_stat);
        stat(target_path, &target_stat);
        if(S_ISREG(source_stat.st_mode) && (access(target_path, F_OK) == -1 || source_stat.st_mtime > target_stat.st_mtime)){
            int source_fd = open(source_path, O_RDONLY);
            int target_fd = open(target_path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
            char buffer[1024];
            ssize_t count;
            while((count = read(source_fd, buffer, sizeof(buffer))) > 0){
                write(target_fd, buffer, count);
            }
            close(source_fd);
            close(target_fd);
        }
        if(S_ISDIR(source_stat.st_mode)){
            sync_files(source_path, target_path);
        }
    }
    closedir(source_ptr);
    closedir(target_ptr);
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage: %s <source_dir> <target_dir>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    printf("Files synchronized successfully!\n");
    return 0;
}