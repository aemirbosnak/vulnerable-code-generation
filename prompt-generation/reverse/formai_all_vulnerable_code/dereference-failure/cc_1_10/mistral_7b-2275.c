//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 256
#define SH_SIZE 1024

typedef struct {
    char cmd[SH_SIZE];
    char args[SH_SIZE][BUF_SIZE];
    int argc;
} shell_t;

void sanitize_input(char *input, char *output, size_t size) {
    size_t i, j;
    for (i = 0; i < size; i++) {
        if (input[i] == '\\') {
            if (i + 1 < size && input[i + 1] == '\\') {
                i++;
                continue;
            }
            output[i] = '\\';
            output[i + 1] = '\\';
            i++;
        } else {
            output[i] = input[i];
        }
    }
    output[size] = '\0';
}

shell_t *parse_command(char *line) {
    shell_t *shell = mmap(NULL, sizeof(shell_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    char *token;
    char *cmd_start = line;
    int arg_count = 0;

    sanitize_input(line, shell->cmd, sizeof(shell->cmd));

    token = strtok(cmd_start, " ");
    while (token != NULL) {
        if (arg_count >= sizeof(shell->args) / sizeof(shell->args[0])) {
            munmap(shell, sizeof(shell_t));
            return NULL;
        }
        sanitize_input(token, shell->args[arg_count], sizeof(shell->args[0]));
        arg_count++;
        token = strtok(NULL, " ");
    }
    shell->argc = arg_count + 1;

    return shell;
}

int execute_command(shell_t *shell) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        munmap(shell, sizeof(shell_t));
        return -1;
    }

    if (pid == 0) {
        if (execvp(shell->cmd, shell->args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    munmap(shell, sizeof(shell_t));
    return 0;
}

int main(int argc, char **argv) {
    char line[BUF_SIZE];
    int i;
    shell_t *shell;

    while (1) {
        printf(">>> ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';

        shell = parse_command(line);
        if (shell == NULL) {
            printf("Invalid command\n");
            continue;
        }

        for (i = 0; i < shell->argc; i++) {
            printf("Arg %d: %s\n", i, shell->args[i]);
        }

        execute_command(shell);
    }

    return 0;
}