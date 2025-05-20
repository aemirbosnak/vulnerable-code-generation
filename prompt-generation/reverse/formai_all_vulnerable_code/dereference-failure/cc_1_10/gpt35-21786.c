//FormAI DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
/**It was a dark and stormy night, and Sherlock Holmes was hard at work solving a case. This time, his attention was focused on a mysterious system error that was causing chaos in the city.**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 256 

char *directory = "/usr/bin/"; //the directory to search for the executable

void sig_handler(int signo) { //the signal handler function
    if (signo == SIGINT) {
        printf("Ha! Caught you red-handed, my dear Watson. No need to Ctrl-C this program.\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) { //check if the number of arguments is correct
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    signal(SIGINT, sig_handler); //register the signal handler for Ctrl-C

    printf("Now let me get to the bottom of this system error.\n");
    printf("The clue lies in the binary file of \"%s\".\n", argv[1]);

    char *path = malloc(sizeof(char) * (strlen(directory) + strlen(argv[1]) + 2)); //allocate memory for the path string
    sprintf(path, "%s%s", directory, argv[1]); //append the directory and filename to the path

    if (access(path, F_OK) == -1) { //check if the file exists
        fprintf(stderr, "Error: the file \"%s\" does not exist in %s.\n", argv[1], directory);
        exit(1);
    }

    printf("The file \"%s\" exists in %s.\n", argv[1], directory);

    char *cmd = malloc(sizeof(char) * (strlen(path) + strlen("<command> ") + 1)); //allocate memory for the command string

    while (1) { //run an infinite loop to execute commands
        printf("> ");
        char buf[BUF_SIZE];
        fgets(buf, BUF_SIZE, stdin); //read the command from standard input

        if (buf[0] == '\n') { //if the user entered an empty command, continue to the next iteration
            continue;
        }

        char *nl = strchr(buf, '\n'); //remove the newline character from the end of the command string
        if (nl != NULL) {
            *nl = '\0';
        }

        sprintf(cmd, "<command> %s", path); //append the command to the command string

        if (system(cmd) == -1) { //execute the command and check for errors
            perror("Error executing system command");
        }
    }

    free(path);
    free(cmd);

    return 0;
}