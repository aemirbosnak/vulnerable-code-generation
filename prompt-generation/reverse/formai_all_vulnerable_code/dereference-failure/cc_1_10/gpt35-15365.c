//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>

// function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    int i,j;
    char temp;
    for(i=0, j=len-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: ./async_string <string>\n");
        exit(1);
    }
    
    char* original_string = argv[1];
    char* reversed_string = (char*) malloc(strlen(original_string)*sizeof(char));

    int pipefd[2];
    pid_t pid;

    if(pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(1);
    }

    if(pid == 0) {
        close(pipefd[0]); // close reading end
        
        // reverse the string
        reverse_string(original_string);
        
        // write the reversed string to the pipe
        write(pipefd[1], original_string, strlen(original_string)+1);
        
        // close the writing end
        close(pipefd[1]);
        
        exit(0);
    }
    else {
        // parent process
        
        int status;
        waitpid(pid, &status, 0);
        
        if(WIFEXITED(status)) {
            if(WEXITSTATUS(status) == 0) {
                close(pipefd[1]); // close writing end
                
                // read the reversed string from the pipe
                read(pipefd[0], reversed_string, strlen(original_string)+1);
                
                // close reading end
                close(pipefd[0]);
                
                // print the reversed string
                printf("Original string: %s\nReversed string: %s\n", original_string, reversed_string);
            }
        }
        else {
            printf("Child process did not terminate normally\n");
            exit(1);
        }
    }
    
    return 0;
}