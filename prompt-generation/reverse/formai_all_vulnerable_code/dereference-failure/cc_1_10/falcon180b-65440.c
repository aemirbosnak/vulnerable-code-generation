//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE 1024

void print_process_info(char *process_name, int pid, int status, int ppid, int priority, int nice) {
    printf("Process Name: %s\n", process_name);
    printf("Process ID: %d\n", pid);
    printf("Status: %d\n", status);
    printf("Parent Process ID: %d\n", ppid);
    printf("Priority: %d\n", priority);
    printf("Nice Value: %d\n\n", nice);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE];
    int pid, status;
    int i, j;
    char *process_name;
    int ppid;
    int priority;
    int nice;

    if (argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }

    pid = atoi(argv[1]);

    file = fopen("/proc/pid/status", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            process_name = strtok(line, ":");
        } else if (strncmp(line, "PPid:", 5) == 0) {
            ppid = atoi(strtok(line, ":"));
        } else if (strncmp(line, "State:", 6) == 0) {
            status = atoi(strtok(line, ":"));
        } else if (strncmp(line, "Priority:", 9) == 0) {
            priority = atoi(strtok(line, ":"));
        } else if (strncmp(line, "Nice:", 5) == 0) {
            nice = atoi(strtok(line, ":"));
        }
    }

    fclose(file);

    printf("Process Information:\n");
    printf("--------------------\n");
    print_process_info(process_name, pid, status, ppid, priority, nice);

    return 0;
}