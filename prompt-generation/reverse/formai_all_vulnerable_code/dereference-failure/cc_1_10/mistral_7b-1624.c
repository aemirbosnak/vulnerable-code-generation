//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct {
    char *command;
    int input_fd[2];
    int output_fd[2];
    pid_t pid;
} process;

void create_pipe(process *p) {
    if (pipe(p->input_fd) < 0 || pipe(p->output_fd) < 0) {
        perror("pipe failed");
        exit(1);
    }
}

int fork_and_exec(process *p, char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(p->input_fd[0]);
        close(p->output_fd[1]);
        return pid;
    }

    dup2(p->input_fd[0], STDIN_FILENO);
    dup2(p->output_fd[1], STDOUT_FILENO);
    close(p->input_fd[0]);
    close(p->input_fd[1]);
    close(p->output_fd[0]);
    close(p->output_fd[1]);

    execvp(p->command, args);
    perror("exec failed");
    exit(1);
}

void free_process(process *p) {
    close(p->input_fd[0]);
    close(p->input_fd[1]);
    close(p->output_fd[0]);
    close(p->output_fd[1]);
    free(p->command);
    free(p);
}

int main() {
    char *args[] = {"/bin/echo", "Hello, World!", NULL};
    process *child;
    int status;

    child = malloc(sizeof(process));
    create_pipe(child);
    child->command = strdup("/bin/cat");

    int pid = fork_and_exec(child, args);
    waitpid(pid, &status, 0);

    args[0] = "/bin/sed";
    args[1] = "s/World/Universe/g";
    args[2] = NULL;

    pid = fork_and_exec(child, args);
    waitpid(pid, &status, 0);

    args[0] = "/bin/wc";
    args[1] = "-l";
    args[2] = NULL;

    pid = fork_and_exec(child, args);
    waitpid(pid, &status, 0);

    free_process(child);

    return 0;
}