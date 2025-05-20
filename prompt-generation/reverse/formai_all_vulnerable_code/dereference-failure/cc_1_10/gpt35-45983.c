//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_SIZE 1024
#define MAX_COMMAND_SIZE 4096

void printHeader()
{
    printf("+---------------------------+\n");
    printf("|        Process Viewer     |\n");
    printf("+----------------+----------+\n");
    printf("| Process Name   |   PID    |\n");
    printf("+----------------+----------+\n");
}

void listProcesses()
{
    DIR *dir;
    struct dirent *entry;
    char command[MAX_COMMAND_SIZE];
    char path[MAX_PATH_SIZE];
    FILE *cmd;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open directory /proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            sprintf(path, "/proc/%s/cmdline", entry->d_name);
            cmd = fopen(path, "r");
            if (cmd) {
                fgets(command, MAX_COMMAND_SIZE, cmd);
                fclose(cmd);
                if (strlen(command) > 0) {
                    printf("| %-14s | %-8s |\n", command, entry->d_name);
                }
            }
        }
    }

    closedir(dir);
}

int main()
{
    system("clear");
    printHeader();
    listProcesses();
    printf("+----------------+----------+\n");

    return 0;
}