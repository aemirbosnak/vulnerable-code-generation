//FormAI DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * This program synchronizes two specified directories on the local file system.
 * It recursively copies over any missing files and updates any files that have been modified since the last sync.
 * The programs assumes that the two directories have the same directory structure. If a directory
 * is missing in one of the directories, the program continues to the next directory in the tree.
*/

char *src_dir;
char *dst_dir;

void sync_dir(char *src_path, char *dst_path);
void sync_file(char *src_path, char *dst_path);

int main(int argc, char *argv[]) {
    
    // Ensure the correct number of arguments were provided
    if (argc != 3) {
        printf("Usage: ./sync <src_directory> <dst_directory>\n");
        return 1;
    }
    
    src_dir = argv[1];
    dst_dir = argv[2];
    
    // Synchronize the directories recursively
    sync_dir(src_dir, dst_dir);

    printf("Sync Complete!\n");
    
    return 0;
}

/**
 * Synchronize the contents of two directories
 */
void sync_dir(char *src_path, char *dst_path) {

    DIR *dir;
    struct dirent *dir_entry;
    
    // Open the source directory
    dir = opendir(src_path);
    
    if (dir == NULL) {
        printf("Error: Unable to open directory: %s\n", src_path);
        return;
    }

    // Loop through each entry in the directory
    while ((dir_entry = readdir(dir)) != NULL) {
        
        // Ignore directories that start with a dot
        if (dir_entry->d_name[0] == '.') {
            continue;
        }

        // Create the source and destination paths
        char *src_file_path = malloc(strlen(src_path) + strlen(dir_entry->d_name) + 2);
        sprintf(src_file_path, "%s/%s", src_path, dir_entry->d_name);
        
        char *dst_file_path = malloc(strlen(dst_path) + strlen(dir_entry->d_name) + 2);
        sprintf(dst_file_path, "%s/%s", dst_path, dir_entry->d_name);
        
        // Check if the entry is a directory
        if (dir_entry->d_type == DT_DIR) {
            sync_dir(src_file_path, dst_file_path);
        }
        // Otherwise synchronize the file
        else if (dir_entry->d_type == DT_REG) {
            sync_file(src_file_path, dst_file_path);
        }
        
        free(src_file_path);
        free(dst_file_path);
    }
    
    closedir(dir);
}

/**
 * Synchronize a file between two directories
 */
void sync_file(char *src_path, char *dst_path) {

    // Check if the destination file exists
    struct stat src_stat, dst_stat;
    
    if (stat(src_path, &src_stat) != 0) {
        printf("Error: Unable to retrieve file stats: %s\n", src_path);
        return;
    }
    
    if (stat(dst_path, &dst_stat) == 0) {
        // Check if the source file is newer
        if (difftime(src_stat.st_mtime, dst_stat.st_mtime) > 0.0) {
            // Overwrite the destination file with the source file
            if (unlink(dst_path) == 0) {
                if (link(src_path, dst_path) != 0) {
                    printf("Error: Unable to overwrite file: %s\n", dst_path);
                }
            }
            else {
                printf("Error: Unable to delete file: %s\n", dst_path);
            }
        }
    }
    // Otherwise the file does not exist in the destination directory
    else {
        // Copy the file from the source to the destination directory
        if (link(src_path, dst_path) != 0) {
            printf("Error: Unable to copy file: %s\n", dst_path);
        }
    }
}