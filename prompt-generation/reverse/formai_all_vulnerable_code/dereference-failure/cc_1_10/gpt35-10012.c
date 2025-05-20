//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
/*
C File Backup System

This program backs up C source code files by copying them to a designated backup folder.
It uses a modular design with separate functions for file copying, directory checking, and error handling.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256 // maximum length of file and folder names
#define BACKUP_FOLDER "backup" // name of the backup folder

int copy_file(char *filename);
int check_directory();
void print_error(char *message);

int main()
{
    int status = check_directory();
    if (status != 0) {
        print_error("Error: Unable to create backup directory.");
        return 1;
    }
    
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG && strstr(dir->d_name, ".c") != NULL) {
                status = copy_file(dir->d_name);
                if (status != 0) {
                    printf("Error: Unable to backup file %s.\n", dir->d_name);
                }
            }
        }
        closedir(d);
    }
    
    return 0;
}

int copy_file(char *filename)
{
    FILE *source, *backup;
    char source_path[MAX_FILENAME_LENGTH], backup_path[MAX_FILENAME_LENGTH];
    
    snprintf(source_path, MAX_FILENAME_LENGTH, "./%s", filename);
    snprintf(backup_path, MAX_FILENAME_LENGTH, "./%s/%s", BACKUP_FOLDER, filename);
    
    source = fopen(source_path, "r");
    if (source == NULL) {
        return 1;
    }
    
    backup = fopen(backup_path, "w");
    if (backup == NULL) {
        fclose(source);
        return 2;
    }
    
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, backup);
    }
    
    fclose(source);
    fclose(backup);
    
    return 0;
}

int check_directory()
{
    DIR *dir = opendir(BACKUP_FOLDER);
    if (dir) {
        closedir(dir);
        return 0;
    }
    
    int status = mkdir(BACKUP_FOLDER, 0777);
    if (status == 0) {
        return 0;
    } else {
        return 1;
    }
}

void print_error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}