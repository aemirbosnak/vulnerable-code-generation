//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE 1024
#define MAX_PROCESSES 1024

typedef struct {
    pid_t pid;
    char name[MAX_LINE];
    int status;
} Process;

void print_processes(Process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    char command[MAX_LINE];
    char *args[MAX_LINE / 2];
    int count = 0;
    int max_count = MAX_PROCESSES;
    Process processes[MAX_PROCESSES];

    while (1) {
        printf("> ");
        fgets(command, MAX_LINE, stdin);
        count = 0;
        int len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[--len] = '\0';
        }
        char *token = strtok(command, " ");
        while (token!= NULL) {
            args[count++] = token;
            if (count >= max_count) {
                break;
            }
            token = strtok(NULL, " ");
        }
        args[count] = NULL;

        pid_t pid = fork();
        if (pid == -1) {
            printf("Fork failed\n");
            continue;
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Exec failed\n");
                exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
            strcpy(processes[count].name, args[0]);
            processes[count].pid = pid;
            processes[count].status = WEXITSTATUS(status);
            count++;
            if (count >= max_count) {
                break;
            }
        }
    }

    print_processes(processes, count);

    return 0;
}