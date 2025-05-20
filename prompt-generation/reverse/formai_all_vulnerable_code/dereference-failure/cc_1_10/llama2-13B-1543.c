//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct cmd {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *shm_name = "/tmp/ken_thompson";
    int shm_id = shmget(IPC_PRIVATE, sizeof(struct cmd), IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        return 1;
    }

    struct cmd *cmd = shmat(shm_id, NULL, 0);
    if (cmd == (struct cmd *) -1) {
        perror("shmat");
        return 1;
    }

    while (1) {
        printf("$ ");
        fgets(cmd->name, MAX_CMD_LEN, stdin);
        cmd->args[0] = cmd->name;
        int i = 1;
        while (i < MAX_ARGS && cmd->args[i] != NULL) {
            fgets(cmd->args[i], MAX_CMD_LEN, stdin);
            i++;
        }

        if (cmd->args[i] == NULL) {
            break;
        }

        // Execute the command
        if (execv(cmd->name, cmd->args) == -1) {
            perror("execv");
            break;
        }
    }

    return 0;
}