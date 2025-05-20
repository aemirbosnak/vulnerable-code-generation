//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

void printStat(char *processId)
{
    FILE *filePointer;
    char pathBuffer[25], line[100], *token;
    sprintf(pathBuffer, "/proc/%s/stat", processId);
    if ((filePointer = fopen(pathBuffer, "r")) == NULL)
    {
        printf("Unable to open process %s status file\n", processId);
        return;
    }
    fgets(line, 100, filePointer);
    const int commIndex = 1;
    const int utimeIndex = 13;
    const int stimeIndex = 14;
    const int rssIndex = 23;
    const int stateIndex = 2;
    int counter = 0;
    token = strtok(line, " ");
    while (token != NULL)
    {
        counter++;
        if (counter == commIndex+1)
        {
            printf("Process Name: %s\n", token);
        }
        if (counter == utimeIndex+1)
        {
            printf("Process User Time (in ticks): %s\n", token);
        }
        if (counter == stimeIndex+1)
        {
            printf("Process System Time (in ticks): %s\n", token);
        }
        if (counter == rssIndex+1)
        {
            printf("Resident Set Size (in pages): %s\n", token);
        }
        if (counter == stateIndex+1)
        {
            printf("Process State: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    fclose(filePointer);
}

int main()
{
    DIR *dirPointer;
    struct dirent *dirEntryPointer;
    if ((dirPointer = opendir("/proc")) == NULL)
    {
        printf("Unable to open /proc\n");
        return 0;
    }
    printf("PID\tPROCESS NAME\n");
    while ((dirEntryPointer = readdir(dirPointer)) != NULL)
    {
        if (atoi(dirEntryPointer->d_name) != 0)
        {
            char path[25];
            sprintf(path, "/proc/%s/exe", dirEntryPointer->d_name);
            char buff[100];
            ssize_t len = readlink(path, buff, sizeof(buff)-1);
            if (len != -1) 
            {
                buff[len] = '\0';
                printf("%s\t%s\n", dirEntryPointer->d_name, buff);
            }
            else 
            {
                perror("Cannot read symbolic link to process image");
            }
            printStat(dirEntryPointer->d_name);
            printf("\n");
        }
    }
    closedir(dirPointer);
    return 0;
}