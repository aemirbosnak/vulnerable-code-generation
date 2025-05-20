//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// Function to copy files from src to dst directory
void copy_file(char *src_file, char *dst_dir)
{
    char *filename = strrchr(src_file, '/');
    char dst_file[strlen(dst_dir) + strlen(filename) + 1];
    sprintf(dst_file, "%s/%s", dst_dir, filename+1);
    char buffer[BUFSIZ];
    FILE *source = fopen(src_file, "rb");
    FILE *dest = fopen(dst_file, "wb");
    size_t n;
    while ((n = fread(buffer, 1, sizeof buffer, source)) > 0)
        fwrite(buffer, 1, n, dest);
    fclose(source);
    fclose(dest);
}

// Function to get current date and time
void get_datetime(char *datetime)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(datetime, "%04d%02d%02d_%02d%02d%02d", 
            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Function to create backup directory with current date and time
void create_backup_dir(char *backup_dir)
{
    char datetime[20];
    get_datetime(datetime);
    sprintf(backup_dir, "backup_%s", datetime);
    mkdir(backup_dir, 0777);
}

// Main function
int main(int argc, char **argv)
{
    char *src_dir = "./files";
    char dst_dir[100];
    create_backup_dir(dst_dir);

    DIR *dir = opendir(src_dir);
    if (dir == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    struct dirent *dir_entry;
    while ((dir_entry = readdir(dir)) != NULL)
    {
        char src_file[strlen(src_dir) + strlen(dir_entry->d_name) + 2];
        sprintf(src_file, "%s/%s", src_dir, dir_entry->d_name);

        struct stat filestat;
        if (stat(src_file, &filestat) < 0)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(filestat.st_mode) != 0)
        {
            copy_file(src_file, dst_dir);
            printf("%s backed up to %s\n", dir_entry->d_name, dst_dir);
        }
    }

    closedir(dir);
    return 0;
}