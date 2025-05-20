//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS_LENGTH 256
#define MAX_ENV_LENGTH 4096

int launch_shell(char *args[]) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking\n");
        return 1;
    } else if (pid == 0) {
        if (execve("/bin/bash", args, NULL) == -1) {
            fprintf(stderr, "Error executing /bin/bash\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS_LENGTH];
    char *envp[MAX_ENV_LENGTH];
    int status;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    strcpy(input_buffer, argv[1]);
    strcat(input_buffer, " ");

    for (i = 2; i < argc; i++) {
        strcat(input_buffer, argv[i]);
        strcat(input_buffer, " ");
    }

    args[0] = "/bin/bash";
    args[1] = "-c";
    args[2] = input_buffer;
    args[3] = NULL;

    envp[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
    envp[1] = NULL;

    status = launch_shell(args);

    if (status == 0) {
        fprintf(stdout, "Command executed successfully\n");
    } else {
        fprintf(stderr, "Command execution failed\n");
    }

    return status;
}