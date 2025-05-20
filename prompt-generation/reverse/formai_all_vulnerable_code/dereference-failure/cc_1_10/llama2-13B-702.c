//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_USERS 10
#define MAX_COMMANDS 5

// Define a struct to hold user information
struct user {
    char name[20];
    char password[20];
    int num_commands;
};

// Define an array to hold all users
struct user users[MAX_USERS];

// Define a function to add a new user
void add_user(char *name, char *password) {
    int i;

    // Check if the user already exists
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("User already exists! Please choose a different name.\n");
            return;
        }
    }

    // Add the new user to the array
    strcpy(users[i].name, name);
    strcpy(users[i].password, password);
    users[i].num_commands = 0;
    i++;
}

// Define a function to execute a command
void execute_command(int user_id, char *command) {
    // Check if the user has enough permissions
    if (users[user_id].num_commands >= MAX_COMMANDS) {
        printf("User has reached the maximum number of commands allowed.\n");
        return;
    }

    // Execute the command
    char *cmd = command;
    char *args[5];
    int argc = 0;

    // Parse the command and arguments
    while (cmd[0] != '\0') {
        if (cmd[0] == ' ') {
            args[argc++] = cmd;
            cmd = cmd + 1;
        } else {
            break;
        }
    }

    // Execute the command
    if (execvp(cmd, args) == -1) {
        perror("execvp failed");
        return;
    }

    // Increment the number of commands for the user
    users[user_id].num_commands++;
}

// Define the main function
int main() {
    int user_id;

    // Add some users
    add_user("Alice", "password123");
    add_user("Bob", "password456");
    add_user("Charlie", "password789");

    // Execute some commands
    execute_command(0, "ls -l");
    execute_command(1, "cd /home/Bob/Documents");
    execute_command(2, "rm -rf /home/Charlie/ TempFile.txt");

    // Print the number of commands for each user
    for (user_id = 0; user_id < MAX_USERS; user_id++) {
        printf("User %d has executed %d commands.\n", user_id, users[user_id].num_commands);
    }

    return 0;
}