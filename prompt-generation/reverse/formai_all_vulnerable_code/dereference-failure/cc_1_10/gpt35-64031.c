//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
/* This program demonstrates interprocess communication using named pipes in C. The process creates a parent-child relationship by spawning a child process. The parent process sends a message to the child through the named pipe. The child process reads the message and sends a response message back to the parent through the same pipe. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUF 1024

int main(void)
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
    
    /* create the FIFO (named pipe) if it does not already exist */
    if (mkfifo(myfifo, 0666) == -1) {
        if(errno != EEXIST){
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    /* parent process */
    if (pid > 0) {

        printf("Parent process with id %d created and waiting for message.\n", getpid());

        /* open the FIFO for writing */
        fd = open(myfifo, O_WRONLY);

        /* wait for user input */
        printf("Enter a message to send to the child:\n");
        fgets(buf, MAX_BUF, stdin);

        /* write message to the FIFO */
        if (write(fd, buf, strlen(buf) + 1) == -1){
            perror("write");
        }

        /* wait for response from child */
        if (read(fd, buf, MAX_BUF) == -1) {
            perror("read");
        }
        printf("Received message from child: %s", buf);

        /* cleanup */
        close(fd);
        unlink(myfifo);
        printf("Parent process exiting.\n");

    }
    /* child process */
    else {
        printf("Child process with id %d created and waiting for message.\n", getpid());

        /* open the FIFO for reading */
        fd = open(myfifo, O_RDONLY);

        /* wait for message from parent */
        if (read(fd, buf, MAX_BUF) == -1) {
            perror("read");
        }
        printf("Received message from parent: %s", buf);

        /* send response message to parent */
        printf("Enter a message to send to the parent:\n");
        fgets(buf, MAX_BUF, stdin);

        /* write message to the FIFO */
        if (write(fd, buf, strlen(buf) + 1) == -1){
            perror("write");
        }

        /* cleanup */
        close(fd);
        printf("Child process exiting.\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}