//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096
#define DELIMITERS " \t\n"

int main() {
    // Variable Declarations
    char buffer[BUFFER_SIZE];
    char *args[BUFFER_SIZE / 2];
    int status;
    
    // Main Loop
    while (1) {
	// Prompt
    	printf("--> ");

	// Read line
    	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
    	    break;
    	}

	// Parse line
    	char *token = strtok(buffer, DELIMITERS);
    	int i = 0;
    	while (token != NULL) {
    	    args[i++] = token;
    	    token = strtok(NULL, DELIMITERS);
    	}
    	args[i] = NULL;

	// Check for built-in commands
    	if (strcmp(args[0], "exit") == 0) {
    	    exit(0);
    	}
	else if (strcmp(args[0], "cd") == 0) {
    	    if (args[1] != NULL) {
    		chdir(args[1]);
    	    }
    	}
	else {
	    // Execute command
    	    pid_t pid = fork();
    	    if (pid == 0) {
    		execvp(args[0], args);
			// Only reaches here if execvp fails
			perror(args[0]);
			exit(1);
    	    }
	    else {
    		wait(&status);
    	    }
	}
    }

    return 0;
}