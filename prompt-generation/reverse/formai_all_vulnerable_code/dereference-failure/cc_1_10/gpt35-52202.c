//FormAI DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUF_SIZE 1024

void copy_file(const char *src_file_path, const char *dest_dir_path)
{
    char dest_file_path[BUF_SIZE];
    char buf[BUF_SIZE];
    size_t n_read;
    FILE *src_file;
    FILE *dest_file;

    sprintf(dest_file_path, "%s/%s", dest_dir_path, src_file_path);
    src_file = fopen(src_file_path, "rb");
    dest_file = fopen(dest_file_path, "wb");
    while ((n_read = fread(buf, 1, BUF_SIZE, src_file)) > 0)
    {
        fwrite(buf, 1, n_read, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);

    printf("%s -> %s\n", src_file_path, dest_file_path);
}

void backup_dir(const char *dir_path, const char *dest_dir_path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char path[BUF_SIZE];

    dir = opendir(dir_path);
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        sprintf(path, "%s/%s", dir_path, entry->d_name);
        stat(path, &statbuf);
        if (S_ISREG(statbuf.st_mode)) // regular file
        {
            copy_file(path, dest_dir_path);
        }
        else if (S_ISDIR(statbuf.st_mode)) // directory
        {
            char dest_subdir_path[BUF_SIZE];
            sprintf(dest_subdir_path, "%s/%s", dest_dir_path, entry->d_name);
            mkdir(dest_subdir_path, 0777);
            backup_dir(path, dest_subdir_path);
        }
    }
    closedir(dir);
}

void backup(char *src_dir_path, char *dest_dir_path)
{
    char timestamp[BUF_SIZE];
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    strftime(timestamp, BUF_SIZE, "%Y%m%d-%H%M%S", tm_now);
    char backup_dir_path[BUF_SIZE];
    sprintf(backup_dir_path, "%s/backup-%s", dest_dir_path, timestamp);
    mkdir(backup_dir_path, 0777);
    backup_dir(src_dir_path, backup_dir_path);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <src_dir_path> <dest_dir_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    backup(argv[1], argv[2]);

    return 0;
}