//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to split the input command into words
char** split_command(char* line) {
    char** words = malloc(sizeof(char*) * 10);  // Allocate memory for 10 words
    int num_words = 0;

    char* word = strtok(line, " ");  // Get the first word
    while (word != NULL) {
        words[num_words] = word;  // Add the word to the array
        num_words++;

        if (num_words >= 10) {  // If we have 10 words, reallocate memory for more
            words = realloc(words, sizeof(char*) * (num_words + 10));
        }

        word = strtok(NULL, " ");  // Get the next word
    }

    words[num_words] = NULL;  // Add a NULL terminator to the end of the array
    return words;
}

// Function to execute a command
void execute_command(char** words) {
    pid_t pid = fork();  // Create a child process

    if (pid == 0) {  // Child process
        execvp(words[0], words);  // Execute the command
        exit(EXIT_FAILURE);  // Exit if the command fails
    } else {  // Parent process
        waitpid(pid, NULL, 0);  // Wait for the child process to finish
    }
}

int main() {
    char line[1024];  // Buffer to store the input command

    while (1) {
        printf("> ");  // Print the prompt
        fgets(line, sizeof(line), stdin);  // Read the input command

        if (strcmp(line, "exit\n") == 0) {  // Check if the command is "exit"
            break;  // Exit the shell
        }

        char** words = split_command(line);  // Split the command into words
        execute_command(words);  // Execute the command
    }

    return 0;
}