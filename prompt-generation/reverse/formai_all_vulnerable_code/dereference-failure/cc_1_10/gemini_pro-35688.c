//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main()
{
    // Get a list of all processes
    FILE *fp = fopen("/proc", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Iterate over the list of processes
    char line[1024];
    while (fgets(line, sizeof(line), fp))
    {
        // The first word on each line is the process ID
        int pid = atoi(strtok(line, " "));

        // Get the process status
        char status_file[1024];
        snprintf(status_file, sizeof(status_file), "/proc/%d/status", pid);
        FILE *status_fp = fopen(status_file, "r");
        if (status_fp == NULL)
        {
            perror("fopen");
            continue;
        }

        // Read the first line of the status file
        char status_line[1024];
        if (fgets(status_line, sizeof(status_line), status_fp) == NULL)
        {
            perror("fgets");
            fclose(status_fp);
            continue;
        }

        // Parse the first line of the status file
        char *status_fields[] = {
            "Name:",
            "State:",
            "Uid:",
            "Gid:",
            "PPid:",
            "VmSize:",
            "VmRSS:",
            "Threads:",
            "SigQ:",
            "SigPnd:",
        };
        char *status_values[sizeof(status_fields) / sizeof(status_fields[0])];
        for (int i = 0; i < sizeof(status_fields) / sizeof(status_fields[0]); i++)
        {
            status_values[i] = strtok(NULL, " ");
        }

        // Print the process information
        printf("PID: %d\n", pid);
        printf("Name: %s\n", status_values[0]);
        printf("State: %s\n", status_values[1]);
        printf("Uid: %s\n", status_values[2]);
        printf("Gid: %s\n", status_values[3]);
        printf("PPid: %s\n", status_values[4]);
        printf("VmSize: %s\n", status_values[5]);
        printf("VmRSS: %s\n", status_values[6]);
        printf("Threads: %s\n", status_values[7]);
        printf("SigQ: %s\n", status_values[8]);
        printf("SigPnd: %s\n", status_values[9]);

        // Close the status file
        fclose(status_fp);
    }

    // Close the list of processes
    fclose(fp);

    return EXIT_SUCCESS;
}