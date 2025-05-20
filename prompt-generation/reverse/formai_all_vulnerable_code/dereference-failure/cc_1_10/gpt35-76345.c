//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024
#define TIME_BUF_SIZE 80

int sync_files(const char *source_dir, const char *dest_dir)
{
    int ret = 0;
    DIR *s_dir, *d_dir;
    struct dirent *s_file, *d_file;
    struct stat s_stat, d_stat;
    char s_path[MAX_BUF_SIZE], d_path[MAX_BUF_SIZE], timestamp[TIME_BUF_SIZE];
    time_t s_mtime, d_mtime;

    s_dir = opendir(source_dir);
    if (s_dir == NULL)
    {
        printf("Error opening source directory: %s\n", strerror(errno));
        return errno;
    }

    d_dir = opendir(dest_dir);
    if (d_dir == NULL)
    {
        printf("Error opening destination directory: %s\n", strerror(errno));
        return errno;
    }

    printf("Synchronizing files from %s to %s\n", source_dir, dest_dir);

    while ((s_file = readdir(s_dir)) != NULL)
    {
        if (s_file->d_name[0] == '.') // skipping hidden files
            continue;

        // Construct source and destination file paths
        sprintf(s_path, "%s/%s", source_dir, s_file->d_name);
        sprintf(d_path, "%s/%s", dest_dir, s_file->d_name);

        stat(s_path, &s_stat);
        s_mtime = s_stat.st_mtime; // Get source file modification time

        if (stat(d_path, &d_stat) != 0) // Check if file exists on destination directory
        {
            printf("\"%s\" does not exist on destination directory. Copying...\n", s_path);
            sprintf(timestamp, "%ld", s_mtime);
            execl("/bin/cp", "/bin/cp", "-p", s_path, d_path, (char *) 0); // Copy source file to destination
            ret = errno;
        }
        else
        {
            d_mtime = d_stat.st_mtime; // Get destination file modification time

            if (difftime(s_mtime, d_mtime) > 0) // Check if source file is newer than destination file
            {
                printf("\"%s\" is newer than \"%s\". Updating...\n", s_path, d_path);
                sprintf(timestamp, "%ld", s_mtime);
                execl("/bin/cp", "/bin/cp", "-p", s_path, d_path, (char *) 0); // Copy source file to destination
                ret = errno;
            }
        }
    }

    // Check if there are any files in the destination directory that don't exist in the source directory
    while ((d_file = readdir(d_dir)) != NULL)
    {
        if (d_file->d_name[0] == '.') // skipping hidden files
            continue;

        sprintf(d_path, "%s/%s", dest_dir, d_file->d_name);

        if ((s_file = opendir(source_dir)) == NULL) // Check if source directory can be opened
        {
            printf("Error opening source directory: %s\n", strerror(errno));
            return errno;
        }

        // Check if file exists in the source directory
        while ((s_file = readdir(s_file)) != NULL)
        {
            if (s_file->d_name[0] == '.') // skipping hidden files
                continue;

            sprintf(s_path, "%s/%s", source_dir, s_file->d_name);

            if (strcmp(s_file->d_name, d_file->d_name) == 0) // File found in source
                break;
        }

        if (s_file == NULL) // File not found in source
        {
            printf("\"%s\" does not exist on source directory. Deleting...\n", d_path);
            execl("/bin/rm", "/bin/rm", "-f", d_path, (char *) 0); // Delete file from destination
            ret = errno;
        }
    }

    printf("Files synchronized successfully!\n");

    return ret;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    return sync_files(argv[1], argv[2]);
}