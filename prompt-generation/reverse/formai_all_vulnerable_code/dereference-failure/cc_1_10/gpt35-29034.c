//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]){
    pid_t pid;
    int status = 0, pipe_fd[2];
    char buffer[BUFFER_SIZE] = {0};
    char *str = (char*) malloc(sizeof(char)*BUFFER_SIZE);
    if(argc > 1){
        str = argv[1];
    }else{
        strcpy(str, "Hello from parent process!");
    }

    if(pipe(pipe_fd)==-1){
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if(pid == -1){
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        printf("Child process is running\n");
        close(pipe_fd[1]);      //Close write end of pipe
        read(pipe_fd[0], buffer, BUFFER_SIZE);
        printf("Child process received message: \"%s\"\n", buffer);
        close(pipe_fd[0]);      //Close read end of pipe
        exit(EXIT_SUCCESS);
    }else{
        printf("Parent process is running\n");
        close(pipe_fd[0]);      //Close read end of pipe
        printf("Sending message to child process\n");
        write(pipe_fd[1], str, strlen(str)+1);
        close(pipe_fd[1]);      //Close write end of pipe
        wait(&status);
        printf("Child process exited with status: %d\n", status);
        exit(EXIT_SUCCESS);
    }
    return 0;
}