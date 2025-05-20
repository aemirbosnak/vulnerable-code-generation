//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MAX_PID_LENGTH 6

void print_error_message(char *message)
{
    fprintf(stderr, "ERROR: %s\n", message);
    exit(1);
}

void print_process_info(char *pid_dir)
{
    char cmd_file_path[BUF_SIZE];
    char status_file_path[BUF_SIZE];
    char cmdline[BUF_SIZE];
    char status[BUF_SIZE];
    char *token;
    char *name;
    FILE *cmd_file, *status_file;

    // Open the cmd and status files
    snprintf(cmd_file_path, BUF_SIZE, "/proc/%s/cmdline", pid_dir);
    snprintf(status_file_path, BUF_SIZE, "/proc/%s/status", pid_dir);
    cmd_file = fopen(cmd_file_path, "r");
    status_file = fopen(status_file_path, "r");
    if (!cmd_file)
        print_error_message("Failed to open cmd file");
    if (!status_file)
        print_error_message("Failed to open status file");

    // Get the process name from the cmd file
    fgets(cmdline, BUF_SIZE, cmd_file);
    token = strtok(cmdline, "/");
    while (token != NULL)
    {
        name = token;
        token = strtok(NULL, "/");
    }

    // Get the process status from the status file
    while (fgets(status, BUF_SIZE, status_file))
    {
        if (strncmp(status, "State:", 6) == 0)
            break;
    }

    // Print the process info
    printf("%-6s %-20s %s", pid_dir, name, status);

    // Close the files
    fclose(cmd_file);
    fclose(status_file);
}

void print_process_list()
{
    DIR *proc_dir;
    struct dirent *entry;
    char pid_dir[MAX_PID_LENGTH + 6];

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (!proc_dir)
        print_error_message("Failed to open /proc directory");

    // Print the header
    printf("%-6s %-20s %s\n", "PID", "NAME", "STATUS");

    // Loop through all the entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL)
    {
        // Check if the entry is a PID directory
        if (isdigit(entry->d_name[0]))
        {
            // Copy the PID directory name to pid_dir
            snprintf(pid_dir, MAX_PID_LENGTH + 6, "%s", entry->d_name);

            // Print the process info
            print_process_info(pid_dir);
        }
    }

    // Close the directory
    closedir(proc_dir);
}

int main()
{
    print_process_list();
    return 0;
}