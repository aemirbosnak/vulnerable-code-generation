//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define KILO_BYTE 1024
#define MEGA_BYTE (1024 * 1024)
#define GIGA_BYTE (1024 * 1024 * 1024)

// Function to print the size of a file in human-readable format
void printSize(long int size)
{
    if(size >= GIGA_BYTE)
        printf("%.2f GB\n", (float)size/GIGA_BYTE);
    else if(size >= MEGA_BYTE)
        printf("%.2f MB\n", (float)size/MEGA_BYTE);
    else if(size >= KILO_BYTE)
        printf("%.2f KB\n", (float)size/KILO_BYTE);
    else
        printf("%ld Bytes\n", size);
}

// Function to recursively traverse the directories to get the size of each file/folder
long int traverseDirectory(char* path)
{
    long int totalSize = 0;     // to store the total size of the directory

    struct dirent *de;      // pointer for directory entry
    struct stat st;         // structure to hold the file stats

    DIR *dr = opendir(path);

    // check if directory is opened successfully or not
    if (dr == NULL)
    {
        fprintf(stderr, "Could not open directory %s\n", path);
        return 0;
    }

    // loop through all the files/folders in the directory
    while ((de = readdir(dr)) != NULL)
    {
        // ignore . and .. directories
        if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
        
        // create the absolute path for the current file/folder
        char filePath[1024];    
        sprintf(filePath, "%s/%s", path, de->d_name);

        // get the stats of the file/folder
        if(stat(filePath, &st) == 0)
        {
            // if it is a directory, traverse it recursively
            if(S_ISDIR(st.st_mode))
                totalSize += traverseDirectory(filePath);  
            else
                totalSize += st.st_size;    // if it is a file, add its size to the totalSize
        }
    }

    closedir(dr);
    printf("%s - ", path);
    printSize(totalSize);
    return totalSize;
}

int main()
{
    char path[1024];    // array to store the path of the directory

    printf("Enter the path of the directory: ");
    scanf("%s", path);

    long int totalSize = traverseDirectory(path);     // get the size of the directory recursively
    printf("Total size of %s - ", path);
    printSize(totalSize);   // print the total size of the directory

    return 0;
}