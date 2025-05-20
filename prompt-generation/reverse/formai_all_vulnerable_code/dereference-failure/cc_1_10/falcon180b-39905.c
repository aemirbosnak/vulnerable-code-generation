//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_DIR_SIZE 1024

typedef struct
{
    char name[MAX_DIR_SIZE];
    int count;
} Dir;

void read_dir(const char *path, Dir *dir)
{
    DIR *dp;
    struct dirent *dirp;
    struct statvfs buf;

    if ((dp = opendir(path))!= NULL)
    {
        if (statvfs(path, &buf) == 0)
        {
            dir->count = buf.f_blocks;
        }

        while ((dirp = readdir(dp))!= NULL)
        {
            if (strlen(dirp->d_name) < MAX_DIR_SIZE)
            {
                strcpy(dir->name, dirp->d_name);
                dir->count = buf.f_blocks;
            }
        }

        closedir(dp);
    }
}

void print_dir(Dir dir)
{
    printf("%s: %d KB\n", dir.name, dir.count / 1024);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    Dir dir;
    read_dir(argv[1], &dir);
    print_dir(dir);

    return 0;
}