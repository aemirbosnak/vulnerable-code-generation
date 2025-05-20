//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>

/* Declare a structure */
struct ProcessDetails
{
    char pid[10];
    char pname[100];
    char pstatus[20];
    char mem[20];
};

/* Function to read process status from /proc/ directory */
int readProcessStatus(char *pid, char *pname, char *pstatus, char *mem)
{
    char filename[50], line[500];
    FILE *fp;

    sprintf(filename, "/proc/%s/status", pid);
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return 0;
    }

    while(fgets(line, 500, fp))
    {
        /* Get the process name */
        if(strncmp(line, "Name:", 5) == 0)
        {
            strncpy(pname, line+5, 100);
            pname[strlen(pname)-1] = '\0';
            continue;
        }
        
        /* Get the process status */
        if(strncmp(line, "State:", 6) == 0)
        {
            strncpy(pstatus, line+7, 20);
            pstatus[strlen(pstatus)-1] = '\0';
            continue;
        }
        
        /* Get the memory usage */
        if(strncmp(line, "VmRSS:", 6) == 0)
        {
            strncpy(mem, line+7, 20);
            mem[strlen(mem)-1] = '\0';
            break;
        }
    }

    fclose(fp);
    return 1;
}

/* Function to get the number of running processes */
int getNumProcesses()
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir("/proc");
    if(dir == NULL)
    {
        return 0;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(isdigit(entry->d_name[0]))
        {
            count++;
        }
    }

    closedir(dir);
    return count;
}

/* Function to get the list of running processes */
int getProcessList(struct ProcessDetails *plist, int numProcesses)
{
    DIR *dir;
    struct dirent *entry;
    int i;

    dir = opendir("/proc");
    if(dir == NULL)
    {
        return 0;
    }

    i = 0;
    while((entry = readdir(dir)) != NULL && i < numProcesses)
    {
        if(isdigit(entry->d_name[0]))
        {
            strncpy(plist[i].pid, entry->d_name, 10);
            if(readProcessStatus(entry->d_name, plist[i].pname, plist[i].pstatus, plist[i].mem) == 0)
            {
                /* If process status cannot be read, skip the process */
                continue;
            }
            i++;
        }
    }

    closedir(dir);
    return i;
}

/* Function to print the process list */
void printProcessList(struct ProcessDetails *plist, int numProcesses)
{
    int i;

    printf("\n%-10s %-30s %-20s %-20s\n", "PID", "Name", "Status", "Memory");

    for(i = 0; i < numProcesses; i++)
    {
        printf("%-10s %-30s %-20s %-20s\n", plist[i].pid, plist[i].pname, plist[i].pstatus, plist[i].mem);
    }
}

/* Main function */
int main()
{
    int numProcesses;
    struct ProcessDetails *plist;

    /* Get the number of running processes */
    numProcesses = getNumProcesses();
    if(numProcesses == 0)
    {
        printf("No processes found.\n");
        return 0;
    }

    /* Allocate memory for the process list */
    plist = (struct ProcessDetails*)malloc(numProcesses * sizeof(struct ProcessDetails));
    if(plist == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    /* Get the list of running processes */
    numProcesses = getProcessList(plist, numProcesses);
    if(numProcesses == 0)
    {
        printf("Failed to get process list.\n");
        free(plist);
        return 0;
    }

    /* Print the process list */
    printProcessList(plist, numProcesses);

    /* Free memory */
    free(plist);

    return 0;
}