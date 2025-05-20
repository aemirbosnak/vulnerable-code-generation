//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/* Function to check if given string contains only digits */
int isNumber(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

/* Function to get process name from PID */
char *getProcessName(int pid)
{
    FILE *file;
    char *filename = (char *)malloc(sizeof(char) * 20);
    char line[100], *name = (char *)malloc(sizeof(char) * 20);

    /* Construct filename for the process */
    sprintf(filename, "/proc/%d/status", pid);

    /* Open file with filename */
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return "";
    }

    /* Read from file until "Name: " line is found */
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Name:"))
        {
            /* Extract process name from line */
            sscanf(line, "Name:\t%s", name);
            break;
        }
    }

    /* Close open file and return process name */
    fclose(file);
    free(filename);
    return name;
}

/* Main function to iterate through all running processes */
int main()
{
    DIR *d;
    struct dirent *dir;
    int pid;
    char *name;
    char *path;
    char line[256], *temp;

    /* Open the /proc directory */
    d = opendir("/proc");

    if (d == NULL)
    {
        printf("Error: Could not open /proc directory\n");
        return 1;
    }

    /* Iterate through all directories in the /proc directory */
    while ((dir = readdir(d)) != NULL)
    {
        /* Check if directory name is a number */
        if (isNumber(dir->d_name))
        {
            /* Convert directory name to integer */
            pid = atoi(dir->d_name);

            /* Get process name from PID */
            name = getProcessName(pid);

            /* Construct path for cmdline file */
            path = (char *)malloc(sizeof(char) * 50);
            sprintf(path, "/proc/%d/cmdline", pid);

            /* Open cmdline file and read first line */
            FILE *file = fopen(path, "r");
            fgets(line, sizeof(line), file);

            /* Remove trailing newline character */
            temp = strchr(line, '\n');
            if (temp)
            {
                *temp = '\0';
            }

            /* Print process name and cmd line */
            printf("%-10s %s\n", name, line);

            /* Free malloc'd memory */
            free(name);
            free(path);
            fclose(file);
        }
    }

    /* Close the /proc directory */
    closedir(d);
    return 0;
}