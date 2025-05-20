//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_LINE_LEN 1024

struct command {
    char *argv[MAX_ARGS];
    int argc;
};

struct shell {
    char *prompt;
    struct command *cmd;
};

void
shell_init(struct shell *s) {
    s->prompt = "$ ";
    s->cmd = malloc(sizeof(struct command));
}

void
shell_free(struct shell *s) {
    free(s->prompt);
    free(s->cmd);
}

int
shell_parse(struct shell *s, char *line) {
    int i = 0;
    char *p = strtok(line, " \t\n");
    while (p != NULL && i < MAX_ARGS) {
        s->cmd->argv[i++] = p;
        p = strtok(NULL, " \t\n");
    }
    s->cmd->argc = i;
    return 0;
}

int
shell_execute(struct shell *s) {
    if (strcmp(s->cmd->argv[0], "exit") == 0) {
        return 1;
    } else {
        int status;
        pid_t pid = fork();
        if (pid == 0) {
            execvp(s->cmd->argv[0], s->cmd->argv);
            perror("execvp");
            exit(1);
        } else {
            wait(&status);
            return WEXITSTATUS(status);
        }
    }
}

int
main(int argc, char *argv[]) {
    struct shell s;
    char line[MAX_LINE_LEN];

    shell_init(&s);

    while (1) {
        printf("%s", s.prompt);
        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            printf("\n");
            break;
        }
        shell_parse(&s, line);
        if (shell_execute(&s)) {
            break;
        }
    }

    shell_free(&s);

    return 0;
}