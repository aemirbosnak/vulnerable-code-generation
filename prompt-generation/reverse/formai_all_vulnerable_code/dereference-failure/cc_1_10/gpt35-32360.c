//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
    This is a surreal C Interprocess Communication program that simulates a conversation between two distinct
    parallel processes. Each process sends a random number to the other process, echoing it, and appending a 
    random character to it before sending it back. The characters appended to the numbers are picked at random 
    from a collection of unusual, surrealist words. 
*/

char* surrealist_words[] = {"juicy", "squishy", "spotty", "lopsided", "zigzag", "chubby", "grumpy", "slippery", 
                            "itchy", "twisted", "fizzy", "clumsy", "bumpy", "crispy", "sleepy", "milky"}; 

int main() {
    pid_t pid;
    int fd[2], nbytes;
    char message[100], random_char;
    
    srand(time(NULL)); 
    
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }
    
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        int random_num = rand() % 100;
        sprintf(message, "%d", random_num);
        random_char = surrealist_words[rand() % 16][0];
        strcat(message, &random_char);
        
        close(fd[0]);
        write(fd[1], message, strlen(message)+1);
        close(fd[1]);
        
        printf("Parent sent %s to child\n", message);
        
        wait(NULL);
    } else { 
        char buffer[100];
        nbytes = read(fd[0], buffer, sizeof(buffer));
        close(fd[1]);
        
        int received_num;
        char received_char;
        sscanf(buffer, "%d%c", &received_num, &received_char);
        printf("Child received %d%c\n", received_num, received_char);
        
        int random_num = rand() % 100;
        sprintf(message, "%d", random_num);
        random_char = surrealist_words[rand() % 16][0];
        strcat(message, &random_char);
        
        close(fd[0]);
        write(fd[1], message, strlen(message)+1);
        close(fd[1]);
        
        printf("Child sent %s to parent\n", message);
    }
    
    return 0;
}