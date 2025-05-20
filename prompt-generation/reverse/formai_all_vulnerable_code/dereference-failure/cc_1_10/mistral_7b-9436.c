//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CMD_LEN 256
#define MAX_NUM_CMDS 64
#define MAX_NUM_TOKENS 32

typedef struct {
    char **tokens;
    int num_tokens;
} cmd_t;

void sigint_handler(int sig) {
    printf("\n[Ruinshell] Interrupted by user, exiting...\n");
    exit(0);
}

void parse_cmd(cmd_t *cmd, char *line) {
    char *token, *save_ptr;
    int i = 0;

    cmd->num_tokens = 0;

    token = strtok_r(line, " \t\r\n", &save_ptr);
    while (token != NULL) {
        cmd->tokens[i] = token;
        i++;
        cmd->num_tokens++;

        token = strtok_r(NULL, " \t\r\n", &save_ptr);
    }

    cmd->tokens[i] = NULL;
}

void exec_cmd(cmd_t *cmd) {
    pid_t pid;
    int status;

    if (strcmp(cmd->tokens[0], "cd") == 0) {
        if (chdir(cmd->tokens[1]) != 0) {
            perror("[Ruinshell] Error changing directory");
            exit(1);
        }
        return;
    } else if (strcmp(cmd->tokens[0], "ls") == 0) {
        system("ls");
        return;
    } else if (strcmp(cmd->tokens[0], "echo") == 0) {
        int i;
        for (i = 1; i < cmd->num_tokens; i++) {
            printf("%s ", cmd->tokens[i]);
        }
        printf("\n");
        return;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(cmd->tokens[0], cmd->tokens) < 0) {
            perror("[Ruinshell] Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        perror("[Ruinshell] Error forking process");
        exit(1);
    }
}

int main() {
    cmd_t cmd;
    char line[MAX_CMD_LEN];
    int i;

    signal(SIGINT, sigint_handler);

    while (1) {
        printf("\n[Ruinshell] > ");
        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "quit\n") == 0) {
            break;
        }

        parse_cmd(&cmd, line);
        exec_cmd(&cmd);

        for (i = 0; i < cmd.num_tokens; i++) {
            free(cmd.tokens[i]);
        }
        free(cmd.tokens);
    }

    return 0;
}