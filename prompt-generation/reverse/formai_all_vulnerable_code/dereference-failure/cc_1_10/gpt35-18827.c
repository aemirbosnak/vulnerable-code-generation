//FormAI DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    // Open the "/proc" directory
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL)
    {
        printf("Error: Failed to open /proc directory.\n");
        return 1;
    }

    // Loop through each subdirectory in the "/proc" directory
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL)
    {
        // Check if the current directory name is a number (i.e. a process ID)
        pid_t pid = atoi(entry->d_name);
        if (pid != 0)
        {
            // Open the "status" file for the current process
            char filename[256];
            sprintf(filename, "/proc/%d/status", pid);
            FILE *status_file = fopen(filename, "r");
            if (status_file != NULL)
            {
                // Read the process name from the "Name" field in the "status" file
                char buffer[1024];
                while (fgets(buffer, 1024, status_file))
                {
                    if (strncmp(buffer, "Name:", 5) == 0)
                    {
                        printf("Process name: %s", buffer + 6);
                        break;
                    }
                }

                // Read the process status from the "State" field in the "status" file
                rewind(status_file);
                while (fgets(buffer, 1024, status_file))
                {
                    if (strncmp(buffer, "State:", 6) == 0)
                    {
                        printf("Process state: %s", buffer + 7);
                        break;
                    }
                }

                // Close the "status" file
                fclose(status_file);
            }
        }
    }

    // Close the "/proc" directory
    closedir(proc_dir);

    // Exit the program
    return 0;
}