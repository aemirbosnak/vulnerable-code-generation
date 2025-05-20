//FormAI DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to check if file exists
int file_exists(const char *filename)
{
    struct stat buffer;
    return stat(filename, &buffer) == 0;
}

// Function to create directory
int create_directory(const char *dir)
{
    if (mkdir(dir, 0777) != 0 )
    {
        printf("Error: Failed to create directory\n");
        return -1;
    }
    return 0;
}

// Function to copy file
int copy_file(const char *source, const char *dest)
{
    FILE *source_file = NULL;
    FILE *dest_file = NULL;
    char buffer[BUFFER_SIZE];
    size_t read_size = 0;

    // Check if source file exists
    if (!file_exists(source))
    {
        printf("Error: Source file does not exist\n");
        return -1;
    }

    // Open source file in read mode
    source_file = fopen(source, "rb");
    if (source_file == NULL)
    {
        printf("Error: Failed to open source file\n");
        return -1;
    }

    // Open destination file in write mode
    dest_file = fopen(dest, "wb");
    if (dest_file == NULL)
    {
        printf("Error: Failed to open destination file\n");
        return -1;
    }

    // Copy data from source file to destination file
    while ((read_size = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0)
    {
        fwrite(buffer, 1, read_size, dest_file);
    }

    // Close files
    fclose(source_file);
    fclose(dest_file);

    return 0;
}

// Function to synchronize directory
int synchronize_directory(const char *source, const char *dest)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat file_info;
    char source_path[BUFFER_SIZE] = "";
    char dest_path[BUFFER_SIZE] = "";

    // Check if source directory exists
    if (!file_exists(source))
    {
        printf("Error: Source directory does not exist\n");
        return -1;
    }

    // Create destination directory if it does not exist
    if (!file_exists(dest))
    {
        if (create_directory(dest) != 0)
        {
            return -1;
        }
    }

    // Open source directory
    dir = opendir(source);
    if (dir == NULL)
    {
        printf("Error: Failed to open source directory\n");
        return -1;
    }

    // Loop through source directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // Build source and destination paths
        snprintf(source_path, BUFFER_SIZE, "%s/%s", source, entry->d_name);
        snprintf(dest_path, BUFFER_SIZE, "%s/%s", dest, entry->d_name);

        // Get file information
        stat(source_path, &file_info);

        // Check if entry is a file or a directory
        if (S_ISREG(file_info.st_mode))
        {
            // Copy file to destination if it does not already exist or is different
            if (!file_exists(dest_path) || file_info.st_mtime > file_info.st_mtime)
            {
                printf("Copying %s to %s\n", source_path, dest_path);
                copy_file(source_path, dest_path);
            }
        }
        else if (S_ISDIR(file_info.st_mode))
        {
            // Recursively synchronize subdirectory
            synchronize_directory(source_path, dest_path);
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

// Main function
int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 3)
    {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return -1;
    }

    // Synchronize directories
    if (synchronize_directory(argv[1], argv[2]) == 0)
    {
        printf("Synchronization complete\n");
        return 0;
    }
    else
    {
        printf("Synchronization failed\n");
        return -1;
    }
}