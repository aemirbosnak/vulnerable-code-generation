//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd;
    int pid;
    int status;
    int count = 0;
    int i;
    char *args[10];
    char *buffer = (char*)malloc(1024*sizeof(char));

    printf("Post-Apocalyptic Process Viewer\n");

    while(1) {
        printf("\nEnter command: ");
        fgets(buffer, 1024, stdin);
        args[count] = strtok(buffer, " ");
        count++;

        if(strcmp(args[0], "exit") == 0) {
            break;
        } else if(strcmp(args[0], "ps") == 0) {
            system("ps");
        } else if(strcmp(args[0], "kill") == 0) {
            if(count < 2) {
                printf("Usage: kill [PID]\n");
            } else {
                pid = atoi(args[1]);
                kill(pid, SIGKILL);
                printf("Process %d killed\n", pid);
            }
        } else {
            pid = fork();

            if(pid == -1) {
                printf("Fork failed\n");
            } else if(pid == 0) {
                if(execvp(args[0], args) == -1) {
                    printf("Command not found\n");
                    exit(1);
                }
            } else {
                waitpid(pid, &status, WUNTRACED);
            }
        }
    }

    free(buffer);
    exit(0);
}