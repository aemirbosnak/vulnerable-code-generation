//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void print_size(long int size)
{
    if (size >= GB)
        printf("%.2f GB\n", (float)size/GB);
    else if (size >= MB)
        printf("%.2f MB\n", (float)size/MB);
    else if (size >= KB)
        printf("%.2f KB\n", (float)size/KB);
    else
        printf("%ld bytes\n", size);
}

long int get_dir_size(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *d;
    struct stat st;
    char new_path[1024];
    long int total_size = 0;

    while ((d = readdir(dir)) != NULL)
    {
        if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0)
        {
            sprintf(new_path, "%s/%s", path, d->d_name);
            stat(new_path, &st);

            if (S_ISDIR(st.st_mode))
                total_size += get_dir_size(new_path);
            else
                total_size += st.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

int main()
{
    char path[1024];

    printf("Enter directory path: ");
    scanf("%s", path);

    long int dir_size = get_dir_size(path);

    printf("\nTotal Size: ");
    print_size(dir_size);

    return 0;
}