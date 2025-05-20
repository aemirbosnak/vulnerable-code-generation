//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
//THE PROCESS DETECTIVE
//A Sherlock Holmes style program to investigate running processes 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

//function prototypes 
void list_processes();
void process_details(int pid);
void string_cleaner(char *string);

int main()
{
    printf("Welcome to the Process Detective!\n\n");
    printf("I am Sherlock Holmes, the world's greatest detective.\n\n");
    printf("I have been called in to investigate running processes on your system.\n\n");
    printf("Let's begin...\n\n");

    //list all running processes on system
    list_processes();

    return 0;
}

//function to list all running processes
void list_processes()
{
    DIR *directory; //directory pointer
    struct dirent *entry; //directory entry struct
    directory = opendir("/proc"); //open directory containing running processes

    //iterate over each directory entry
    while ((entry = readdir(directory)) != NULL)
    {
        if (isdigit(*entry->d_name)) //if directory entry name is a number, it is a process ID
        {
            int pid = atoi(entry->d_name); //convert process ID from string to int
            char cmdline[1024]; //string to hold process command line
            snprintf(cmdline, sizeof(cmdline), "/proc/%d/cmdline", pid); //format path string for command line file
            FILE* cmd_file = fopen(cmdline, "r"); //open command line file for reading

            if (cmd_file != NULL) //if file is successfully opened
            {
                char command[1024]; //buffer to hold command line
                fgets(command, sizeof(command), cmd_file); //read command line from file
                fclose(cmd_file); //close file

                string_cleaner(command); //clean up command string

                printf("\nProcess ID: %d\n", pid);
                printf("Process Name: %s\n", command);

                process_details(pid); //get additional process details
            } 
        }
    }

    closedir(directory); //close directory
}

//function to print additional process details
void process_details(int pid)
{
    char status_path[1024];
    snprintf(status_path, sizeof(status_path), "/proc/%d/status", pid); //format path string for status file
    FILE* status_file = fopen(status_path, "r"); //open status file for reading

    if (status_file != NULL) //if file is successfully opened
    {
        char line[1024]; //buffer to hold each line of file
        char name[1024]; //buffer to hold process name
        int ppid; //buffer to hold parent process ID
        int uid; //buffer to hold user ID
        int gid; //buffer to hold group ID

        //iterate over each line of status file
        while (fgets(line, sizeof(line), status_file) != NULL)
        {
            if (strncmp(line, "Name:", 5) == 0) //if line begins with "Name:"
            {
                sscanf(line + 5, "%s", name); //parse process name from line
                string_cleaner(name); //clean up name string

                printf("Process Name (from status file): %s\n", name);
            }
            else if (strncmp(line, "PPid:", 5) == 0) //if line begins with "PPid:"
            {
                sscanf(line + 5, "%d", &ppid); //parse parent process ID from line

                printf("Parent Process ID: %d\n", ppid);
            }
            else if (strncmp(line, "Uid:", 4) == 0) //if line begins with "Uid:"
            {
                sscanf(line + 4, "%*s%d%d", &uid, &gid); //parse user and group IDs from line

                printf("User ID: %d\n", uid);
                printf("Group ID: %d\n", gid);
            }
        }

        fclose(status_file); //close status file
    }
}

//function to remove unwanted characters from strings
void string_cleaner(char *string)
{
    int i, j = 0;
    for (i = 0; i < strlen(string); i++)
    {
        if (isprint(string[i]))
        {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';
}