//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 255

void scan_path(char *path);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [path]\n", argv[0]);
        exit(1);
    }
    char *path = argv[1];
    scan_path(path);
    printf("Scan completed.\n");
    return 0;
}

void scan_path(char *path)
{
    DIR *dir;
    struct dirent *ent;
    char file_path[MAX_PATH_LENGTH];
    char command[2*MAX_PATH_LENGTH];
    dir = opendir(path);
    if(!dir)
    {
        printf("Unable to scan directory %s\n", path);
        return;
    }
    while((ent = readdir(dir)) != NULL)
    {
        // Ignore hidden files
        if(ent->d_name[0] == '.')
            continue;
        snprintf(file_path, MAX_PATH_LENGTH, "%s/%s", path, ent->d_name);
        if(ent->d_type == DT_DIR)
        {
            // Recursive call for directories
            scan_path(file_path);
        }
        else if(ent->d_type == DT_REG)
        {
            // Check file for virus using ClamAV command line tool
            snprintf(command, 2*MAX_PATH_LENGTH, "clamscan %s", file_path);
            int status = system(command);
            if(status)
                printf("Virus detected in file %s\n", file_path);
        }
    }
    closedir(dir);
}