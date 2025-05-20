//FormAI DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/* Struct to store Process Details */
struct Process
{
    char name[BUFFER_SIZE];
    int pid;
    char state[BUFFER_SIZE];
    int memory_usage;
};

/* Function to get the total memory usage of the process */
int getMemoryUsage(int pid)
{
    char cmd[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    sprintf(cmd, "cat /proc/%d/status | grep VmRSS | awk '{print $2}'", pid);
    FILE *file = popen(cmd, "r");
    fgets(buffer, BUFFER_SIZE, file);
    int memory_usage = atoi(buffer);
    pclose(file);
    return memory_usage;
}

/* Function to parse and display the process information */
void displayProcessInfo(struct Process process)
{
    printf("%-20s %-10d %-4s %-8d\n", process.name, process.pid, process.state, process.memory_usage);
}

/* Function to get the process information of all running processes */
void getAllProcessInfo()
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/proc");
    printf("%-20s %-10s %-4s %-8s\n", "Process Name", "PID", "State", "Memory Usage (KB)");

    while ((entry = readdir(dir)) != NULL) 
    {
        if (isdigit(*entry->d_name)) 
        {
            char path[BUFFER_SIZE];
            sprintf(path, "/proc/%s/stat", entry->d_name);
            FILE *file = fopen(path, "r");
            if (!file)
                continue;
            char buffer[BUFFER_SIZE];
            fgets(buffer, BUFFER_SIZE, file);
            fclose(file);

            char *token = strtok(buffer, " ");
            char *name = token + strlen(token)+2;
            strncpy(name, name+1, strlen(name)-2);
            char *stat = strtok(NULL, " ");
            if(stat[0] == 'Z')
                continue;
            struct Process process = {0};
            strncpy(process.name, name, strlen(name));
            process.pid = atoi(entry->d_name);
            strncpy(process.state, stat, strlen(stat));
            process.memory_usage = getMemoryUsage(process.pid);
            displayProcessInfo(process);
        }
    }
    closedir(dir);
}

/* Main function to display all process information */
int main()
{
    getAllProcessInfo();
    return 0;
}