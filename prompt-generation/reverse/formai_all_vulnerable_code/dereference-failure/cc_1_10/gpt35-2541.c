//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 512
#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

void copy_file(char *src_filename, char *dest_filename) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    // Open the source file for reading
    src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        printf("Error: Unable to open source file %s.\n", src_filename);
        return;
    }
    
    // Open the destination file for writing
    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        printf("Error: Unable to open destination file %s.\n", dest_filename);
        fclose(src_file);
        return;
    }
    
    // Copy the contents of the source file to the destination file
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }
    
    // Close the files
    fclose(src_file);
    fclose(dest_file);
}

void backup_file(char *src_path, char *dest_path, char *filename) {
    char src_filename[MAX_FILENAME];
    char dest_filename[MAX_FILENAME];
    char timestamp[20];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d-%H%M%S", tm);
    
    // Generate the source and destination filenames
    sprintf(src_filename, "%s/%s", src_path, filename);
    sprintf(dest_filename, "%s/%s-%s", dest_path, filename, timestamp);
    
    // Copy the file
    copy_file(src_filename, dest_filename);
}

void backup_directory(char *src_path, char *dest_path) {
    DIR *src_dir;
    struct dirent *entry;
    char filename[MAX_FILENAME];
    
    // Open the source directory for reading
    src_dir = opendir(src_path);
    if (src_dir == NULL) {
        printf("Error: Unable to open source directory %s.\n", src_path);
        return;
    }
    
    // Create the destination directory if it doesn't exist
    if (access(dest_path, F_OK) == -1) {
        mkdir(dest_path, 0777);
    }
    
    // Process each file in the source directory
    while ((entry = readdir(src_dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Backup the file
        backup_file(src_path, dest_path, entry->d_name);
    }
    
    // Close the directory
    closedir(src_dir);
}

int main(int argc, char **argv) {
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];
    
    // Check that the correct number of arguments are present
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }
    
    // Get the source and destination directory paths
    strncpy(src_path, argv[1], MAX_PATH);
    strncpy(dest_path, argv[2], MAX_PATH);
    
    // Backup the directory
    backup_directory(src_path, dest_path);
    
    return 0;
}