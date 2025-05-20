//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1000
#define MAX_ARGS 100

char **build_argv(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *args = strdup(command);
    char *token;

    token = strtok(args, " ");
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    free(args);
    return argv;
}

pid_t launch_process(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return pid;
    }
}

void print_process_info(pid_t pid) {
    char path[MAX_LINE_LEN];
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(path, "r");
    char cmdline[MAX_LINE_LEN];
    fgets(cmdline, MAX_LINE_LEN, fp);
    fclose(fp);

    char *token = strtok(cmdline, "\0");
    printf("PID: %d\n", pid);
    printf("Command: %s\n", token);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    pid_t pid = launch_process(build_argv(argv[1]));
    if (pid == -1) {
        return 1;
    }

    print_process_info(pid);

    return 0;
}