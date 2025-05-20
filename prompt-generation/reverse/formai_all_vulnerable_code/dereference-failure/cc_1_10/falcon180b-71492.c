//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/wait.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 512

char *program_name;

void error(const char *fmt,...)
{
    va_list ap;
    fprintf(stderr, "%s: ", program_name);
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    exit(1);
}

int launch_shell(const char *shell)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == -1) {
        error("fork");
        return -1;
    } else if (pid == 0) {
        execlp(shell, shell, NULL);
        error("execlp");
        return -1;
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int launch_process(const char *command)
{
    char *argv[MAX_ARGUMENTS];
    int argc = 0;
    char *token;
    char *saveptr;
    argv[argc++] = strdup(command);
    token = strtok_r(argv[0], " ", &saveptr);
    while (token!= NULL) {
        argv[argc++] = strdup(token);
        token = strtok_r(NULL, " ", &saveptr);
    }
    argv[argc] = NULL;
    return launch_shell("/bin/sh");
}

void print_process_info(pid_t pid)
{
    char path[MAX_COMMAND_LENGTH];
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stdout, "Error: ");
    } else {
        char *line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, file);
        if (read!= -1) {
            line[strcspn(line, "\n")] = '\0';
            fprintf(stdout, "%s\n", line);
        }
        free(line);
        fclose(file);
    }
}

int main(int argc, char *argv[])
{
    program_name = argv[0];
    if (argc < 2) {
        fprintf(stdout, "Usage: %s PID\n", program_name);
        return 1;
    }
    int pid = atoi(argv[1]);
    if (kill(pid, 0) == -1) {
        if (errno == ESRCH) {
            fprintf(stdout, "Process not found.\n");
        } else {
            fprintf(stdout, "Error: %s\n", strerror(errno));
        }
        return 1;
    }
    print_process_info(pid);
    return 0;
}