//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_INPUT_LENGTH 1024 // Maximum length of command entered by user
#define MAX_HISTORY_LENGTH 20 // Maximum number of commands to be stored for history feature
#define MAX_COMMAND_LENGTH 200 // Maximum length of individual command stored in history

char *history[MAX_HISTORY_LENGTH]; // Array to store previous commands

/**
 * @brief Function to clear the screen
 *
 * @return void
 */
void clear_screen() {
    printf("\033[H\033[J"); // Escape sequence to clear the terminal
}

/**
 * @brief Function to read command entered by user
 *
 * @param input Command entered by user
 * @param len Length of command entered by user
 *
 * @return void
 */
void read_input(char *input, size_t len) {
    getline(&input, &len, stdin); // Using getline function to read the input from user
    input[strlen(input)-1] = '\0'; // Replacing newline character with null character
}

/**
 * @brief Function to add command to history
 *
 * @param command New command to be added
 *
 * @return void
 */
void add_to_history(char *command) {
    static int index = 0; // Static variable to keep track of index in history array

    // If history is full, remove oldest command
    if(index == MAX_HISTORY_LENGTH) {
        free(history[0]); // Free memory occupied by oldest command
        for(int i=1; i<MAX_HISTORY_LENGTH; i++) {
            history[i-1] = history[i]; // Shift all commands left by one
        }
        index--;
    }

    // Allocate memory for new command and add to history
    history[index] = (char*)malloc(MAX_COMMAND_LENGTH*sizeof(char));
    strcpy(history[index], command);
    index++;
}

/**
 * @brief Function to display previous commands from history
 *
 * @param count Number of previous commands to display
 *
 * @return void
 */
void print_history(int count) {
    int start = 0;
    if(count > MAX_HISTORY_LENGTH) { // If count is greater than MAX_HISTORY_LENGTH, display all commands
        count = MAX_HISTORY_LENGTH;
        start = 0;
    } else if(count > index) { // If count is greater than number of commands in history, display all commands
        count = index;
        start = 0;
    } else { // Display last 'count' commands
        start = index-count;
    }

    for(int i=start; i<index; i++) {
        printf("%d. %s\n", i+1, history[i]); // Display command with corresponding index
    }
}

int main() {
    char input[MAX_INPUT_LENGTH]; // Initial input buffer
    char *args[MAX_INPUT_LENGTH/2+1]; // Arguments to pass to execvp()
    int should_run = 1; // Flag to control the main loop
    int arg_count; // Number of arguments entered by user

    while(should_run) {
        clear_screen(); // Clear the screen before prompting for new input
        printf("%% "); // Prompt for new input
        fflush(stdout); // Flush output buffer

        read_input(input, MAX_INPUT_LENGTH); // Read input from user
        if(strlen(input) == 0) { // If input is empty, skip to next iteration of loop
            continue;
        }

        add_to_history(input); // Add input to history
        arg_count = 0;

        // Parse input and store arguments in args array
        char *token = strtok(input, " ");
        while(token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // Set last argument to NULL as required by execvp()

        // Check if user wants to exit the shell
        if(strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        // Check if user wants to display previous commands from history
        if(strcmp(args[0], "history") == 0 && arg_count == 1) {
            print_history(MAX_HISTORY_LENGTH); // Display all commands stored in history
            continue;
        } else if(strcmp(args[0], "history") == 0 && arg_count == 2) {
            print_history(atoi(args[1])); // Display specified number of previous commands from history
            continue;
        }

        pid_t pid = fork(); // Fork a child process to execute the command
        if(pid < 0) { // Forking failed
            printf("Fork failed!\n");
        } else if(pid == 0) { // Child process
            if(execvp(args[0], args) < 0) { // Execute the command using execvp()
                printf("Command not found!\n"); // If command not found, display an error
            }
            exit(0); // Exit the child process
        } else { // Parent process
            wait(NULL); // Wait for child process to terminate
        }
    }

    // Free memory occupied by commands stored in history
    for(int i=0; i<index; i++) {
        free(history[i]);
    }

    return 0;
}