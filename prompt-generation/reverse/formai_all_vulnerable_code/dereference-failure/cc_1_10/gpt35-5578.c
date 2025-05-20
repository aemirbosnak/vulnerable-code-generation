//FormAI DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare the data structure that holds the parsed command
typedef struct {
    char* command;
    char** arguments;
    int arguments_count;
} ParsedCommand;

//Declare the function that will parse the command
ParsedCommand parse_command(char* command);

int main() {
    char input[1000];
    while (1) {
        printf("> ");
        fgets(input, 1000, stdin);

        //Remove the trailing newline character from the input
        strtok(input, "\n");

        //If the user typed exit, exit the program
        if (strcmp(input, "exit") == 0) break;

        ParsedCommand parsed_command = parse_command(input);

        printf("Command: %s\n", parsed_command.command);
        printf("Arguments Count: %d\n", parsed_command.arguments_count);
        printf("Arguments:\n");
        for (int i = 0; i < parsed_command.arguments_count; i++) {
            printf("%s\n", parsed_command.arguments[i]);
        }

        //Free the allocated memory for the parsed arguments
        for (int i = 0; i < parsed_command.arguments_count; i++) {
            free(parsed_command.arguments[i]);
        }
    }
    return 0;
}

ParsedCommand parse_command(char* command) {
    ParsedCommand parsed_command;

    //Tokenize the input string using space as the delimiter
    char* token = strtok(command, " ");

    //The first token is the command
    parsed_command.command = strdup(token);

    //Initialize the arguments count to 0
    parsed_command.arguments_count = 0;

    //Initialize the arguments array to NULL
    parsed_command.arguments = NULL;

    //Keep tokenizing the input string until there are no more tokens
    while (token != NULL) {
        //Allocate memory for the new argument
        char* argument = malloc((strlen(token) + 1) * sizeof(char));

        //Copy the token to the new argument
        strcpy(argument, token);

        //Increase the arguments count
        parsed_command.arguments_count++;

        //Reallocate memory for the arguments array
        parsed_command.arguments = realloc(parsed_command.arguments, parsed_command.arguments_count * sizeof(char*));

        //Set the new argument in the arguments array
        parsed_command.arguments[parsed_command.arguments_count - 1] = argument;

        //Tokenize the input string again
        token = strtok(NULL, " ");
    }

    //Return the parsed command
    return parsed_command;
}