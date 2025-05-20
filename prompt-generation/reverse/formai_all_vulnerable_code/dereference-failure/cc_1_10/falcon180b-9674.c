//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[30];
    int pid;
    int status;
    int ppid;
} Process;

void get_processes(Process* processes, int num_processes) {
    char line[100];
    char* token;
    FILE* fp;
    int count = 0;

    fp = popen("ps -ax", "r");
    if (fp == NULL) {
        printf("Error: Failed to open ps command\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL)
            continue;
        if (count >= num_processes)
            break;
        strcpy(processes[count].name, token);
        processes[count].pid = atoi(token);
        token = strtok(NULL, " ");
        processes[count].status = atoi(token);
        token = strtok(NULL, " ");
        processes[count].ppid = atoi(token);
        count++;
    }

    pclose(fp);
}

void print_processes(Process* processes, int num_processes) {
    int i;

    printf("Process ID\tName\t\tStatus\tParent Process ID\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].status, processes[i].ppid);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int pid;
    int status;

    get_processes(processes, MAX_PROCESSES);
    printf("Number of processes: %d\n", num_processes);
    print_processes(processes, num_processes);

    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp("ls", "ls", NULL);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        printf("Child process terminated with status %d\n", status);
    }

    return 0;
}