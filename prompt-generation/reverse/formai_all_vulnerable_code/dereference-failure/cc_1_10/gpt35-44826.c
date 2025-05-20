//FormAI DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>

// Function to check if string is a number
int isNumber(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++) 
        if (isdigit(str[i]) == 0)
            return 0;
    return 1;
}

// Function to parse the command line arguments
int parse_args(int argc, char *argv[])
{
    int i, pid = -1; 
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-p") == 0 && i < argc-1 && isNumber(argv[i+1]))
            return atoi(argv[i+1]);
    }
    return pid;
}

// Main function
int main(int argc, char *argv[])
{
    int pid, n = 0, i = 0;
    DIR *dirp;
    struct dirent *dir;
    char path[1024], line[1024], buf[1024], name[1024], state[1024], ppid[1024];
    FILE *fp;

    // Parse the command line arguments
    pid = parse_args(argc, argv);

    // If no pid argument is provided, print usage and exit
    if (pid == -1)
    {
        printf("Usage: %s -p <pid>\n", argv[0]);
        return 1;
    }

    // If pid is specified, print the process information
    printf("Process ID: %d\n", pid);
    sprintf(path, "/proc/%d/status", pid);
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", path);
        return 1;
    }

    // Read the file line by line
    while (fgets(line, 1024, fp) != NULL)
    {
        if (sscanf(line, "Name: %[^\n]", buf) == 1)
            strcpy(name, buf);
        else if (sscanf(line, "State: %[^\n]", buf) == 1)
            strcpy(state, buf);
        else if (sscanf(line, "PPid: %[^\n]", buf) == 1)
            strcpy(ppid, buf);
    }
    
    // Close the file
    fclose(fp);

    printf("Name:\t%s\n", name);
    printf("State:\t%s\n", state);
    printf("PPid:\t%s\n", ppid);

    // Print the process hierarchy
    printf("\nParent Process Hierarchy:\n");
    sprintf(path, "/proc/%d/stat", pid);
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", path);
        return 1;
    }

    // Read the file line by line and extract the information
    fgets(line, 1024, fp);
    fclose(fp);

    sscanf(line, "%d (%[^)]", &pid, buf);
    n = strlen(buf);
    buf[n-1] = '\0';

    printf("%d (%s)\n", pid, buf);

    while (pid != 1)
    {
        sprintf(path, "/proc/%d/stat", atoi(ppid));
        fp = fopen(path, "r");

        if (fp == NULL)
        {
            printf("Error: Cannot open file %s\n", path);
            return 1;
        }

        fgets(line, 1024, fp);
        fclose(fp);

        sscanf(line, "%d (%[^)]", &pid, buf);
        n = strlen(buf);
        buf[n-1] = '\0';

        printf("%d (%s)\n", pid, buf);
    }

    // Print the child processes
    printf("\nChild Processes:\n");

    dirp = opendir("/proc");

    if (dirp == NULL)
    {
        printf("Error: Cannot open directory /proc\n");
        return 1;
    }

    while ((dir = readdir(dirp)) != NULL)
    {
        // Check if the directory is a directory and its name is numeric
        if (dir->d_type == DT_DIR && isNumber(dir->d_name))
        {
            sprintf(path, "/proc/%s/stat", dir->d_name);
            fp = fopen(path, "r");

            if (fp != NULL)
            {
                fgets(line, 1024, fp);
                fclose(fp);

                // Extract the process information from the stat file
                sscanf(line, "%d (%[^)]", &n, buf);

                if (n == pid)
                {
                    printf("%d (%s)\n", atoi(dir->d_name), buf);
                    i++;
                }
            }
        }
    }

    closedir(dirp);

    if (i == 0)
        printf("None\n");

    return 0;
}