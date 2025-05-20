//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void copy_file(char *source_path, char *dest_path)
{
    int source_fd, dest_fd;
    ssize_t num_read;
    char buf[BUF_SIZE];

    source_fd = open(source_path, O_RDONLY);
    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((num_read = read(source_fd, buf, BUF_SIZE)) > 0)
    {
        write(dest_fd, buf, num_read);
    }
    close(source_fd);
    close(dest_fd);
}

void sync_dir(char *source_dir, char *dest_dir)
{
    DIR *d;
    struct dirent *dir;
    struct stat source_stat, dest_stat;
    char source_path[PATH_MAX], dest_path[PATH_MAX];

    if ((d = opendir(source_dir)) != NULL)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (strcmp(dir->d_name, ".") != 0 &&
                strcmp(dir->d_name, "..") != 0)
            {
                sprintf(source_path, "%s/%s", source_dir, dir->d_name);
                sprintf(dest_path, "%s/%s", dest_dir, dir->d_name);
                if (stat(source_path, &source_stat) == 0 &&
                    (stat(dest_path, &dest_stat) != 0 ||
                     source_stat.st_mtime > dest_stat.st_mtime))
                {
                    if (S_ISREG(source_stat.st_mode))
                    {
                        printf("Copying %s to %s\n", source_path, dest_path);
                        copy_file(source_path, dest_path);
                    }
                    else if (S_ISDIR(source_stat.st_mode))
                    {
                        printf("Synchronizing directory %s\n", source_path);
                        mkdir(dest_path, 0755);
                        sync_dir(source_path, dest_path);
                    }
                }
            }
        }
        closedir(d);
    }
    else
    {
        fprintf(stderr, "Cannot open directory %s\n", source_dir);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    sync_dir(argv[1], argv[2]);

    printf("Synchronization complete\n");

    return 0;
}