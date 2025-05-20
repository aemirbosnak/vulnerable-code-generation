//FormAI DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024 // Define maximum size of the path name
#define MAX_FILE_SIZE 1048576 // Define maximum size of the file

void sync_files(char *source, char *destination);
void copy_file(char *source, char *destination);

int main(int argc, char *argv[]) {
    // Check if correct number of arguments present
    if (argc != 3) {
        printf("Usage: ./file_sync <source_directory> <destination_directory>\n");
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}

void sync_files(char *source, char *destination) {
    // Open source directory using DIR* and opendir()
    DIR *source_dir = opendir(source);
    if (!source_dir) {
        printf("Error opening source directory %s: %s\n", source, strerror(errno));
        return;
    }
    
    // Open destination directory using DIR* and opendir()
    DIR *destination_dir = opendir(destination);
    if (!destination_dir) {
        printf("Error opening destination directory %s: %s\n", destination, strerror(errno));
        return;
    }
    
    struct dirent *entry = NULL;
    char source_path[MAX_PATH_LENGTH] = {0};
    char destination_path[MAX_PATH_LENGTH] = {0};
    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_type == DT_REG) { // If the entry is a file
            // Create full source path by concatenating directory and file name using sprintf()
            sprintf(source_path, "%s/%s", source, entry->d_name);
            
            // Create full destination path by concatenating directory and file name using sprintf()
            sprintf(destination_path, "%s/%s", destination, entry->d_name);
            
            // Check if file exists in destination directory using stat() and struct stat
            struct stat st = {0};
            if (stat(destination_path, &st) == 0) {
                // If file already exists, check if same size using st_size
                if (st.st_size != entry->d_reclen) {
                    // If not the same size, copy the file using copy_file()
                    printf("%s is not same size in %s, copying\n", entry->d_name, destination);
                    copy_file(source_path, destination_path);
                    continue;
                }
            } else if (errno != ENOENT) {
                printf("Error getting stats for %s in %s: %s\n", entry->d_name, destination, strerror(errno));
                continue;
            } else {
                printf("%s does not exist in %s, copying\n", entry->d_name, destination);
                copy_file(source_path, destination_path);
                continue;
            }
        } else if (entry->d_type == DT_DIR) { // If the entry is a directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                // Skip current directory and parent directory if encountered
                continue;
            }
            
            // Create full source path by concatenating directory and folder name using sprintf()
            sprintf(source_path, "%s/%s", source, entry->d_name);
            
            // Create full destination path by concatenating directory and folder name using sprintf()
            sprintf(destination_path, "%s/%s", destination, entry->d_name);
            
            // Check if the folder exists in destination directory using access()
            if (access(destination_path, F_OK) == 0) {
                // If folder exists in destination directory, recursively call sync_files() on the subdirectories
                sync_files(source_path, destination_path);
            } else {
                // If folder does not exist in destination directory, create the folder using mkdir()
                if (mkdir(destination_path, 0755) != 0) {
                    printf("Error creating directory %s in %s: %s\n", entry->d_name, destination, strerror(errno));
                    continue;
                }
                // Recursively call sync_files() on the subdirectories
                sync_files(source_path, destination_path);
            }
        }
    }
    // Close the directory pointers using closedir()
    closedir(source_dir);
    closedir(destination_dir);
}

void copy_file(char *source, char *destination) {
    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        printf("Error opening source file %s: %s\n", source, strerror(errno));
        return;
    }
    
    FILE *destination_file = fopen(destination, "wb");
    if (!destination_file) {
        printf("Error opening destination file %s: %s\n", destination, strerror(errno));
        fclose(source_file);
        return;
    }
    
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, destination_file) != bytes_read) {
            printf("Error writing to %s: %s\n", destination, strerror(errno));
            fclose(source_file);
            fclose(destination_file);
            return;
        }
    }
    
    fclose(source_file);
    fclose(destination_file);
}