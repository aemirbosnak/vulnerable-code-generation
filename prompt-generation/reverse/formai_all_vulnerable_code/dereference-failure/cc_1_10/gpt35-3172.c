//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024

/* This function checks if a directory exists or not */
int dir_exists(char *path)
{
    DIR *dir = opendir(path);

    if (dir)
    {
        closedir(dir);
        return 1;
    }
    else
    {
        perror("Directory does not exist");
        return 0;
    }
}

/* This function will create a directory if it does not already exist */
int create_dir(char *path)
{
    if (dir_exists(path) == 0)
    {
        int status;
        status = mkdir(path, S_IRUSR | S_IWUSR | S_IXUSR); /* Set permissions to user read, write and execute */
        if (status != 0)
        {
            perror("Unable to create directory");
            return -1;
        }
    }

    return 0;
}

/* This function checks if a file exists or not */
int file_exists(char *path)
{
    FILE *fp;

    fp = fopen(path, "r");

    if (fp)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        perror("File does not exist");
        return 0;
    }
}

/* This function will copy contents of a file to another file */
int copy_file(char *src, char *dest)
{
    char buffer[MAX_SIZE];
    int in, out;
    size_t nread;

    in = open(src, O_RDONLY);
    if (in == -1)
    {
        perror("Unable to open source file");
        return -1;
    }

    out = open(dest, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (out == -1)
    {
        perror("Unable to create destination file");
        return -1;
    }

    while ((nread = read(in, buffer, MAX_SIZE)) > 0)
    {
        if (write(out, buffer, nread) != nread)
        {
            perror("Unable to write data to destination file");
            return -1;
        }
    }

    if (nread == -1)
    {
        perror("Unable to read data from source file");
        return -1;
    }

    if (close(in) == -1 || close(out) == -1)
    {
        perror("Error closing file descriptors");
        return -1;
    }

    return 0;
}

/* This function will synchronize two directories */
int sync_directories(char *src, char *dest)
{
    DIR *dir;
    struct dirent *entry;
    struct stat st_src, st_dest;
    char src_path[MAX_SIZE], dest_path[MAX_SIZE];
    int ret = 0;

    dir = opendir(src);

    if (!dir)
    {
        perror("Unable to open source directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (stat(src_path, &st_src) == -1)
        {
            perror("Unable to get file information");
            ret = -1;
            continue;
        }

        if (S_ISREG(st_src.st_mode))
        {
            if (stat(dest_path, &st_dest) == -1)
            {
                /* If destination file does not exist, create one and copy contents */
                if (copy_file(src_path, dest_path) == -1)
                {
                    perror("Unable to copy file to destination");
                    ret = -1;
                }
            }
            else
            {
                /* Check if source file has been modified */
                if (st_src.st_mtime > st_dest.st_mtime)
                {
                    if (copy_file(src_path, dest_path) == -1)
                    {
                        perror("Unable to copy file to destination");
                        ret = -1;
                    }
                }
            }
        }
        else if (S_ISDIR(st_src.st_mode))
        {
            /* If subdirectory does not exist in destination, create it */
            if (create_dir(dest_path) == -1)
            {
                perror("Unable to create directory in destination");
                ret = -1;
            }

            /* Recursively sync subdirectories */
            if (sync_directories(src_path, dest_path) == -1)
            {
                perror("Unable to sync subdirectories");
                ret = -1;
            }
        }
    }

    closedir(dir);
    return ret;
}

int main(int argc, char **argv)
{
    char *src, *dest;

    if (argc != 3)
    {
        printf("Usage: %s SOURCE DESTINATION\n", argv[0]);
        return -1;
    }

    src = argv[1];
    dest = argv[2];

    if (dir_exists(src) == 0)
    {
        perror("Source directory does not exist");
        return -1;
    }

    if (dir_exists(dest) == 0)
    {
        /* If destination directory does not exist, create it */
        if (create_dir(dest) == -1)
        {
            perror("Unable to create destination directory");
            return -1;
        }
    }

    if (sync_directories(src, dest) == -1)
    {
        perror("Unable to sync directories");
        return -1;
    }

    printf("Directories synced successfully!\n");
    return 0;
}