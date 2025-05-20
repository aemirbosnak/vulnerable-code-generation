//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6 // Max number of digits a PID can have
#define MAX_COMMAND_LENGTH 256 // Max length of command string

// Function to check if a string is numeric
int isNumeric(char *str)
{
    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Function to read the command associated with a PID from /proc/<PID>/cmdline
void getProcessCommand(char *pid, char *command)
{
    FILE *fp;
    char filename[MAX_COMMAND_LENGTH];
    sprintf(filename, "/proc/%s/cmdline", pid);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fgets(command, MAX_COMMAND_LENGTH, fp);
    fclose(fp);
}

// Function to print the header row of the process table
void printHeader()
{
    printf("%-8s %-20s\n", "PID", "COMMAND");
    printf("----------------------------------\n");
}

int main(void)
{
    struct dirent *dirEntry;
    DIR *dir = opendir("/proc"); // Open the /proc directory
    char pid[MAX_PID_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    printHeader();
    if (dir == NULL)
    {
        fprintf(stderr, "Error opening /proc directory\n");
        exit(1);
    }
    while ((dirEntry = readdir(dir)) != NULL) // Iterate over the entries in the /proc directory
    {
        if (isNumeric(dirEntry->d_name)) // Check if the entry is a PID
        {
            strcpy(pid, dirEntry->d_name);
            getProcessCommand(pid, command);
            printf("%-8s %-20s\n", pid, command);
        }
    }
    closedir(dir); // Close the directory
    return 0;
}