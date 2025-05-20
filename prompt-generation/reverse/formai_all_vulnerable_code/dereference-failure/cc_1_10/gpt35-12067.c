//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

// Function Declarations
void print_directory_info(char* path, int level);
long long get_directory_size(char* path);

// Entry Point of the Program
int main()
{
    printf("Welcome to Happy Disk Space Analyzer\n\n");
    printf("This program analyses the disk space used by different directories in your C Drive\n\n");

    // Path to C Drive
    char* c_drive_path = "C:";

    // Print Status Message
    printf("Analyzing Disk Space of %s Drive...\n\n", c_drive_path);

    // Call the Directory Info Print Function
    print_directory_info(c_drive_path, 0);

    // Print Program Status
    printf("\n\nDisk Space Analysis Completed Successfully!\n\n");

    return 0;
}

// Function to Print Directory Info
void print_directory_info(char* path, int level)
{
    // Directory Pointer Declaration
    DIR* dir;

    // Directory Entry Pointer Declaration
    struct dirent* entry;

    // Stat Struct Declaration
    struct stat statbuf;

    // Open Directory
    if ((dir = opendir(path)) == NULL)
        return;

    // Loop through all entries of the Directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore Current and Parent Directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build Full File Path
        char full_path[1000];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get File Stats
        stat(full_path, &statbuf);

        // Print Directory Info
        for (int i = 0; i < level; i++)
            printf("  ");
        printf("%s - %lld MB\n", entry->d_name, get_directory_size(full_path)/(1024*1024));

        // Recursive Call for Subdirectories
        if (S_ISDIR(statbuf.st_mode))
        {
            print_directory_info(full_path, level + 1);
        }
    }

    // Close Directory Pointer
    closedir(dir);
}

// Function to Get the Size of a Directory
long long get_directory_size(char* path)
{
    long long size = 0;

    // Directory Pointer Declaration
    DIR* dir;

    // Directory Entry Pointer Declaration
    struct dirent* entry;

    // Stat Struct Declaration
    struct stat statbuf;

    // Open Directory
    if ((dir = opendir(path)) == NULL)
        return 0;

    // Loop through all entries of the Directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore Current and Parent Directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build Full File Path
        char full_path[1000];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get File Stats
        stat(full_path, &statbuf);

        // Check if Entry is a Directory
        if (S_ISDIR(statbuf.st_mode))
        {
            size += get_directory_size(full_path);
        }
        else
        {
            size += statbuf.st_size;
        }
    }

    // Close Directory Pointer
    closedir(dir);

    return size;
}