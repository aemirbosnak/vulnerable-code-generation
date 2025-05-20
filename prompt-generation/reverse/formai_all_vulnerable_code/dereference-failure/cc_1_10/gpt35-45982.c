//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <dirent.h>
#include <string.h>

// Function to check if a given string is numeric or not
int isNumeric(char *str)
{
    // Loop through every character in the string 
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

// Function to print the process information given the process ID
void printProcessInfo(int pid)
{
    char filePath[50];
    sprintf(filePath, "/proc/%d/stat", pid);

    FILE *fp = fopen(filePath, "r");

    if (fp == NULL)
    {
        printf("Error opening process file for PID: %d\n", pid);
        return;
    }

    char name[50], state;
    int ppid, pgrp, session, tty_nr, tpgid, utime, stime, cutime, cstime, priority, nice, num_threads, starttime;

    fscanf(fp, "%d %s %c %d %d %d %d %d %u %u %u %u %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %u", 
           &pid, name, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &utime, &stime, &cutime, &cstime, 
           &priority, &nice, &num_threads, &starttime);

    printf("========================= Process Info for PID: %d =========================\n", pid);
    printf("Name: %s\n", name);
    printf("State: %c\n", state);
    printf("Parent PID: %d\n", ppid);
    printf("Process Group Id: %d\n", pgrp);
    printf("Session Id: %d\n", session);
    printf("Terminal Number: %d\n", tty_nr);
    printf("Task Group Id: %d\n", tpgid);
    printf("User Time: %u\n", utime);
    printf("System Time: %u\n", stime);
    printf("Cumulative User Time: %u\n", cutime);
    printf("Cumulative System Time: %u\n", cstime);
    printf("Priority: %ld\n", priority);
    printf("Nice Value: %ld\n", nice);
    printf("Number of Threads: %d\n", num_threads);
    printf("Process Start Time: %u\n", starttime);

    fclose(fp);
}

int main()
{
    printf("================================= System Process Viewer ==================================\n\n");

    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir("/proc")) == NULL)
    {
        printf("Error opening /proc directory.\n");
        return 1;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        if (isNumeric(dirp->d_name))
        {
            int pid = atoi(dirp->d_name);
            // Print process information
            printProcessInfo(pid);
        }
    }

    closedir(dp);

    return 0;
}