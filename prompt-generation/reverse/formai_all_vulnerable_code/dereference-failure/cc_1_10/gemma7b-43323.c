//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_NAME_LENGTH 256

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;
    char dir_name[MAX_DIR_NAME_LENGTH];
    long long total_space = 0;
    long long used_space = 0;

    printf("Scanning directories...\n");

    // Iterate over all directories in the current path
    dir = opendir(".");
    if (dir)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            // Skip current and parent directories
            if (entry->d_name[0] == '.' || entry->d_name[0] == '..')
            {
                continue;
            }

            // Get the full path of the directory
            sprintf(dir_name, "./%s", entry->d_name);

            // Get the statistics of the directory
            stat(dir_name, &stat_buf);

            // Add the space used by the directory and its children to the total space used
            used_space += stat_buf.st_size;

            // Add the space used by the directory to the total space used
            total_space += stat_buf.st_size;
        }

        closedir(dir);
    }

    printf("Total space used: %lld bytes\n", total_space);
    printf("Used space: %lld bytes\n", used_space);

    return 0;
}