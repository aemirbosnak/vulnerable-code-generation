//Falcon-180B DATASET v1.0 Category: System administration ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int background;
} command_t;

int main() {
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];
    char input[100];
    char *token;
    int i, j, pid, status;

    while(1) {
        printf("Enter command (or type 'exit' to quit): ");
        fgets(input, 100, stdin);
        token = strtok(input, " ");
        if(strcmp(token, "exit") == 0) {
            break;
        }
        num_commands++;
        if(num_commands >= MAX_COMMANDS) {
            printf("Too many commands.\n");
            exit(1);
        }
        commands[num_commands-1].command = malloc(strlen(input)+1);
        strcpy(commands[num_commands-1].command, input);
        commands[num_commands-1].arguments = malloc(MAX_ARGUMENTS*sizeof(char*));
        j = 0;
        token = strtok(input, " ");
        while(token!= NULL) {
            commands[num_commands-1].arguments[j++] = malloc(strlen(token)+1);
            strcpy(commands[num_commands-1].arguments[j-1], token);
            token = strtok(NULL, " ");
        }
        commands[num_commands-1].arguments[j] = NULL;
    }

    for(i=0; i<num_commands; i++) {
        pid = fork();
        if(pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        }
        if(pid == 0) {
            if(commands[i].background == 0) {
                execvp(commands[i].command, commands[i].arguments);
            } else {
                setsid();
                for(j=0; commands[i].arguments[j]!= NULL; j++) {
                    fprintf(stdout, "%s ", commands[i].arguments[j]);
                }
                fprintf(stdout, "\n");
                exit(0);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}