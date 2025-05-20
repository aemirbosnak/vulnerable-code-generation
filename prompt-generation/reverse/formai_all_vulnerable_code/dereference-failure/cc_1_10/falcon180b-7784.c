//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 80
#define MAX_NUM_ARGS 20

void main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Not enough arguments.\n");
        exit(1);
    }

    char *input_str = argv[1];
    int num_args = 0;
    char **args = (char **) malloc(MAX_NUM_ARGS * sizeof(char *));

    // Parse input string into arguments
    char *token = strtok(input_str, " ");
    while (token!= NULL) {
        if (num_args >= MAX_NUM_ARGS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " ");
    }

    // Check if correct number of arguments were provided
    if (num_args < 2) {
        printf("Error: Not enough arguments.\n");
        exit(1);
    }

    // Perform operation on arguments
    int result = 0;
    if (strcmp(args[0], "add") == 0) {
        result = atoi(args[1]) + atoi(args[2]);
    } else if (strcmp(args[0], "subtract") == 0) {
        result = atoi(args[1]) - atoi(args[2]);
    } else {
        printf("Error: Invalid operation.\n");
        exit(1);
    }

    // Print result
    printf("Result: %d\n", result);
    exit(0);
}