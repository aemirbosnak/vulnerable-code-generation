//FormAI DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void sync_files(char *path1, char *path2);
void sync_dirs(char *dir1, char *dir2);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <directory 1> <directory 2>\n", argv[0]);
        exit(1);
    }

    sync_dirs(argv[1], argv[2]);

    return 0;
}

void sync_files(char *path1, char *path2)
{
    int fd1, fd2, n1, n2;
    char buf1[1024], buf2[1024];

    fd1 = open(path1, O_RDONLY);
    fd2 = open(path2, O_CREAT | O_WRONLY, 0644);

    while ((n1 = read(fd1, buf1, sizeof(buf1))) > 0)
    {
        n2 = write(fd2, buf1, n1);
        if (n2 != n1)
        {
            printf("Error: could not write to file %s\n", path2);
            exit(1);
        }
    }

    close(fd1);
    close(fd2);
}

void sync_dirs(char *dir1, char *dir2)
{
    DIR *dp1, *dp2;
    struct dirent *de1, *de2;
    struct stat st1, st2;
    char path1[1024], path2[1024];

    if ((dp1 = opendir(dir1)) == NULL)
    {
        printf("Error: could not open directory %s\n", dir1);
        exit(1);
    }

    if ((dp2 = opendir(dir2)) == NULL)
    {
        printf("Error: could not open direcory %s\n", dir2);
        exit(1);
    }

    while ((de1 = readdir(dp1)) != NULL)
    {
        if (strcmp(de1->d_name, ".") == 0 || strcmp(de1->d_name, "..") == 0)
            continue;

        sprintf(path1, "%s/%s", dir1, de1->d_name);
        sprintf(path2, "%s/%s", dir2, de1->d_name);

        if (stat(path1, &st1) == -1)
        {
            printf("Error: could not stat file %s\n", path1);
            exit(1);
        }

        if (stat(path2, &st2) == -1)
        {
            if (S_ISDIR(st1.st_mode))
            {
                mkdir(path2, st1.st_mode);
            }
            else
            {
                sync_files(path1, path2);
            }
        }
        else
        {
            if (S_ISDIR(st1.st_mode))
            {
                sync_dirs(path1, path2);
            }
            else if (st1.st_mtime > st2.st_mtime)
            {
                sync_files(path1, path2);
            }
        }
    }

    while ((de2 = readdir(dp2)) != NULL)
    {
        if (strcmp(de2->d_name, ".") == 0 || strcmp(de2->d_name, "..") == 0)
            continue;

        sprintf(path1, "%s/%s", dir1, de2->d_name);
        sprintf(path2, "%s/%s", dir2, de2->d_name);

        if (stat(path2, &st2) == -1)
        {
            printf("Error: could not stat file %s\n", path2);
            exit(1);
        }

        if (stat(path1, &st1) == -1)
        {
            if (S_ISDIR(st2.st_mode))
            {
                mkdir(path1, st2.st_mode);
            }
            else
            {
                sync_files(path2, path1);
            }
        }
        else
        {
            if (S_ISDIR(st2.st_mode))
            {
                sync_dirs(path2, path1);
            }
            else if (st2.st_mtime > st1.st_mtime)
            {
                sync_files(path2, path1);
            }
        }
    }

    closedir(dp1);
    closedir(dp2);
}