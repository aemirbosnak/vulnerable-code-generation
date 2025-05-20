//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BLOCK_SIZE 4096

// Structure to hold file information
typedef struct FileInfo {
    char path[MAX_PATH];
    long size;
    struct FileInfo *next;
} FileInfo;

// Function to create a new FileInfo node
FileInfo* create_file_info(const char* path, long size) {
    FileInfo *new_file = (FileInfo*)malloc(sizeof(FileInfo));
    if (new_file == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(new_file->path, path, MAX_PATH);
    new_file->size = size;
    new_file->next = NULL;
    return new_file;
}

// Function to calculate total size and number of files
void traverse_directory(const char *dir_path, FileInfo **file_list, long *total_size, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    
    DIR *directory = opendir(dir_path);
    if (!directory) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        char full_path[MAX_PATH];
        
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) { // If it's a regular file
                *total_size += file_stat.st_size;
                (*file_count)++;
                FileInfo *new_file = create_file_info(full_path, file_stat.st_size);
                new_file->next = *file_list;
                *file_list = new_file;
            } else if (S_ISDIR(file_stat.st_mode)) { // If it's a directory
                traverse_directory(full_path, file_list, total_size, file_count);
            }
        } else {
            perror("Stat failed");
        }
    }

    closedir(directory);
}

// Function to display the file information
void display_files(FileInfo *file_list) {
    printf("File List:\n");
    printf("==========================================\n");
    while (file_list != NULL) {
        printf("%s - %ld bytes\n", file_list->path, file_list->size);
        file_list = file_list->next;
    }
    printf("==========================================\n");
}

// Function to free the FileInfo list
void free_file_info(FileInfo *file_list) {
    while (file_list != NULL) {
        FileInfo *temp = file_list;
        file_list = file_list->next;
        free(temp);
    }
}

// Main function
int main(int argc, char *argv[]) {
    FileInfo *file_list = NULL;
    long total_size = 0;
    int file_count = 0;

    // Check for directory argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start traversing the directory
    traverse_directory(argv[1], &file_list, &total_size, &file_count);

    // Display the results
    printf("Total number of files: %d\n", file_count);
    printf("Total size of files: %ld bytes\n", total_size);
    printf("Average file size: %.2f bytes\n", file_count > 0 ? (double)total_size / file_count : 0);
    
    // Display detailed file list
    display_files(file_list);

    // Free allocated memory
    free_file_info(file_list);
    
    return EXIT_SUCCESS;
}