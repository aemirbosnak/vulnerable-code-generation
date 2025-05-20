//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NAME_LEN 64

int findProcessByName(char *name) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int ret = execlp("/usr/bin/pgrep", "pgrep", name, NULL);
        if (ret < 0) {
            perror("Error executing pgrep");
            exit(EXIT_FAILURE);
        }
    } else { // pid == 0
        int id = atoi(strtok(NULL, "\n"));
        _exit(id);
    }

    waitpid(pid, &status, 0);

    return WEXITSTATUS(status);
}

int main() {
    char myName[MAX_NAME_LEN] = "The Magnificent Process Hunter 3000";
    char myPid[16];
    char targetName[MAX_NAME_LEN] = "node";
    int targetPid;

    printf("%s\n", myName);
    printf("--------------------\n");

    myPid[0] = '\0';
    sprintf(myPid, "%d", getpid());

    while (1) {
        targetPid = findProcessByName(targetName);

        if (targetPid > 0) {
            printf("Found process %s with ID %d!\n", targetName, targetPid);
            printf("Looks like it's busy coding some more lines of code!\n");

            // Wait for the process to terminate before continuing
            int wstatus;
            waitpid(targetPid, &wstatus, 0);
            printf("Process %d terminated!\n", targetPid);
        } else {
            printf("Couldn't find process %s. Better luck next time!\n", targetName);
        }

        sleep(3);
    }

    return 0;
}