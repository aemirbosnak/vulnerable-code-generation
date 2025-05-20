//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
/* Welcome to the Statistical Style Shell program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LENGTH 1024 /* Maximum input length */

int main(void) {

    char *cmd; /* user input */
    char *args[MAX_LENGTH/2 + 1]; /* command arguments */
    int should_run = 1; /* flag to determine when to exit program */
    char cwd[MAX_LENGTH]; /* current working directory */

    while (should_run) {
        printf("stat>$ "); /* shell prompt */
        fflush(stdout);

        /* read user input */
        cmd = (char*)malloc(MAX_LENGTH*sizeof(char));
        fgets(cmd,MAX_LENGTH,stdin);
        cmd[strlen(cmd)-1] = '\0'; /* remove trailing newline */

        /* tokenize input */
        char *token;
        int i = 0;
        token = strtok(cmd," ");
        while(token!=NULL) {
            args[i] = token;
            token = strtok(NULL," ");
            i++;
        }
        args[i] = NULL; /* set last argument to NULL */

        if(strcmp(args[0],"exit")==0) { /* exit program */
            should_run = 0;
        }
        else if(strcmp(args[0],"cd")==0) { /* change directory */
            char *path = args[1];
            if(path==NULL) { /* go to home directory */
                chdir(getenv("HOME"));
            }
            else if(chdir(path)==-1) {
                perror("stat");
            }
        }
        else { /* execute external command */
            pid_t pid = fork(); /* create child process */
            if(pid==0) { /* child process */
                if(execvp(args[0],args)==-1) { /* execute command */
                    perror("stat");
                }
                exit(EXIT_FAILURE); /* exit child process */
            }
            else if(pid>0) { /* parent process */
                wait(NULL); /* wait for child process */
            }
            else { /* error */
                perror("stat");
            }
        }

        getcwd(cwd, sizeof(cwd)); /* get current working directory */
        printf("\n%s $ ",cwd); /* display current working directory */
        fflush(stdout);
    }

    printf("\nShutting down...\n");

    return EXIT_SUCCESS;
}