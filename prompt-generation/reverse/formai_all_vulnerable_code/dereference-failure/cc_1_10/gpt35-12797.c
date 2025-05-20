//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LEN 256

void backup_directory(char source_dir[MAX_PATH_LEN], char dest_dir[MAX_PATH_LEN]){
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH_LEN], dest_path[MAX_PATH_LEN];
    time_t current_time;
    struct tm *time_info;
    char timestamp[25];
    int err_num;

    // Get current time for directory name
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(timestamp, 25, "%Y-%m-%d_%H-%M-%S", time_info);

    // Create backup directory
    sprintf(dest_path, "%s%s/", dest_dir, timestamp);
    if(mkdir(dest_path, 0777) == -1){
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Traverse source directory and backup files
    if((dir = opendir(source_dir)) != NULL){
        while((entry = readdir(dir)) != NULL){
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                continue;
            }
            sprintf(source_path, "%s%s", source_dir, entry->d_name);
            sprintf(dest_path, "%s%s", dest_dir, timestamp);
            if(entry->d_type == DT_DIR){
                backup_directory(source_path, dest_path);
            }
            else{
                strcat(dest_path, "/");
                strcat(dest_path, entry->d_name);
                if(link(source_path, dest_path) == -1){
                    fprintf(stderr, "Error: %s\n", strerror(errno));
                }
            }
        }
        closedir(dir);
    }
    else{
        err_num = errno;
        fprintf(stderr, "Error: %s\n", strerror(err_num));
        exit(EXIT_FAILURE);
    }
}

int main(){
    char source_dir[MAX_PATH_LEN], dest_dir[MAX_PATH_LEN];

    printf("Enter source directory: ");
    fgets(source_dir, MAX_PATH_LEN, stdin);
    source_dir[strcspn(source_dir, "\n")] = '\0'; // Remove newline character

    printf("Enter destination directory: ");
    fgets(dest_dir, MAX_PATH_LEN, stdin);
    dest_dir[strcspn(dest_dir, "\n")] = '\0'; // Remove newline character

    backup_directory(source_dir, dest_dir);

    printf("Backup complete!\n");

    return 0;
}