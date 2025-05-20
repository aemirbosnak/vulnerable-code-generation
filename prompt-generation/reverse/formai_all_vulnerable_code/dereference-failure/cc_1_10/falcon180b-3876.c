//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_PROCESSES 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
    int exit_code;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t* new_process = &processes[num_processes];
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    new_process->pid = fork();

    if (new_process->pid == -1) {
        printf("Error: Failed to fork process.\n");
        return;
    } else if (new_process->pid == 0) {
        // Child process
        execlp(command, command, NULL);
        exit(1);
    }

    // Parent process
    num_processes++;
}

void remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            waitpid(pid, &processes[i].status, 0);
            processes[i].exit_code = WEXITSTATUS(processes[i].status);
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\tStatus\tExit Code\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\n", processes[i].pid, processes[i].command, processes[i].status, processes[i].exit_code);
    }
}

int main() {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char pid_str[10];
            sprintf(pid_str, "%d", atoi(ent->d_name));

            add_process(pid_str);
        }

        closedir(dir);
    } else {
        perror("");
        exit(1);
    }

    while (1) {
        print_processes();
        sleep(1);
    }

    return 0;
}