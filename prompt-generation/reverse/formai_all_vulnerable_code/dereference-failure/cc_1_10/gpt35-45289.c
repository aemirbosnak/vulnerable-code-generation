//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 512

// function to remove leading and trailing spaces from a string
char *trim(char *str)
{
    char *end;

    // remove leading spaces
    while (isspace(*str)) 
        str++;

    // if string is all spaces, return empty string
    if (*str == 0)
        return str;

    // remove trailing spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
        end--;

    // null terminate string after last non-space character
    *(end+1) = 0;

    return str;
}

// function to read process status from /proc/<pid>/status file
int read_proc_status(char *buf, int buf_size, int pid)
{
    char filename[BUF_SIZE];
    sprintf(filename, "/proc/%d/status", pid);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    int bytes_read = fread(buf, 1, buf_size, fp);
    buf[bytes_read] = '\0';

    fclose(fp);

    return bytes_read;
}

// function to print process info for a given PID
void print_process_info(int pid)
{
    char buf[BUF_SIZE];
    int bytes_read = read_proc_status(buf, BUF_SIZE, pid);

    if (bytes_read > 0) 
    {
        char *name = "unknown";
        char *state = "unknown";
        int ppid = 0;
        int vmsize = 0;

        // parse name, state, ppid and vmsize from status file
        char *ptr = strtok(buf, "\n");
        while (ptr != NULL) 
        {
            if (strncmp(ptr, "Name:", 5) == 0)
                name = trim(ptr+5);
            else if (strncmp(ptr, "State:", 6) == 0)
                state = trim(ptr+6);
            else if (strncmp(ptr, "PPid:", 5) == 0)
                ppid = atoi(ptr+5);
            else if (strncmp(ptr, "VmSize:", 7) == 0)
                vmsize = atoi(ptr+7);

            ptr = strtok(NULL, "\n");
        }

        printf("%5d %-15s %-10s %5d %10d\n", pid, name, state, ppid, vmsize);
    }
}

// main function
int main(int argc, char *argv[])
{
    DIR *proc_dir;
    struct dirent *entry;

    printf("%5s %-15s %-10s %5s %10s\n", "PID", "NAME", "STATE", "PPID", "VMSIZE");

    // open /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) 
    {
        fprintf(stderr, "Error: could not open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    // loop through all directories in /proc
    while ((entry = readdir(proc_dir)) != NULL) 
    {
        // skip non-directories
        if (entry->d_type != DT_DIR)
            continue;

        // skip directories whose name is not a number
        if (!isdigit(entry->d_name[0]))
            continue;

        // print process info for this PID
        print_process_info(atoi(entry->d_name));
    }

    closedir(proc_dir);

    return 0;
}