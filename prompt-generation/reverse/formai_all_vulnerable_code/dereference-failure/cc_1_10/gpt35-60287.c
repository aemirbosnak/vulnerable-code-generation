//FormAI DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>

//function prototypes
void sync_dirs(char *dir1, char *dir2, char *log_file);
void sync_files(char *file1, char *file2);

int main(int argc, char *argv[])
{
    //check if enough arguments are passed
    if(argc < 3)
    {
        printf("Insufficient arguments!\nUsage: %s <directory1> <directory2> [<log_file>]\n", argv[0]);
        exit(1);
    }

    //if a log file is specified
    if(argc == 4)
        sync_dirs(argv[1], argv[2], argv[3]);
    else
        sync_dirs(argv[1], argv[2], NULL);

    return 0;
}

//function to sync directories recursively
void sync_dirs(char *dir1, char *dir2, char *log_file)
{
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);

    if(d1 == NULL || d2 == NULL)
    {
        printf("Error opening directories!\n");
        exit(1);
    }

    struct dirent *entry1;
    struct dirent *entry2;
    struct stat fstat1, fstat2;

    while((entry1 = readdir(d1)) != NULL)
    {
        //skip special directories
        if(strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0)
            continue;

        char *file1 = malloc(strlen(dir1) + strlen(entry1->d_name) + 2);
        sprintf(file1, "%s/%s", dir1, entry1->d_name);

        //get stats of file in directory 1
        if(stat(file1, &fstat1) == -1)
        {
            printf("Error getting file stats!\n");
            exit(1);
        }

        //check if file is directory or file
        if(S_ISDIR(fstat1.st_mode))
        {
            //check if directory exists in directory 2
            char *file2 = malloc(strlen(dir2) + strlen(entry1->d_name) + 2);
            sprintf(file2, "%s/%s", dir2, entry1->d_name);

            if(stat(file2, &fstat2) == -1)
            {
                //create directory in directory 2
                mkdir(file2, fstat1.st_mode);
                free(file2);
            }
            else
                free(file2);

            //recursively sync directories
            sync_dirs(file1, file2, log_file);
        }
        else
        {
            //check if file exists in directory 2
            char *file2 = malloc(strlen(dir2) + strlen(entry1->d_name) + 2);
            sprintf(file2, "%s/%s", dir2, entry1->d_name);

            if(stat(file2, &fstat2) == -1)
            {
                //copy file from directory 1 to directory 2
                sync_files(file1, file2);

                //log the file sync operation
                if(log_file != NULL)
                {
                    FILE *log = fopen(log_file, "a");
                    fprintf(log, "Created %s\n", file2);
                    fclose(log);
                }

                free(file2);
            }
            else
            {
                if(fstat1.st_mtime > fstat2.st_mtime)
                {
                    //sync file from directory 1 to directory 2
                    sync_files(file1, file2);

                    //log the file sync operation
                    if(log_file != NULL)
                    {
                        FILE *log = fopen(log_file, "a");
                        fprintf(log, "Updated %s\n", file2);
                        fclose(log);
                    }
                }

                free(file2);
            }
        }

        free(file1);
    }

    //check for any files in directory 2 that are not in directory 1
    while((entry2 = readdir(d2)) != NULL)
    {
        //skip special directories
        if(strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0)
            continue;

        char *file2 = malloc(strlen(dir2) + strlen(entry2->d_name) + 2);
        sprintf(file2, "%s/%s", dir2, entry2->d_name);

        //get stats of file in directory 2
        if(stat(file2, &fstat2) == -1)
        {
            printf("Error getting file stats!\n");
            exit(1);
        }

        //check if file is directory or file
        if(S_ISDIR(fstat2.st_mode))
        {
            //check if directory exists in directory 1
            char *file1 = malloc(strlen(dir1) + strlen(entry2->d_name) + 2);
            sprintf(file1, "%s/%s", dir1, entry2->d_name);

            if(stat(file1, &fstat1) == -1)
            {
                //create directory in directory 1
                mkdir(file1, fstat2.st_mode);
                free(file1);
            }
            else
                free(file1);

            //recursively sync directories
            sync_dirs(file1, file2, log_file);
        }
        else
        {
            //check if file exists in directory 1
            char *file1 = malloc(strlen(dir1) + strlen(entry2->d_name) + 2);
            sprintf(file1, "%s/%s", dir1, entry2->d_name);

            if(stat(file1, &fstat1) == -1)
            {
                //copy file from directory 2 to directory 1
                sync_files(file2, file1);

                //log the file sync operation
                if(log_file != NULL)
                {
                    FILE *log = fopen(log_file, "a");
                    fprintf(log, "Created %s\n", file1);
                    fclose(log);
                }

                free(file1);
            }

            free(file2);
        }
    }

    closedir(d1);
    closedir(d2);
}

//function to sync files
void sync_files(char *file1, char *file2)
{
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "w");

    if(f1 == NULL || f2 == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }

    //read contents of file 1 and write to file 2
    int c;
    while((c = fgetc(f1)) != EOF)
        fputc(c, f2);

    fclose(f1);
    fclose(f2);

    //set file permissions of file 2 to match file 1
    struct stat fstat;
    if(stat(file1, &fstat) == -1)
    {
        printf("Error getting file stats!\n");
        exit(1);
    }

    chmod(file2, fstat.st_mode);
}