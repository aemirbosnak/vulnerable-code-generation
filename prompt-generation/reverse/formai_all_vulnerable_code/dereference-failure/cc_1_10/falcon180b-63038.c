//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define DELIM " "

// Function to execute a command and return its output as a string
char* execute_command(char* command) {
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        return strdup("");
    }

    char buffer[1024];
    char* result = NULL;
    size_t len = 0;

    while (fgets(buffer, sizeof(buffer), pipe)!= NULL) {
        len += strlen(buffer);
        result = realloc(result, len + 1);
        strcat(result, buffer);
    }

    pclose(pipe);
    return result;
}

// Function to split a string into an array of strings using a delimiter
char** split_string(char* str, char delim) {
    int count = 0;
    char* token = strtok(str, delim);

    while (token!= NULL) {
        count++;
        token = strtok(NULL, delim);
    }

    char** args = malloc(sizeof(char*) * (count + 1));
    count = 0;
    char* ptr = strtok(str, delim);

    while (ptr!= NULL) {
        args[count] = strdup(ptr);
        count++;
        ptr = strtok(NULL, delim);
    }
    args[count] = NULL;

    return args;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s command [argument1] [argument2]...\n", argv[0]);
        return 1;
    }

    char* command = argv[1];
    char** args = split_string(command, DELIM);

    if (args[0] == NULL) {
        printf("Invalid command.\n");
        return 1;
    }

    char* output = execute_command(command);
    printf("%s\n", output);

    for (int i = 0; args[i]!= NULL; i++) {
        free(args[i]);
    }
    free(args);

    return 0;
}