//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define COMMAND_PATH "/proc"
#define COMMAND_FORMAT "ps -o pid,comm,user,stime"

struct Process {
    int pid;
    char comm[256];
    char user[32];
    char stime[12];
};

void get_process_info(struct Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    FILE *fp;

    *count = 0;
    if ((dir = opendir(COMMAND_PATH)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            struct Process proc;
            snprintf(path, sizeof(path), COMMAND_PATH"/%s/status", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                fscanf(fp, "Name:\t%s\n", proc.comm);
                fscanf(fp, "Uid:\t%s\n", proc.user); // Uid as a string
                fclose(fp);

                proc.pid = atoi(entry->d_name);

                snprintf(path, sizeof(path), COMMAND_PATH"/%s/stat", entry->d_name);
                fp = fopen(path, "r");
                if (fp) {
                    char state[2], ptty[16];
                    int ppid, pgrp;
                    fscanf(fp, "%d %s %s %d %d %*s %*s %*s %*s %*s %*s %*s %*s %*s %d\n", 
                        &proc.pid, proc.comm, state, &ppid, &pgrp, &proc.stime);
                    fclose(fp);

                    processes[*count] = proc;
                    (*count)++;
                }
            }
        }
    }
    closedir(dir);
}

void display_processes(struct Process *processes, int count) {
    printf("%-10s %-15s %-10s %-10s\n", "PID", "Command", "User", "Start Time");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-15s %-10s %-10s\n", 
            processes[i].pid, processes[i].comm, processes[i].user, processes[i].stime);
    }
    printf("------------------------------------------------------\n");
}

void execute_command() {
    printf("Executing command: '%s'\n", COMMAND_FORMAT);
    system(COMMAND_FORMAT);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int process_count;

    get_process_info(processes, &process_count);
    display_processes(processes, process_count);
    
    printf("Would you like to see the command output? (y/n): ");
    char choice;
    scanf(" %c", &choice); // Space before %c to ignore any leading whitespace

    if (tolower(choice) == 'y') {
        execute_command();
    } else {
        printf("Exiting process viewer.\n");
    }

    return 0;
}