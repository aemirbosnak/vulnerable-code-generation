//FormAI DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int isNumeric(char *str) //function to check if a string is numeric
{
    while(*str)
    {
        if(!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

void printProcessInfo(char *pid) //function to print process info for a particular PID
{
    char filePath[50];
    FILE *file;
    char line[100];
    sprintf(filePath, "/proc/%s/stat", pid); //constructing the path of the stat file for the given PID
    file = fopen(filePath, "r");
    if(file) //if the file is found, parse and print the required process information
    {
        printf("%-10s %-10s %-10s %-10s\n", "PID", "STATE", "PPID", "CMD");
        fgets(line, 100, file);
        char *infoArray[50];
        char *info;
        int i = 0;
        while(i < 50 && (info = strsep(&line, " ")) != NULL)
        {
            infoArray[i] = info;
            i++;
        }
        fclose(file);
        if(i >= 3)
        {
            printf("%-10s %-10s %-10s %-10s\n", infoArray[0], infoArray[2], infoArray[3], infoArray[1]);
        }
    }
}

void printAllProcesses() //function to print info for all running processes
{
    DIR *directory;
    struct dirent *entry;
    directory = opendir("/proc");
    if(directory) //if the directory is found
    {
        printf("%-10s %-10s %-10s %-10s\n", "PID", "STATE", "PPID", "CMD");
        while((entry = readdir(directory)) != NULL) //iterate through each entry in the directory
        {
            if(isNumeric(entry->d_name)) //if the entry is a process ID
            {
                printProcessInfo(entry->d_name); //print the process info for that ID
            }
        }
        closedir(directory);
    }
}

int main(int argc, char *argv[])
{
    char option;
    if(argc == 1) //if no command line arguments are provided, print all running process info
    {
        printAllProcesses();
    }
    else if(argc > 2 || (argc == 2 && strcmp(argv[1], "-p") != 0)) //if invalid command line arguments are provided
    {
        printf("Invalid arguments\n");
        exit(0);
    }
    else //if valid command line arguments are provided
    {
        if(strcmp(argv[1], "-p") == 0) //if the user specifies a PID using the -p option
        {
            printf("%-10s %-10s %-10s %-10s\n", "PID", "STATE", "PPID", "CMD");
            for(int i = 2; i < argc; i++) //iterate through the PIDs provided
            {
                if(isNumeric(argv[i])) //if the provided PID is numeric
                {
                    printProcessInfo(argv[i]); //print the process info for that PID
                }
                else //if the provided PID is not numeric
                {
                    printf("%s is not a valid PID\n", argv[i]); //print an error message
                }
            }
        }
    }
    return 0;
}