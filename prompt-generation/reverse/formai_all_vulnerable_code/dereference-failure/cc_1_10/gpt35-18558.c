//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void printProcInfo(char* pid)
{
    char path[50];
    sprintf(path, "/proc/%s/status", pid);
    FILE *fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1);
    }

    char line[300];
    int lineCount = 0;
    while(fgets(line, 300, fp) != NULL && lineCount < 17)
    {
        if (lineCount == 0)
            printf("\n Process Name: ");

        if (strstr(line, "Name") != NULL)
            printf("%s", strstr(line, "\t"));

        if (lineCount == 2)
            printf("\n PID: %s", pid);

        if (lineCount == 13)
            printf("\n Memory Usage: %s", strstr(line, "\t"));

        if (lineCount == 14)
            printf("\n State: %s", strstr(line, "\t"));

        if (lineCount == 15)
            printf("\n Priority: %s", strstr(line, "\t"));

        if (lineCount == 16)
            printf("\n Number of Threads: %s", strstr(line, "\t"));

        lineCount++;
    }

    printf("\n");
    fclose(fp);
}

void listProcesses()
{
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir("/proc")) == NULL)
    {
        perror("opendir() error");
        exit(-1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (atoi(entry->d_name) != 0)
            printProcInfo(entry->d_name);
    }

    closedir(dir);
}

int main(void)
{
    printf("List of Processes Running: \n");
    listProcesses();

    return 0;
}