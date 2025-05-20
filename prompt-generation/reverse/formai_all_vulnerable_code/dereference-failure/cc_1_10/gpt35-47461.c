//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
//Welcome to the C System Process Viewer!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

//Function to check if the input string is a number
int isNumber(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main()
{
    printf("C System Process Viewer\n");
    printf("-----------------------\n\n");

    DIR *directory;
    struct dirent *entry;

    directory = opendir("/proc");

    if (directory == NULL)
    {
        printf("Error opening /proc directory\n");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-20s %-15s %-10s\n", "PID", "PROCESS", "USER", "MEMORY");

    while ((entry = readdir(directory)) != NULL)
    {
        if (isNumber(entry->d_name))
        {
            char filename[100];
            snprintf(filename, sizeof(filename), "/proc/%s/status", entry->d_name);

            FILE *fp = fopen(filename, "r");

            if (fp != NULL)
            {
                char line[256];
                char *name, *uid, *vmrss;
                name = uid = vmrss = "";

                while (fgets(line, sizeof(line), fp))
                {
                    if (strncmp(line, "Name:", 5) == 0)
                    {
                        name = line + 6;
                        name[strlen(name) - 1] = '\0';
                    }
                    else if (strncmp(line, "Uid:", 4) == 0)
                    {
                        uid = line + 5;
                        uid[strlen(uid) - 1] = '\0';
                    }
                    else if (strncmp(line, "VmRSS:", 6) == 0)
                    {
                        vmrss = line + 7;
                        vmrss[strlen(vmrss) - 3] = '\0';
                    }
                }

                fclose(fp);
                printf("%-10s %-20s %-15s %-10s\n", entry->d_name, name, uid, vmrss);
            }
        }
    }

    closedir(directory);

    return 0;
}