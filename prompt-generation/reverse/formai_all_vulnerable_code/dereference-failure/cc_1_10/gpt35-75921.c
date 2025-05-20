//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

void handle_signal(int signal);
void read_pipe(int fd);

int main()
{
    //Create a pipe
    int pp[2];
    if (pipe(pp) == -1) {
        printf("Error: Unable to create pipe\n");
        exit(EXIT_FAILURE);
    }
    
    //Fork a child process
    int pid = fork();
    if (pid == -1) {
        printf("Error: Unable to create child process\n");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) { //Child process
        printf("Child process started with pid=%d\n", getpid());
        
        //Close the write end of the pipe
        close(pp[1]);
        
        //Register signal handler for SIGUSR1
        signal(SIGUSR1, handle_signal);
        
        //Read from the pipe asynchronously
        while (1) {
            read_pipe(pp[0]);
            usleep(100000); //Sleep for 0.1 seconds
        }
        
        //Close the read end of the pipe
        close(pp[0]);
        
        printf("Child process exiting...\n");
        exit(EXIT_SUCCESS);
    } else { //Parent process
        printf("Parent process started with pid=%d\n", getpid());
        
        //Close the read end of the pipe
        close(pp[0]);
        
        //Send messages to the child process asynchronously
        int count = 0;
        while (1) {
            char message[50];
            sprintf(message, "Message %d from parent\n", count++);
            write(pp[1], message, strlen(message));
            usleep(500000); //Sleep for 0.5 seconds
        }
        
        //Close the write end of the pipe
        close(pp[1]);
    }
    
    return 0;
}

void handle_signal(int signal)
{
    printf("Signal %d received by child process with pid=%d\n", signal, getpid());
}

void read_pipe(int fd)
{
    char buffer[1024];
    int nbytes = read(fd, buffer, sizeof(buffer));
    if (nbytes > 0) {
        buffer[nbytes] = '\0';
        printf("%s", buffer);
    }
}