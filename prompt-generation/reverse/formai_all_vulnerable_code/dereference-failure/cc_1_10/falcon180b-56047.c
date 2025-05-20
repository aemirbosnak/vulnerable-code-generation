//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int sync_files(char *source_path, char *destination_path)
{
    DIR *d;
    struct dirent *dir;
    char file_name[1024];
    char file_path[1024];

    d = opendir(source_path);
    if (d == NULL)
    {
        fprintf(stderr, "Error: Could not open source directory.\n");
        return 1;
    }

    while ((dir = readdir(d))!= NULL)
    {
        if (dir->d_type == DT_DIR)
        {
            sprintf(file_path, "%s/%s", source_path, dir->d_name);
            sync_files(file_path, destination_path);
        }
        else
        {
            sprintf(file_path, "%s/%s", source_path, dir->d_name);
            sprintf(file_name, "%s/%s", destination_path, dir->d_name);

            FILE *source_file;
            FILE *destination_file;

            source_file = fopen(file_path, "rb");
            if (source_file == NULL)
            {
                fprintf(stderr, "Error: Could not open source file.\n");
                return 1;
            }

            destination_file = fopen(file_name, "wb");
            if (destination_file == NULL)
            {
                fprintf(stderr, "Error: Could not open destination file.\n");
                return 1;
            }

            char buffer[BUFFER_SIZE];
            int bytes_read;

            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0)
            {
                fwrite(buffer, 1, bytes_read, destination_file);
            }

            fclose(source_file);
            fclose(destination_file);
        }
    }

    closedir(d);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    char source_path[1024];
    char destination_path[1024];

    strcpy(source_path, argv[1]);
    strcpy(destination_path, argv[2]);

    sync_files(source_path, destination_path);

    return 0;
}