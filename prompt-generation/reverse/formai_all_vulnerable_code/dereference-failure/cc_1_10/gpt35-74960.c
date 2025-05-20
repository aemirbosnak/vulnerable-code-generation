//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() 
{
    DIR *proc; // A pointer to a directory stream object.
    struct dirent *entry; // A pointer to a structure representing a directory entry.

    // Open proc directory.
    if ((proc = opendir("/proc")) == NULL) 
    {
        fprintf(stderr, "Cannot open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    // Print header
    printf("%-10s%-20s%s\n", "PID", "Command", "Status");

    // Loop through each directory entry in proc
    while ((entry = readdir(proc))) 
    {
        // Skip entries that are not directories or don't have a numeric name.
        if (entry->d_type != DT_DIR || atoi(entry->d_name) == 0)
        {
            continue;
        }

        char status_path[64], cmd_path[64];
        FILE *status_file, *cmd_file;
        char status, cmd[256];

        // Build the paths to the status and cmdline files for this process.
        snprintf(status_path, sizeof(status_path), "/proc/%s/status", entry->d_name);
        snprintf(cmd_path, sizeof(cmd_path), "/proc/%s/cmdline", entry->d_name);

        // Open status file
        if ((status_file = fopen(status_path, "r")) == NULL) 
        {
            continue;
        }

        // Read the status file to get the process state
        fscanf(status_file, "State:\t%c", &status);

        // Close the status file
        fclose(status_file);

        // Open the cmdline file
        if ((cmd_file = fopen(cmd_path, "r")) == NULL) 
        {
            continue;
        }

        // Read the cmdline file to get the process command
        fgets(cmd, sizeof(cmd), cmd_file);

        // Close the cmdline file
        fclose(cmd_file);

        // Print the process information to the console
        printf("%-10s%-20s%c\n", entry->d_name, cmd, status);
    }

    // Close the proc directory
    closedir(proc);

    return EXIT_SUCCESS;
}