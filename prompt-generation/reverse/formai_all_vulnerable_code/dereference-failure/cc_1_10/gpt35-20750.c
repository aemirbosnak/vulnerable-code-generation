//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    DIR* directory = opendir("/proc");
    if(directory == NULL)
    {
        printf("Cannot open /proc directory\n");
        return 1;
    }

    FILE* file;
    char path[50], line[200];
    struct dirent *directoryEntry;

    printf("This is the Medieval System Process Viewer!\n\n");

    while((directoryEntry = readdir(directory)) != NULL)
    {
        // Check if the directory entry is a number (process ID)
        if(!isdigit(directoryEntry->d_name[0]))
            continue;

        // Open the status file for the process
        sprintf(path, "/proc/%s/status", directoryEntry->d_name);
        file = fopen(path, "r");

        if(file == NULL)
        {
            printf("Cannot open file %s\n", path);
            return 1;
        }

        // Read the contents of the status file for the process
        while(fgets(line, sizeof(line), file))
        {
            // Check if the line starts with "Name:"
            if(strncmp(line, "Name:", 5) == 0)
            {
                char processName[50];
                sscanf(line + 5, "%s", processName);
                printf("Process Name: %s\n", processName);
            }

            // Check if the line starts with "Pid:"
            if(strncmp(line, "Pid:", 4) == 0)
            {
                printf("Process ID: %s\n\n", line + 4);
            }
        }

        fclose(file);
    }

    closedir(directory);

    return 0;
}