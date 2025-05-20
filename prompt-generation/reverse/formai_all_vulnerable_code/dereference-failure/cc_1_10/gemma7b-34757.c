//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

typedef struct ShellState {
    char **cmd_history;
    int cmd_history_size;
    char prompt[MAX_CMD_LEN];
    char current_cmd[MAX_CMD_LEN];
    int current_cmd_len;
} ShellState;

ShellState shell_state;

void shell_init() {
    shell_state.cmd_history = NULL;
    shell_state.cmd_history_size = 0;
    shell_state.prompt[0] = '$';
    shell_state.prompt[1] = '\0';
    shell_state.current_cmd[0] = '\0';
    shell_state.current_cmd_len = 0;
}

void shell_prompt() {
    printf("%s", shell_state.prompt);
}

void shell_read_cmd() {
    shell_state.current_cmd_len = 0;
    getline(shell_state.current_cmd, MAX_CMD_LEN, stdin);
    shell_state.current_cmd_len = strlen(shell_state.current_cmd);
    shell_state.cmd_history = realloc(shell_state.cmd_history, (shell_state.cmd_history_size + 1) * sizeof(char *));
    shell_state.cmd_history[shell_state.cmd_history_size++] = shell_state.current_cmd;
}

void shell_execute() {
    int pid;
    char **cmd_args;
    shell_state.current_cmd[shell_state.current_cmd_len - 1] = '\0';
    cmd_args = shell_state.current_cmd;
    pid = fork();
    if (pid == 0) {
        execvp(cmd_args[0], cmd_args);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Error executing command");
    }
}

int main() {
    shell_init();
    while (1) {
        shell_prompt();
        shell_read_cmd();
        shell_execute();
    }
    return 0;
}