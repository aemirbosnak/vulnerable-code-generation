//FormAI DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BUF_SIZE 1024

static volatile int STOP = 0;

void handle_signal(int signal) {
    printf("Interrupt signal received. Stopping synchronizer...\n");
    STOP = 1;
}

int main(int argc, char* argv[]) {
    // Register signal handler for interruption
    signal(SIGINT, handle_signal);
    
    // Check for correct argument count
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return -1;
    }
    
    // Store source and destination directory paths
    char* source_dir = argv[1];
    char* dest_dir = argv[2];
    
    // Create destination directory if it does not already exist
    if (access(dest_dir, F_OK) == -1) {
        printf("Creating destination directory...\n");
        if (mkdir(dest_dir, 0700) == -1) {
            perror("mkdir");
            return -1;
        }
    }
    
    // Traverse source directory and sync files to destination directory
    printf("Synchronizing files...\n");
    DIR* dir = opendir(source_dir);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (STOP) {
            printf("Stopped synchronizer.\n");
            return 0;
        }
        
        char entry_path[MAX_PATH_LENGTH];
        snprintf(entry_path, MAX_PATH_LENGTH, "%s/%s", source_dir, entry->d_name);
        struct stat entry_stat;
        if (stat(entry_path, &entry_stat) == -1) {
            perror("stat");
            return -1;
        }
        
        // Check if entry is a regular file or a directory
        if (S_ISREG(entry_stat.st_mode)) {
            char dest_path[MAX_PATH_LENGTH];
            snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, entry->d_name);
            
            // Check if file already exists in destination directory
            if (access(dest_path, F_OK) == -1) {
                printf("Copying %s to %s...\n", entry_path, dest_dir);
                int source_fd = open(entry_path, O_RDONLY);
                int dest_fd = open(dest_path, O_WRONLY | O_CREAT, entry_stat.st_mode);
                if (source_fd == -1 || dest_fd == -1) {
                    perror("open");
                    return -1;
                }
                
                char buf[MAX_BUF_SIZE];
                ssize_t read_len;
                while ((read_len = read(source_fd, buf, MAX_BUF_SIZE)) > 0) {
                    if (write(dest_fd, buf, read_len) != read_len) {
                        printf("Error copying %s to %s.\n", entry_path, dest_dir);
                        break;
                    }
                }
                
                close(source_fd);
                close(dest_fd);
            }
        } else if (S_ISDIR(entry_stat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char dest_path[MAX_PATH_LENGTH];
            snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, entry->d_name);
            
            // Recursively call the function for directories
            main((int[]){0, 2, 0}, (char*[]){ "", entry_path, dest_path });
        }
    }
    closedir(dir);
    
    printf("Synchronization complete.\n");
    return 0;
}