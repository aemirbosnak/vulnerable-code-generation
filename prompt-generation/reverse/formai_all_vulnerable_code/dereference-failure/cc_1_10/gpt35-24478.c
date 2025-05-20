//FormAI DATASET v1.0 Category: System administration ; Style: distributed
//This is a unique C system administration example program in a distributed style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_LINE 1024 /* Maximum command length */

int main(int argc, char* argv[]) {
    char* cmd; //command to be executed
    char delim[] = " "; //delimiter to separate command and arguments
    char* token; //to store each argument of the given command
    char* args[MAX_LINE/2 + 1]; //to store the arguments of the command
    int should_run = 1; //flag for the execution of a command
    pid_t pid; //process id for fork
    int status; //status of child process for waitpid

    printf("Welcome to the Distributed System Administration Program.\n"); 
    printf("Enter your command: ");

    while(should_run) {
        cmd = (char*) malloc(MAX_LINE * sizeof(char)); //allocate buffer for the command
        fgets(cmd, MAX_LINE, stdin); //read command from user

        args[0] = strtok(cmd, delim); //separate the command
        int i = 1;
        while (token = strtok(NULL, delim)) { //separate the arguments
            args[i] = token;
            i++;
        }
        args[i] = NULL; //add NULL at the end of the argument list to execute with execvp

        if (strcmp(args[0], "exit\n") == 0) { //check if user wants to exit the program
            should_run = 0;
            continue;
        }

        pid = fork(); //fork a new process
        if (pid == -1) { //fork error
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { //child process
            if (execvp(args[0], args) == -1) { //execute the command with arguments
                perror("execvp failed");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS); //child process terminates
        }
        else { //parent process
            do { //wait for child process to terminate
                if (waitpid(pid, &status, WUNTRACED) == -1) {
                    perror("waitpid failed");
                    exit(EXIT_FAILURE);
                }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        free(cmd); //free command buffer
    }
    printf("Goodbye.\n"); //program ends
    return 0;
}