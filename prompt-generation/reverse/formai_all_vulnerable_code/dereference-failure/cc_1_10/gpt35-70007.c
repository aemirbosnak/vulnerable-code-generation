//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_LONG_PATH 1024

int is_file_infected(const char* fname)
{
    FILE* fptr;
    unsigned char buffer[1024];

    fptr = fopen(fname,"rb");

    if(fptr == NULL)
    {
        return 0;
    }

    while(fread(buffer,1,sizeof(buffer), fptr) != 0)
    {
        if( buffer[0] == 'v' && buffer[1] == 'i' &&
            buffer[2] == 'r' && buffer[3] == 'u' &&
            buffer[4] == 's')
        {
            fclose(fptr);
            return 1;
        }
    }

    fclose(fptr);

    return 0;
}

void scan_directory(const char* path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;

    char filename[MAX_LONG_PATH];

    dir = opendir(path);
    if (dir == NULL)
    {
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        snprintf(filename, MAX_LONG_PATH, "%s/%s", path, entry->d_name);

        if(stat(filename, &file_info) != 0)
        {
            continue;
        }

        if(S_ISDIR(file_info.st_mode)) 
        {
            if(entry->d_name[0] == '.')
            {
                continue;
            }
            scan_directory(filename);
        }
        else if(S_ISREG(file_info.st_mode))
        {
            if(is_file_infected(filename))
            {
                printf("File %s is infected\n",filename);
            }
        }
    }
    closedir(dir);
}

int main()
{
    char path[MAX_LONG_PATH];
    printf("Enter the path to scan: ");
    scanf("%s", path);

    printf("Scanning %s for viruses...\n", path);
    scan_directory(path);

    printf("Anti-virus scan complete.\n");

    return 0;
}