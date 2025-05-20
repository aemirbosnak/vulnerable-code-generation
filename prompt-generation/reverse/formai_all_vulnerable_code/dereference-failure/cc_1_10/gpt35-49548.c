//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_CMDLINE_LEN 1024
#define MAX_PATH_LEN 1024
#define MAX_PID_LEN 10

void print_header()
{
    printf("%-10s %-20s %-10s %-10s %-30s\n", "PID", "Name", "Status", "Memory", "Command");
    printf("--------------------------------------------------------------\n");
}

char* get_cmdline(char* pid)
{
    char cmdfile[MAX_PATH_LEN];
    snprintf(cmdfile, MAX_PATH_LEN, "/proc/%s/cmdline", pid);

    FILE* fp;
    fp = fopen(cmdfile, "r");

    if (fp == NULL)
    {
        return NULL;
    }

    char* cmdline = malloc(MAX_CMDLINE_LEN);
    memset(cmdline, 0, MAX_CMDLINE_LEN);

    fread(cmdline, sizeof(char), MAX_CMDLINE_LEN, fp);

    fclose(fp);

    return cmdline;
}

void print_process(char* pid)
{
    char statusfile[MAX_PATH_LEN];
    snprintf(statusfile, MAX_PATH_LEN, "/proc/%s/status", pid);

    char* cmdline = get_cmdline(pid);

    if (cmdline == NULL)
    {
        free(cmdline);
        return;
    }

    FILE* fp;
    fp = fopen(statusfile, "r");

    if (fp == NULL)
    {
        free(cmdline);
        return;
    }

    char* name = malloc(MAX_CMDLINE_LEN);
    char* status = malloc(MAX_CMDLINE_LEN);
    char* memory = malloc(MAX_CMDLINE_LEN);

    memset(name, 0, MAX_CMDLINE_LEN);
    memset(status, 0, MAX_CMDLINE_LEN);
    memset(memory, 0, MAX_CMDLINE_LEN);

    char line[MAX_CMDLINE_LEN];
    while(fgets(line, MAX_CMDLINE_LEN, fp))
    {
        if (strncmp(line, "Name:", 5) == 0)
            sscanf(line+5, "%s", name);
        else if (strncmp(line, "State:", 6) == 0)
            sscanf(line+6, "%s", status);
        else if (strncmp(line, "VmRSS:", 6) == 0)
            sscanf(line+6, "%s", memory);
    }

    printf("%-10s %-20s %-10s %-10s %-30s\n", pid, name, status, memory, cmdline);

    free(name);
    free(status);
    free(memory);
    free(cmdline);
    fclose(fp);
}

void list_processes()
{
    DIR* dir = opendir("/proc");

    if (dir == NULL)
        return;

    struct dirent* entry;
    while((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            char* pid = entry->d_name;

            if (atoi(pid) > 0)
                print_process(pid);
        }
    }

    closedir(dir);
}

int main()
{
    print_header();
    list_processes();

    return 0;
}