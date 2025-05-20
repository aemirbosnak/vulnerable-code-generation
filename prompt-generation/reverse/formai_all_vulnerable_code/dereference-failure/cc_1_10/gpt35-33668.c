//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LEN 512

char *read_line()
{
    char *line = malloc(sizeof(char) * MAX_LEN);
    fgets(line, MAX_LEN, stdin);

    return line;
}

char **parse_line(char *line)
{   
    char **tokens = malloc(sizeof(char*) * MAX_LEN);
    int i = 0;

    tokens[i] = strtok(line, " \n\r\t");
    
    while (tokens[i] != NULL) {
        i++;
        tokens[i] = strtok(NULL, " \n\r\t");
    }
    
    return tokens;
}

void execute(char **args)
{   
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork error");
    } else {
        wait(NULL);
    }
}

int main()
{
    char *line;
    char **args;
    int status;

    do {
        printf(">>> ");
        line = read_line();
        args = parse_line(line);
        execute(args);

        free(line);
        free(args);
    } while (status);
   
    return 0;
}