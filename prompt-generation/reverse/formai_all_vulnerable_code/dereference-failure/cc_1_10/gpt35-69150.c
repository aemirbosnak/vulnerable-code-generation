//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define MEGABYTE 1048576

// Function to calculate the directory size
long int calculate_directory_size(char *dir_name)
{
    DIR *dir = opendir(dir_name);      // Open the specified directory
    struct dirent *entry;              // Struct for storing directory entry information
    struct stat stat_buf;              // Struct for storing file information
    long int size = 0;                 // Variable for storing size of directory
    
    // Check if directory opened successfully
    if (dir == NULL)
    {
        printf("Error opening directory %s", dir_name);
        return 0;
    }

    // Read directory entries and sum up file sizes
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore parent and current directory
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            // Get file information
            char file_path[1000];
            sprintf(file_path, "%s/%s", dir_name, entry->d_name);
            stat(file_path, &stat_buf);

            // Calculate size of file or directory
            if (S_ISDIR(stat_buf.st_mode))
            {
                size += calculate_directory_size(file_path);
            }
            else
            {
                size += stat_buf.st_size;
            }
        }
    }

    // Close the directory and return the calculated size
    closedir(dir);
    return size;
}

// Function to print directory usage
void print_directory_usage(char *dir_name)
{
    // Calculate size of directory
    long int size = calculate_directory_size(dir_name);

    // Print directory usage
    printf("%s Disk Usage: %.2f MB\n", dir_name, (float)size/MEGABYTE);
}

int main(int argc, char *argv[])
{
    // Check if user provided a directory name
    if(argc != 2)
    {
        printf("Usage: %s directory_name", argv[0]);
        return 1;
    }

    // Call function to print directory usage
    print_directory_usage(argv[1]);

    return 0;
}