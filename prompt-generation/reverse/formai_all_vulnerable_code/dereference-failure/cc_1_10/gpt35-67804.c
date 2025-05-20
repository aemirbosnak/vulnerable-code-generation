//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc/"

void printProcessInfo(char *pid);
int getProcessCount();
int isNumeric(char *str);

int main() {
    int processCount = getProcessCount();
    DIR *dir;
    struct dirent *entry;
    
    printf("There are %d processes currently running:\n\n", processCount);
    printf("PID\t\tName\t\t\t\tMemory Usage\n");

    // Open the /proc directory
    dir = opendir(PROC_PATH);

    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    // Read all files and directories within the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore all files and directories that are not numeric
        if (isNumeric(entry->d_name)) {
            printProcessInfo(entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}

// function to check if a string is numeric
int isNumeric(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

// function to get the number of currently running processes
int getProcessCount() {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    // Open the /proc directory
    dir = opendir(PROC_PATH);

    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    // Read all files and directories within the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore all files and directories that are not numeric
        if (isNumeric(entry->d_name)) {
            count++;
        }
    }

    closedir(dir);

    return count;
}

// function to print information about a specific process
void printProcessInfo(char *pid) {
    char filename[100], buff[1024], name[100], *memoryUsage;
    FILE *fp;

    // Create the filename for the status file for the given process
    sprintf(filename, "%s%s%s", PROC_PATH, pid, "/status");

    // Open the status file for the given process
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening status file for process %s\n", pid);
        return;
    }

    // Read the process name from the status file
    while (fgets(buff, sizeof(buff), fp)) {
        if (strncmp("Name:", buff, 5) == 0) {
            sscanf(buff, "%*s %s", name);
        }
    }

    // Close the status file
    fclose(fp);

    // Create the filename for the statm file for the given process
    sprintf(filename, "%s%s%s", PROC_PATH, pid, "/statm");

    // Open the statm file for the given process
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening statm file for process %s\n", pid);
        return;
    }

    // Read the memory usage from the statm file
    fgets(buff, sizeof(buff), fp);
    memoryUsage = strtok(buff, " ");

    // Close the statm file
    fclose(fp);

    // Print the process ID, name, and memory usage
    printf("%s\t\t%-20s%s\n", pid, name, memoryUsage);
}