//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <errno.h>

typedef struct {
    char **argv;
    size_t argc;
    size_t alloc;
} arglist_t;

static void arglist_init(arglist_t *args)
{
    args->argv = NULL;
    args->argc = 0;
    args->alloc = 0;
}

static void arglist_free(arglist_t *args)
{
    for (size_t i = 0; i < args->argc; i++)
        free(args->argv[i]);
    free(args->argv);
}

static int arglist_append(arglist_t *args, const char *arg)
{
    if (args->argc >= args->alloc) {
        size_t new_alloc = args->alloc ? args->alloc * 2 : 16;
        char **new_argv = realloc(args->argv, new_alloc * sizeof(*args->argv));
        if (!new_argv)
            return -1;
        args->argv = new_argv;
        args->alloc = new_alloc;
    }
    args->argv[args->argc++] = strdup(arg);
    return 0;
}

static int arglist_parse(arglist_t *args, const char *line)
{
    const char *start = line;
    while (*start) {
        while (*start && isspace(*start))
            start++;
        if (!*start)
            break;
        const char *end = start;
        while (*end && !isspace(*end))
            end++;
        if (arglist_append(args, strndup(start, end - start)) < 0)
            return -1;
        start = end;
    }
    return 0;
}

static int run_command(const char *cmd, arglist_t *args)
{
    pid_t pid = fork();
    if (pid < 0)
        err(1, "fork");
    else if (pid == 0) {
        if (execvp(cmd, args->argv) < 0)
            err(1, "execvp");
    } else {
        int status;
        if (waitpid(pid, &status, 0) < 0)
            err(1, "waitpid");
        return WEXITSTATUS(status);
    }
    return 0;
}

int main(int argc, char **argv)
{
    arglist_t args;
    char line[1024];

    arglist_init(&args);
    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin))
            break;
        arglist_parse(&args, line);
        if (args.argc > 0) {
            if (!strcmp(args.argv[0], "exit"))
                break;
            else if (!strcmp(args.argv[0], "run")) {
                if (args.argc < 2) {
                    fprintf(stderr, "run: missing command\n");
                    continue;
                }
                run_command(args.argv[1], &args);
            }
            else {
                fprintf(stderr, "%s: unrecognized command\n", args.argv[0]);
                continue;
            }
        }
        arglist_free(&args);
    }
    arglist_free(&args);
    return 0;
}