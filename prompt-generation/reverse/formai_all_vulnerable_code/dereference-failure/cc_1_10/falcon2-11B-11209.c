//Falcon2-11B DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    int child;
    int status;
    int pid;
    int oldeuid;
    int oldegid;

    if (argc!= 3) {
        printf("Usage: %s <UID> <GID>\n", argv[0]);
        return 1;
    }

    oldeuid = geteuid();
    oldegid = getegid();
    if (setresgid(atoi(argv[2]), atoi(argv[2]), atoi(argv[2]))!= 0) {
        perror("setresgid");
        return 1;
    }

    if (setresuid(atoi(argv[1]), atoi(argv[1]), atoi(argv[1]))!= 0) {
        perror("setresuid");
        return 1;
    }

    child = fork();
    if (child == -1) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        // Child process
        printf("Child process started with PID %d\n", getpid());
        sleep(1);
        printf("Child process finished with status %d\n", WEXITSTATUS(status));
        return 0;
    } else {
        // Parent process
        pid = wait(&status);
        printf("Parent process finished with child PID %d and status %d\n", pid, WEXITSTATUS(status));
        return 0;
    }
}