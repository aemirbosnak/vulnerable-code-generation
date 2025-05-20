//FormAI DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256

void synchronize(char *source_dir, char *destination_dir)
{
    DIR *source_dir_ptr, *destination_dir_ptr;
    struct dirent *source_dir_ent, *destination_dir_ent;

    if ((source_dir_ptr = opendir(source_dir)) == NULL)
    {
        printf("Error: unable to open source directory.\n");
        exit(EXIT_FAILURE);
    }

    if ((destination_dir_ptr = opendir(destination_dir)) == NULL)
    {
        printf("Error: unable to open destination directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((source_dir_ent = readdir(source_dir_ptr)) != NULL)
    {
        char source_file[MAX_PATH], destination_file[MAX_PATH];
        struct stat source_stat, destination_stat;

        if (strcmp(source_dir_ent->d_name, ".") == 0 || strcmp(source_dir_ent->d_name, "..") == 0)
        {
            continue;
        }

        sprintf(source_file, "%s/%s", source_dir, source_dir_ent->d_name);
        sprintf(destination_file, "%s/%s", destination_dir, source_dir_ent->d_name);

        if (lstat(source_file, &source_stat) == -1)
        {
            printf("Error: unable to access file %s.\n", source_file);
            exit(EXIT_FAILURE);
        }

        if (lstat(destination_file, &destination_stat) == -1 && !S_ISDIR(source_stat.st_mode))
        {
            printf("Copying file %s to %s\n", source_file, destination_file);
            FILE *source_file_ptr = fopen(source_file, "r");
            FILE *destination_file_ptr = fopen(destination_file, "w");
            int character;

            while ((character = fgetc(source_file_ptr)) != EOF)
            {
                fputc(character, destination_file_ptr);
            }

            fclose(source_file_ptr);
            fclose(destination_file_ptr);
        }
        else if (S_ISDIR(source_stat.st_mode))
        {
            synchronize(source_file, destination_file);
        }
        else if (difftime(source_stat.st_mtime, destination_stat.st_mtime) > 0)
        {
            printf("Updating file %s to %s\n", source_file, destination_file);
            FILE *source_file_ptr = fopen(source_file, "r");
            FILE *destination_file_ptr = fopen(destination_file, "w");
            int character;

            while ((character = fgetc(source_file_ptr)) != EOF)
            {
                fputc(character, destination_file_ptr);
            }

            fclose(source_file_ptr);
            fclose(destination_file_ptr);
        }
    }

    closedir(source_dir_ptr);
    closedir(destination_dir_ptr);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: must provide source and destination directories as arguments.\n");
        exit(EXIT_FAILURE);
    }

    synchronize(argv[1], argv[2]);

    return 0;
}