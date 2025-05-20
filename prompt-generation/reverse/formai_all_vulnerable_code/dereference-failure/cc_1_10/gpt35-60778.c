//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
//The case of the Mysteriously Running Processes
//A C program to detect and view active System processes

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

//Main function begins here
int main()
{
    //The stage is set. Let's get to work!
    printf("Welcome to the Case of the Mysteriously Running Processes!\n\n");

    //Create a directory pointer pointing to the "/proc" directory
    DIR *dp = opendir("/proc");

    //If the "/proc" directory cannot be opened, inform the user and exit
    if(dp == NULL)
    {
        printf("Error: Unable to open /proc directory.\n");
        exit(1);
    }

    //Let's get a magnifying glass and examine the contents of the "/proc" directory
    printf("The following processes are currently running:\n\n");
    struct dirent *dirp;

    //Loop through the contents of the "/proc" directory
    while((dirp = readdir(dp)) != NULL)
    {
        //Skip any files that are not directories
        if(!isdigit(*dirp->d_name))
        continue;

        char path[100]; //Create a path variable to hold the path information for each file in the "/proc" directory
        sprintf(path, "/proc/%s/status", dirp->d_name); //Create the full path for each process status file
        
        //Open the process status file
        FILE *fp = fopen(path, "r");

        //If the file cannot be opened, skip to the next file
        if(fp == NULL)
        continue;

        //Read the contents of the process status file and extract the process name and ID
        char line[256];
        char name[256];
        int pid;
        while(fgets(line, sizeof(line), fp))
        {
            if(strncmp(line, "Name:", 5) == 0)
            {
                sscanf(line+6, "%s", name);
            }

            if(strncmp(line, "Pid:", 4) == 0)
            {
                sscanf(line+5, "%d", &pid);
            }
        }

        //Close the process status file
        fclose(fp);

        //Print the process information for the user to see
        printf("Process ID: %d\tName: %s\n", pid, name);
    }

    //Close the "/proc" directory pointer and conclude the case!
    closedir(dp);
    printf("\nThe case is now closed. Thank you for your help.\n");

    return 0;
}