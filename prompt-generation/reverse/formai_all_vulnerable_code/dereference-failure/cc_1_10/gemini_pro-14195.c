//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

struct cmd {
    char *name;
    char **args;
    int argc;
};

struct sh {
    char **argv;
    int argc;
    struct cmd *cmds;
    int cmd_count;
};

struct sh *sh_new(int argc, char **argv) {
    struct sh *sh = malloc(sizeof(struct sh));
    sh->argv = argv;
    sh->argc = argc;
    sh->cmds = NULL;
    sh->cmd_count = 0;
    return sh;
}

void sh_free(struct sh *sh) {
    for (int i = 0; i < sh->cmd_count; i++) {
        free(sh->cmds[i].name);
        for (int j = 0; j < sh->cmds[i].argc; j++) {
            free(sh->cmds[i].args[j]);
        }
        free(sh->cmds[i].args);
    }
    free(sh->cmds);
    free(sh);
}

int sh_parse(struct sh *sh) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, stdin)) != -1) {
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }
        if (strcmp(line, "quit") == 0) {
            return 0;
        }
        struct cmd *cmd = malloc(sizeof(struct cmd));
        cmd->name = strtok(line, " ");
        cmd->argc = 0;
        cmd->args = malloc(sizeof(char *));
        while ((cmd->args[cmd->argc] = strtok(NULL, " ")) != NULL) {
            cmd->argc++;
            cmd->args = realloc(cmd->args, sizeof(char *) * (cmd->argc + 1));
        }
        sh->cmds = realloc(sh->cmds, sizeof(struct cmd) * (sh->cmd_count + 1));
        sh->cmds[sh->cmd_count++] = *cmd;
    }
    return 1;
}

int sh_run(struct sh *sh) {
    for (int i = 0; i < sh->cmd_count; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            execvp(sh->cmds[i].name, sh->cmds[i].args);
            perror("execvp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    struct sh *sh = sh_new(argc, argv);
    if (sh_parse(sh)) {
        sh_run(sh);
    }
    sh_free(sh);
    return 0;
}