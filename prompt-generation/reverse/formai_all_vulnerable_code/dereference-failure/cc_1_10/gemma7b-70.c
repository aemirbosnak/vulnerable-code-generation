//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define HIST_SIZE 10

typedef struct CmdHist {
    char **cmd_history;
    int hist_size;
    int hist_pos;
} CmdHist;

void hist_init(CmdHist *hist) {
    hist->cmd_history = NULL;
    hist->hist_size = HIST_SIZE;
    hist->hist_pos = 0;
}

void hist_add(CmdHist *hist, char *cmd) {
    if (hist->cmd_history == NULL) {
        hist->cmd_history = malloc(sizeof(char *) * hist->hist_size);
    }

    hist->cmd_history[hist->hist_pos++] = strdup(cmd);

    if (hist->hist_pos >= hist->hist_size) {
        hist->hist_pos = hist->hist_size - 1;
    }
}

int main() {
    CmdHist hist;
    hist_init(&hist);

    char cmd[MAX_CMD_LEN];

    printf("Welcome to the Zork Shell!\n");

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        hist_add(&hist, cmd);

        // Execute the command here
        printf("Command: %s\n", cmd);
    }

    return 0;
}