//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define VIRUS_SIGNATURE "ThisIsAVirus!\n"

void scan_file(char *filepath);
void scan_directory(char *dirpath);

int main(int argc, char **argv)
{
    char *path = NULL;

    // check if a path was provided as argument
    if (argc > 1)
    {
        path = argv[1];
    }
    else
    {
        // prompt user for path to scan
        printf("Enter the path to scan: ");
        fgets(path, MAX_PATH_LENGTH, stdin);

        // remove newline character from input
        path[strcspn(path, "\n")] = 0;
    }

    printf("Scanning path %s...\n", path);
    printf("------------------------------------------\n");

    // check if the path is a file or directory
    DIR *dir;
    dir = opendir(path);

    if (dir == NULL)
    {
        // path is a file
        scan_file(path);
    }
    else
    {
        // path is a directory
        scan_directory(path);
    }

    printf("------------------------------------------\n");
    printf("Scan complete.\n");

    return 0;
}

void scan_file(char *filepath)
{
    FILE *fp = fopen(filepath, "rb");

    // check if file could be opened
    if (fp == NULL)
    {
        printf("Could not open file %s.\n", filepath);
        return;
    }

    char signature[17];
    fread(signature, 1, 16, fp);
    signature[16] = '\0';

    // check if file contains virus signature
    if (strcmp(signature, VIRUS_SIGNATURE) == 0)
    {
        printf("Found virus in file %s.\n", filepath);
    }
    else
    {
        printf("No virus found in file %s.\n", filepath);
    }

    fclose(fp);
}

void scan_directory(char *dirpath)
{
    DIR *dir;
    struct dirent *ent;

    // open directory
    dir = opendir(dirpath);
    if (dir == NULL)
    {
        printf("Could not open directory %s.\n", dirpath);
        return;
    }

    // scan all files in directory
    while ((ent = readdir(dir)) != NULL)
    {
        // ignore "." and ".." directories
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
        {
            continue;
        }

        char filepath[MAX_PATH_LENGTH];
        snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", dirpath, ent->d_name);

        // check if file is a directory
        DIR *subdir = opendir(filepath);
        if (subdir != NULL)
        {
            // file is a directory, scan subdirectory
            closedir(subdir);
            scan_directory(filepath);
        }
        else
        {
            // file is a regular file, scan it
            scan_file(filepath);
        }
    }

    // close directory
    closedir(dir);
}