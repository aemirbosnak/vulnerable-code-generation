//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

// File backup system
int main()
{
    // Get the current time
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    // Create a directory for the backup
    char dir_name[100];
    sprintf(dir_name, "backup_%d-%d-%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    mkdir(dir_name, 0755);

    // Open the directory to be backed up
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Loop through the directory and copy each file to the backup directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip hidden files
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Get the file size
        struct stat statbuf;
        stat(entry->d_name, &statbuf);

        // Open the source file
        FILE *src = fopen(entry->d_name, "rb");
        if (src == NULL)
        {
            perror("fopen");
            return EXIT_FAILURE;
        }

        // Open the destination file
        char dest_name[100];
        sprintf(dest_name, "%s/%s", dir_name, entry->d_name);
        FILE *dest = fopen(dest_name, "wb");
        if (dest == NULL)
        {
            perror("fopen");
            return EXIT_FAILURE;
        }

        // Copy the file
        char buf[4096];
        size_t nread;
        while ((nread = fread(buf, 1, sizeof(buf), src)) > 0)
        {
            fwrite(buf, 1, nread, dest);
        }

        // Close the files
        fclose(src);
        fclose(dest);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}