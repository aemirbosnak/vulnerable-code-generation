//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int i, j, fd[2], n, status;
    char command[MAX];

    for(i=0; i<argc; i++) {
        if(strcmp(argv[i], "-c") == 0) {
            strcpy(command, argv[i+1]);
            break;
        }
    }

    if(pipe(fd) == -1) {
        perror("Pipe Failed");
        exit(1);
    }

    switch(fork()) {
        case -1: // error occurred
            perror("Fork Failed");
            exit(1);
        case 0: // child process
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execlp("sh", "sh", "-c", command, NULL); // execute the command
            perror("execlp Failed");
            exit(1);
        default: // parent process
            close(fd[1]);
            fd[1] = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // create output file
            if(fd[1] == -1) {
                perror("open Failed");
                exit(1);
            }
            waitpid(0, &status, 0); // wait for child process to finish
            close(fd[0]);
            exit(0);
    }

    return 0;
}