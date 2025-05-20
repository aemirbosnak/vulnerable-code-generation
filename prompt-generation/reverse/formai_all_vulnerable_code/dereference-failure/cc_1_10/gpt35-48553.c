//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<ctype.h>

//function to calculate size of folder
long long int folderSize(const char *name)
{
    struct stat st;
    long long int size = 0; 
    DIR *dir;
    struct dirent *entry;

    dir = opendir(name);
    if(!dir)
    {
        return -1;
    }

    while((entry = readdir(dir)) != NULL)
    {
        char* path = malloc(strlen(name)+strlen(entry->d_name)+2);
        if(path == NULL)
        {
            return -1;
        }
        sprintf(path,"%s/%s",name,entry->d_name);

        if(stat(path,&st)==-1)
        {
            return -1;
        }
        if(S_ISDIR(st.st_mode))
        {
            if(strcmp(entry->d_name, ".") ==0 || strcmp(entry->d_name, "..")==0)
            {
                continue;
            }
            size += folderSize(path);
            free(path);
        }
        else
        {
            size += st.st_size;
            free(path);
        }
    }
    closedir(dir);
    return size;
}

//function to convert bytes to human readable format
char* formatBytes(long long int bytes)
{
    char *suffix[] = {"B", "KB", "MB", "GB", "TB"};
    char length = sizeof(suffix) / sizeof(suffix[0]);

    long long int base = 1024;
    int i = 0;

    while(bytes >= base && i < length - 1)
    {
        bytes = bytes / base;
        i++;
    }

    char* result = malloc(50 * sizeof(char));

    if(result == NULL)
    {
        return NULL;
    }

    sprintf(result, "%.2f%s", (float)bytes, suffix[i]);

    return result;
}

int main(int argc, char const *argv[])
{
    char *path;

    if(argc == 1)
    {
        path = ".";
    }
    else
    {
        path = argv[1];
    }

    long long int size = folderSize(path);

    if(size == -1)
    {
        printf("Error: Could not find directory or file.\n");
        exit(EXIT_FAILURE);
    }

    if(isatty(fileno(stdout)))
    {
        printf("The total size of %s is %s.\n", path, formatBytes(size));
    }
    else
    {
        printf("%lld", size);
    }

    return 0;
}