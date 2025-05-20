//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LENGTH 10

struct Process
{
    char pid[MAX_PID_LENGTH];
    char name[255];
    char state[255];
    char user[255];
};

void printProcess(struct Process process)
{
    printf("| %s | %-20s | %-10s | %-10s |\n", process.pid, process.name, process.user, process.state);
}

int main()
{
    DIR* procDir;
    struct dirent* dirEntry;
    char procFilepath[256];
    char pid[MAX_PID_LENGTH];
    char name[255];
    char state[255];
    char user[255];
    struct Process processes[100];
    int processCount = 0;
    FILE* procFile;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* token;
    const char* delim = " ";

    // Open /proc directory.
    procDir = opendir("/proc");
    if (procDir==NULL)
    {
        printf("Error opening /proc directory\n");
        return -1;
    }

    // Print header.
    printf("| PID       | NAME                 | USER      | STATE     |\n");
    printf("|-----------|----------------------|-----------|-----------|\n");

    // Go through all entries in /proc directory.
    while ((dirEntry = readdir(procDir)) != NULL)
    {
        // If entry is not a directory, skip it.
        if (dirEntry->d_type != DT_DIR)
        {
            continue;
        }

        // If entry is not a number, skip it.
        if (!isdigit(dirEntry->d_name[0]))
        {
            continue;
        }

        // Build filepath to /proc/[pid]/stat file.
        sprintf(procFilepath, "/proc/%s/stat", dirEntry->d_name);

        // Open /proc/[pid]/stat file.
        procFile = fopen(procFilepath, "r");
        if (procFile == NULL)
        {
            continue;
        }

        // Parse /proc/[pid]/stat file.
        if ((read = getline(&line, &len, procFile)) != -1)
        {
            // Get pid.
            token = strtok(line, delim);
            strncpy(pid, token, MAX_PID_LENGTH);

            // Get name.
            token = strtok(NULL, delim);
            strncpy(name, token + 1, strlen(token) - 2);

            // Get state.
            int i = 0;
            while (i < 2)
            {
                token = strtok(NULL, delim);
                i++;
            }
            strncpy(state, token, strlen(token));

            // Get user.
            i = 0;
            while (i < 4)
            {
                token = strtok(NULL, delim);
                i++;
            }
            strncpy(user, token, strlen(token) - 1);

            // Add process to array of processes.
            struct Process process;
            strncpy(process.pid, pid, MAX_PID_LENGTH);
            strncpy(process.name, name, 255);
            strncpy(process.state, state, 255);
            strncpy(process.user, user, 255);
            processes[processCount] = process;
            processCount++;
        }

        fclose(procFile);
    }

    // Sort array of processes by pid.
    for (int i = 0; i < processCount - 1; i++)
    {
        for (int j = i + 1; j < processCount; j++)
        {
            if (atoi(processes[j].pid) < atoi(processes[i].pid))
            {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print all processes.
    for (int i = 0; i < processCount; i++)
    {
        printProcess(processes[i]);
    }

    // Close /proc directory.
    closedir(procDir);

    if (line)
    {
        free(line);
    }

    return 0;
}