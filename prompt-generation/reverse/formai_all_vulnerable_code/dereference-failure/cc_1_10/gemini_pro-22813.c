//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
// Embark on a journey through the elusive world of the Unix-like shell with our inquisitive C program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define our shell's repertoire of commands.
char *commands[] = {"cd", "ls", "pwd", "mkdir", "rmdir", "touch", "rm", "cat", "echo", "exit", NULL};

// The command line, where our user's desires are expressed.
char *cmdline;

// A buffer to capture the user's command and arguments.
char buffer[1024];

// Parse the command line into an array of strings.
char **parse_line(char *line) {
    char **argv = malloc(sizeof(char *) * 10);
    int argc = 0;

    char *token = strtok(line, " ");
    while (token) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    argv[argc] = NULL;
    return argv;
}

// Execute the command specified by the user.
int execute_command(char **argv) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror(argv[0]);
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}

// Present the user with a welcoming prompt.
void prompt() {
    printf("shell> ");
    fflush(stdout);
}

// The main event, where the shell interacts with the user.
int main() {
    while (1) {
        prompt();

        // Capture the user's command and arguments.
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }

        // Parse the command line.
        char **argv = parse_line(buffer);

        // Identify the command to be executed.
        int i;
        for (i = 0; commands[i] != NULL; i++) {
            if (strcmp(argv[0], commands[i]) == 0) {
                break;
            }
        }

        // Execute the specified command.
        switch (i) {
            case 0:  // cd
                chdir(argv[1]);
                break;
            case 1:  // ls
                system("ls");
                break;
            case 2:  // pwd
                system("pwd");
                break;
            case 3:  // mkdir
                mkdir(argv[1], 0755);
                break;
            case 4:  // rmdir
                rmdir(argv[1]);
                break;
            case 5:  // touch
                creat(argv[1], 0644);
                break;
            case 6:  // rm
                remove(argv[1]);
                break;
            case 7:  // cat
                system(argv[1]);
                break;
            case 8:  // echo
                printf("%s\n", argv[1]);
                break;
            case 9:  // exit
                exit(0);
            default:
                printf("Unrecognized command: %s\n", argv[0]);
                break;
        }
    }

    return 0;
}