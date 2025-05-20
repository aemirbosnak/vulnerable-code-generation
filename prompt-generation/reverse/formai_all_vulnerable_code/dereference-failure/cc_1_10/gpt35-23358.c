//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_WORDS 10
#define BUFFER_SIZE 100

// The main function of a shell that reads and executes user's input
int main() {
    char* tokens[MAX_WORDS];    // an array of pointers to hold individual words in input
    char buffer[BUFFER_SIZE];   // buffer to hold input
    char* word;                 // pointer to each word in input
    int num_words;              // number of words in input
    pid_t pid;                  // process ID for fork
    int status;                 // status value returned by child process
    
    while (1) {
        printf("mathShell> ");   // prompt for user input
        fgets(buffer, BUFFER_SIZE, stdin);  // read user input
        
        // Tokenize the input into individual words
        num_words = 0;
        word = strtok(buffer, " \n");
        while (word != NULL) {
            tokens[num_words++] = word;
            word = strtok(NULL, " \n");
        }
        
        // Exit shell if user types "exit"
        if (strcmp(tokens[0], "exit") == 0) {
            printf("Exiting shell...\n");
            exit(0);
        }
        
        // Fork a child process to execute the command
        pid = fork();       
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) {  // child process
            // Check if user typed "sum" command
            if (strcmp(tokens[0], "sum") == 0) {
                if (num_words != 3) {
                    printf("Usage: sum <a> <b>\n");
                    exit(1);
                }
                int a = atoi(tokens[1]);
                int b = atoi(tokens[2]);
                int result = a + b;
                printf("%d + %d = %d\n", a, b, result);
                exit(0);
            } else {
                // Command not recognized
                printf("Error: Command not recognized!\n");
                exit(1);
            }
        } else {     // parent process
            // Wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}