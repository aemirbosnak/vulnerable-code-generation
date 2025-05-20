//FormAI DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

int copy_file(char* source_path, char* dest_path)
{
    FILE* src_file = fopen(source_path, "rb");
    if(src_file == NULL)
        return -1;

    FILE* dest_file = fopen(dest_path, "wb");
    if(dest_file == NULL)
    {
        fclose(src_file);
        return -1;
    }

    char buffer[1024];
    size_t n;
    while((n = fread(buffer, 1, sizeof buffer, src_file)) != 0)
        fwrite(buffer, 1, n, dest_file);

    fclose(dest_file);
    fclose(src_file);

    return 0;
}

int copy_dir(char* source_path, char* dest_path)
{
    DIR* dp = opendir(source_path);
    if(dp == NULL)
    {
        printf("ERROR: Cannot open directory %s\n", source_path);
        return -1;
    }

    struct dirent* ep;
    struct stat s_buf;
    char dest_file_path[MAX_PATH];
    char source_file_path[MAX_PATH];
    int result = 0;

    while((ep = readdir(dp)) != NULL)
    {
        if(strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
            continue;

        snprintf(source_file_path, MAX_PATH, "%s/%s", source_path, ep->d_name);
        snprintf(dest_file_path, MAX_PATH, "%s/%s", dest_path, ep->d_name);

        if(lstat(source_file_path, &s_buf) != 0)
        {
            printf("ERROR: Cannot stat file %s: %s\n", source_file_path, strerror(errno));
            result = -1;
            continue;
        }

        if(S_ISREG(s_buf.st_mode))
        {
            if(copy_file(source_file_path, dest_file_path) != 0)
            {
                printf("ERROR: Cannot copy file %s to %s\n", source_file_path, dest_file_path);
                result = -1;
            }
        }
        else if(S_ISDIR(s_buf.st_mode))
        {
            if(mkdir(dest_file_path, s_buf.st_mode & ~S_IFDIR) != 0 && errno != EEXIST)
            {
                printf("ERROR: Cannot create directory %s: %s\n", dest_file_path, strerror(errno));
                result = -1;
                continue;
            }

            if(copy_dir(source_file_path, dest_file_path) != 0)
                result = -1;
        }
        else
        {
            printf("WARNING: Unsupported file type for file %s\n", source_file_path);
        }
    }

    closedir(dp);
    return result;
}

int main(int argc, char** argv)
{
    char* source_path = NULL;
    char* dest_path = NULL;

    if(argc == 1)
    {
        printf("Please specify source and destination paths\n");
        return -1;
    }

    source_path = argv[1];
    dest_path = argv[2];

    if(access(source_path, F_OK) != 0)
    {
        printf("Source directory %s does not exist\n", source_path);
        return -1;
    }
    if(access(dest_path, F_OK) != 0)
    {
        printf("Destination directory %s does not exist\n", dest_path);
        return -1;
    }

    printf("Copying directory %s to %s...\n", source_path, dest_path);

    if(copy_dir(source_path, dest_path) == 0)
    {
        printf("Done.\n");
        return 0;
    }
    else
    {
        printf("ERROR: Copy failed.\n");
        return -1;
    }
}