//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

int main()
{
    char *command;
    char *parsed_command[MAX_NUM_ARGUMENTS];
    char prompt[] = ">>>";
    char *history[20];
    int i, num_commands = 0, choice = -1;
    int exit_called = 0, run_history = 0;

    while(!exit_called)
    {
        // Print the prompt
        printf("%s ", prompt);
        
        // Read input from user
        command = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        // Split the input into separate arguments
        char *token = strtok(command, " \n");
        int argument_count = 0;
        while(token != NULL && argument_count < MAX_NUM_ARGUMENTS-1)
        {
            parsed_command[argument_count] = token;
            token = strtok(NULL, " \n");
            argument_count++;
        }
        parsed_command[argument_count] = NULL;

        // Check if history command is called
        if(argument_count == 1 && strcmp(parsed_command[0], "history") == 0)
        {
            if(num_commands == 0)
            {
                printf("No commands in history.\n");
            }
            else
            {
                for(i=0; i<num_commands; i++)
                {
                    printf("%d %s", i, history[i]);
                }
            }
            run_history = 1;
        }
        // Check if numeric value is entered after ! command
        else if(parsed_command[0][0] == '!' && strlen(parsed_command[0]) > 1)
        {
            for(i=1; i<strlen(parsed_command[0]); i++)
            {
                if(parsed_command[0][i] < '0' || parsed_command[0][i] > '9')
                {
                    printf("Invalid history command.\n");
                    run_history = 1;
                    break;
                }
            }
            if(run_history == 0)
            {
                choice = atoi(parsed_command[0]+1);
                if(choice >= 0 && choice < num_commands)
                {
                    // Copy previous command to current command
                    strcpy(command, history[choice]);
                    argument_count = 0;
                    token = strtok(command, " \n");
                    while(token != NULL && argument_count < MAX_NUM_ARGUMENTS-1)
                    {
                        parsed_command[argument_count] = token;
                        token = strtok(NULL, " \n");
                        argument_count++;
                    }
                    parsed_command[argument_count] = NULL;
                }
                else
                {
                    printf("Invalid history command.\n");
                    run_history = 1;
                }
            }
        }

        if(run_history == 0)
        {
            // Add command to history
            history[num_commands % 20] = command;
            num_commands++;

            // Check for exit command
            if(strcmp(parsed_command[0], "exit") == 0)
            {
                exit_called = 1;
            }
            else
            {
                // Create child process to execute the command
                pid_t pid = fork();
                if(pid == 0)
                {
                    // Execute the command
                    int exec_result = execvp(parsed_command[0], parsed_command);
                    if(exec_result == -1)
                    {
                        printf("Unrecognized command.\n");
                    }
                    exit(0);
                }
                else
                {
                    // Wait for child process to finish
                    waitpid(pid, NULL, 0);
                }
            }
        }

        run_history = 0;
    }

    printf("Exiting shell.\n");

    return 0;
}