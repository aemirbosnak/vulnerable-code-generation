//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 256

int main() {
    // Get the current directory
    char current_dir[MAX_PATH_LENGTH];
    getcwd(current_dir, MAX_PATH_LENGTH);

    // Get the list of files and directories in the current directory
    DIR *dirp;
    struct dirent *entry;
    if ((dirp = opendir(current_dir))!= NULL) {
        while ((entry = readdir(dirp))!= NULL) {
            // Process each file and directory
            if (entry->d_type == DT_REG) {
                char file_name[MAX_FILENAME_LENGTH];
                strncpy(file_name, entry->d_name, MAX_FILENAME_LENGTH);
                file_name[MAX_FILENAME_LENGTH - 1] = '\0';

                // Get the size of the file
                struct stat file_stat;
                stat(file_name, &file_stat);

                // Compare the size of the file with the size in the backup directory
                char backup_dir[MAX_PATH_LENGTH];
                strcat(backup_dir, "/backup/");
                strcat(backup_dir, file_name);
                struct stat backup_stat;
                stat(backup_dir, &backup_stat);

                // If the file has changed, copy it to the backup directory
                if (file_stat.st_size!= backup_stat.st_size) {
                    char command[MAX_PATH_LENGTH];
                    sprintf(command, "cp -r %s %s", file_name, backup_dir);
                    system(command);
                }
            }
        }
        closedir(dirp);
    } else {
        perror("opendir");
    }

    // Get the list of files and directories in the backup directory
    char backup_dir[MAX_PATH_LENGTH];
    strcat(backup_dir, "/backup/");
    if ((dirp = opendir(backup_dir))!= NULL) {
        while ((entry = readdir(dirp))!= NULL) {
            // Process each file and directory
            if (entry->d_type == DT_REG) {
                char file_name[MAX_FILENAME_LENGTH];
                strncpy(file_name, entry->d_name, MAX_FILENAME_LENGTH);
                file_name[MAX_FILENAME_LENGTH - 1] = '\0';

                // Get the size of the file
                struct stat file_stat;
                stat(file_name, &file_stat);

                // Compare the size of the file with the size in the current directory
                char current_dir[MAX_PATH_LENGTH];
                strcat(current_dir, "/");
                strcat(current_dir, file_name);
                struct stat current_stat;
                stat(current_dir, &current_stat);

                // If the file has changed, copy it back to the current directory
                if (file_stat.st_size!= current_stat.st_size) {
                    char command[MAX_PATH_LENGTH];
                    sprintf(command, "cp -r %s %s", file_name, current_dir);
                    system(command);
                }
            }
        }
        closedir(dirp);
    } else {
        perror("opendir");
    }

    return 0;
}