//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PATH 1024
#define MAX_CMDLINE 2048

int is_number(char *str)
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

void print_process_info(char *pid)
{
    char cmdline_path[MAX_PATH];
    snprintf(cmdline_path, MAX_PATH, "/proc/%s/cmdline", pid);

    char cmdline[MAX_CMDLINE];
    FILE *fp = fopen(cmdline_path, "r");
    if (fp)
    {
        fread(cmdline, sizeof(char), MAX_CMDLINE, fp);
        fclose(fp);
    }
    else
    {
        strcpy(cmdline, "N/A");
    }

    printf("%-8s %-30s\n", pid, cmdline);
}

int main()
{
    printf("PID     Command\n");

    DIR *dir = opendir("/proc");
    if (!dir)
    {
        printf("Failed to open /proc directory!\n");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (is_number(entry->d_name))
        {
            print_process_info(entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}