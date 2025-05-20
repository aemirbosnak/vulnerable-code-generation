//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int memory_usage;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void read_processes() {
    // Read all running processes and store their PID, name, and memory usage in the "processes" array
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = popen("ps -eo pid,comm,rss", "r");
    if (fp == NULL) {
        printf("Error: Failed to read running processes.\n");
        exit(1);
    }

    while ((fgets(line, sizeof(line), fp))!= NULL) {
        token = strtok(line, " ");
        processes[i].pid = atoi(token);
        strcpy(processes[i].name, token = strtok(NULL, " "));
        processes[i].memory_usage = atoi(token = strtok(NULL, " "));
        i++;
        if (i >= MAX_PROCESSES) {
            break;
        }
    }

    pclose(fp);
    num_processes = i;
}

void print_processes() {
    // Print the list of running processes along with their memory usage
    printf("PID\tName\tMemory Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
    }
}

int main() {
    read_processes();
    print_processes();

    while (1) {
        sleep(5); // Update the list of running processes and their memory usage every 5 seconds
        read_processes();
        print_processes();
    }

    return 0;
}