//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 2048
#define PROJECT_ID 0x1234

typedef struct {
    int id;
    char name[50];
} person_t;

int main() {
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    person_t *buffer = (person_t *) shmat(shmid, NULL, 0);
    if ((void *) -1 == buffer) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        printf("Error: pipe failed\n");
        exit(1);
    }

    pid_t childpid = fork();
    if (childpid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    }

    if (childpid == 0) {
        // child process
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execlp("ls", "ls", NULL);
        perror("execlp");
        exit(1);
    } else {
        // parent process
        close(pipefd[1]);
        char inputbuffer[BUFFER_SIZE];
        while (fgets(inputbuffer, BUFFER_SIZE, stdin)!= NULL) {
            strcat(buffer->name, inputbuffer);
        }
        kill(childpid, SIGKILL);
        waitpid(childpid, NULL, 0);
        printf("Child process terminated\n");
    }

    return 0;
}