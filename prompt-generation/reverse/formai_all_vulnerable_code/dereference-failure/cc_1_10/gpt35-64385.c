//FormAI DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_NAME_LENGTH 256

// Function to synchronize two directories
void sync_directories(const char* source_path, const char* target_path)
{
    DIR* source_dir = opendir(source_path);
    DIR* target_dir = opendir(target_path);
    
    // Check if the directories were successfully opened
    if (source_dir == NULL || target_dir == NULL) {
        printf("Error: Unable to open the source or target directory\n");
        exit(EXIT_FAILURE);
    }
    
    // Synchronize the source directory with the target directory
    struct dirent* source_entry;
    while ((source_entry = readdir(source_dir)) != NULL) {
        // Ignore . and .. directories
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0) {
            continue;
        }
        
        // Construct the paths of the source file and the target file
        char source_file_path[MAX_FILE_NAME_LENGTH];
        char target_file_path[MAX_FILE_NAME_LENGTH];
        snprintf(source_file_path, sizeof(source_file_path), "%s/%s", source_path, source_entry->d_name);
        snprintf(target_file_path, sizeof(target_file_path), "%s/%s", target_path, source_entry->d_name);
        
        struct stat source_file_stat;
        
        // Check if the source file exists
        if (stat(source_file_path, &source_file_stat) < 0) {
            printf("Error: Unable to get file status for %s\n", source_file_path);
            continue;
        }
        
        // Check if the source file is a directory or a regular file
        if (S_ISDIR(source_file_stat.st_mode)) {
            // If the source file is a directory, recursively synchronize the subdirectories
            sync_directories(source_file_path, target_file_path);
        } else if (S_ISREG(source_file_stat.st_mode)) {
            // If the source file is a regular file, synchronize the source file with the target file
            int source_file_fd = open(source_file_path, O_RDONLY);
            int target_file_fd = open(target_file_path, O_WRONLY|O_CREAT|O_TRUNC, 0644);
            if (source_file_fd < 0) {
                printf("Error: Unable to open the source file %s\n", source_file_path);
                continue;
            }
            if (target_file_fd < 0) {
                printf("Error: Unable to open the target file %s\n", target_file_path);
                continue;
            }
            char buffer[BUFFER_SIZE];
            int bytes_read;
            while ((bytes_read = read(source_file_fd, buffer, sizeof(buffer))) > 0) {
                write(target_file_fd, buffer, bytes_read);
            }
            close(source_file_fd);
            close(target_file_fd);
        }
    }
    
    // Close the directories
    closedir(source_dir);
    closedir(target_dir);
}

// Main function
int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: %s <source_directory> <target_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    sync_directories(argv[1], argv[2]);
    printf("Successfully synchronized the directories\n");
    return 0;
}