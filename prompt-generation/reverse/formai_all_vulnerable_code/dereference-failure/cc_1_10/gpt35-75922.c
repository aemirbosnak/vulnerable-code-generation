//FormAI DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH 1024

void print_process_info(const char* pid);

int main()
{
    DIR* proc_dir;
    struct dirent* dir_entry;

    proc_dir = opendir("/proc");
    while ((dir_entry = readdir(proc_dir)) != NULL)
    {
        if (dir_entry->d_type != DT_DIR)
            continue;

        if (strspn(dir_entry->d_name, "0123456789") != strlen(dir_entry->d_name))
            continue;

        print_process_info(dir_entry->d_name);
    }
    closedir(proc_dir);

    return 0;
}

void print_process_info(const char* pid)
{
    char proc_path[MAX_PATH], line[MAX_PATH], *token;
    FILE* proc_file;
    int mem_size;

    // Get process executable path
    sprintf(proc_path, "/proc/%s/exe", pid);
    mem_size = readlink(proc_path, line, sizeof(line));
    if (mem_size == -1)
        sprintf(line, "%s", "Error");

    // Print process info
    printf("PID: %s\n", pid);
    printf("Executable path: %s\n", line);

    // Get process command line
    sprintf(proc_path, "/proc/%s/cmdline", pid);
    proc_file = fopen(proc_path, "r");
    if (proc_file == NULL)
        return;

    printf("Command: ");
    while (fgets(line, sizeof(line), proc_file) != NULL)
        printf("%s ", line);
    fclose(proc_file);

    // Get process status
    sprintf(proc_path, "/proc/%s/status", pid);
    proc_file = fopen(proc_path, "r");
    if (proc_file == NULL)
        return;

    printf("\nStatus:\n");
    while (fgets(line, sizeof(line), proc_file) != NULL)
    {
        token = strtok(line, ":\t");
        if (strcmp(token, "VmSize") == 0)
            printf("  Memory usage: %s", strtok(NULL, "\n"));
        else if (strcmp(token, "State") == 0)
            printf("  State: %s", strtok(NULL, "\n"));
        else if (strcmp(token, "PPid") == 0)
            printf("  Parent PID: %s", strtok(NULL, "\n"));
    }
    fclose(proc_file);

    printf("\n---------------------------\n");
}