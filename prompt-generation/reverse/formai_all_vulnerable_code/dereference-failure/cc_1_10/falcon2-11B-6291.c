//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_PROCESSES 100

void displayProcess(pid_t pid, char *processName, char *parentName, char *command) {
    printf("%d %s %s %s\n", pid, processName, parentName, command);
}

void readProcess(pid_t pid) {
    char processName[100];
    char parentName[100];
    char command[100];

    if (read(STDOUT_FILENO, processName, sizeof(processName)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (read(STDOUT_FILENO, parentName, sizeof(parentName)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (read(STDOUT_FILENO, command, sizeof(command)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    displayProcess(pid, processName, parentName, command);
}

void displayAllProcesses() {
    int status;
    pid_t pid;
    char processName[100];
    char parentName[100];
    char command[100];

    DIR *dir;
    struct dirent *ent;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") == 0 && strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        pid = atoi(ent->d_name);

        if (pid < 1 || pid > MAX_PROCESSES) {
            continue;
        }

        if (fork() == 0) {
            readProcess(pid);
        } else {
            wait(&status);
        }
    }

    closedir(dir);
    printf("\nAll processes have been displayed.\n");
}

int main() {
    displayAllProcesses();
    return 0;
}