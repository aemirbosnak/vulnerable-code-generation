//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_DEPTH 10
#define MSG_SIZE 100

void child_process(int depth, int parent_id, int id, int fd[2]) {
    char message[MSG_SIZE];
    close(fd[1]); // closing write end of pipe
    
    read(fd[0], message, sizeof(message)); // reading message from parent process
    
    printf("Depth %d: Process %d read message from process %d: %s\n", depth, id, parent_id, message);
    
    if(depth < MAX_DEPTH) { // spawn new child process if current depth is less than max depth
        int new_fd[2];
        pipe(new_fd);
        int pid = fork();
        if(pid == 0) { // child process
            child_process(depth + 1, id, id * 2, new_fd);
        } else { // parent process
            close(new_fd[0]); // closing read end of pipe in parent process
            char* message = malloc(MSG_SIZE * sizeof(char));
            sprintf(message, "Hello from process %d.", id);
            write(new_fd[1], message, strlen(message) + 1); // writing message to child process
            free(message);
            wait(NULL);
        }
    } else {
        printf("Depth %d: Maximum depth reached for process %d.\n", depth, id);
    }
}

int main() {
    int fd[2];
    pipe(fd);
    int pid = fork();
    
    if(pid == 0) { // child process
        child_process(1, 1, 2, fd);
    } else { // parent process
        close(fd[0]); // closing read end of pipe in parent process
        char* message = malloc(MSG_SIZE * sizeof(char));
        sprintf(message, "Hello from process 1.");
        write(fd[1], message, strlen(message) + 1); // writing message to child process
        free(message);
        wait(NULL);
    }
    return 0;
}