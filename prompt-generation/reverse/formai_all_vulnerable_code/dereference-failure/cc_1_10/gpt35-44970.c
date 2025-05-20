//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// This function will check if a given string is a valid integer
int isInteger(char *string)
{
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]))
            return 0;
    }

    return 1;
}

// This function will retrieve the command name for a given PID
void getProcessCommand(int pid, char *command)
{
    char path[25];
    sprintf(path, "/proc/%d/cmdline", pid);

    FILE *file = fopen(path, "r");
    fgets(command, 100, file);
    fclose(file);
}

int main()
{
    DIR *directory;
    struct dirent *entry;
    char path[25], command[100];
    int pid, i, count = 0;

    printf(" PID   | COMMAND\n");
    printf("-------|-------------------\n");

    // Open the /proc directory
    directory = opendir("/proc");

    // Loop through each directory entry
    while ((entry = readdir(directory)) != NULL)
    {
        // Check if the entry is a directory and its name is a valid integer
        if (entry->d_type == DT_DIR && isInteger(entry->d_name))
        {
            pid = atoi(entry->d_name);  // Convert directory name to PID

            // Get the command name for the current process
            getProcessCommand(pid, command);

            // Print the PID and command name
            printf("%-7d| %s", pid, command);

            // Increment the process count
            count++;
        }
    }

    printf("\nTotal number of processes: %d\n", count);

    // Close the directory
    closedir(directory);

    return 0;
}