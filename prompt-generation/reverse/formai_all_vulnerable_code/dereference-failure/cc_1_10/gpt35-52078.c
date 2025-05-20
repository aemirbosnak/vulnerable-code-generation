//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_TOKEN_NUM 64

char pwd[MAX_BUFFER_SIZE];

void shell_loop();

char *read_line();

char **parse_line(char *line);

int execute_command(char **args);

int cd(char **args);

int pwd_cmd(char **args);

int echo(char **args);

int ls(char **args);

int mkdir_cmd(char **args);

int rmdir_cmd(char **args);

int rm_cmd(char **args);

int touch(char **args);

int exit_shell(char **args);

char* trim(char *s);

int main(int argc, char **argv) {
    // Initialize PWD variable
    if (getcwd(pwd, sizeof(pwd)) == NULL) {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }

    // Start shell loop
    shell_loop();

    return EXIT_SUCCESS;
}

void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("$%s> ", pwd);
        fflush(stdout);

        line = read_line();
        args = parse_line(line);
        status = execute_command(args);

        free(line);
        free(args);
    } while (status);
}

char *read_line() {
    int position = 0;
    int max_buffer_size = MAX_BUFFER_SIZE;
    char *buffer = malloc(sizeof(char) * max_buffer_size);
    int c;

    if (!buffer) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF) {
            exit_shell(NULL);
        } else if (c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }

        position++;

        if (position >= max_buffer_size) {
            max_buffer_size += MAX_BUFFER_SIZE;
            buffer = realloc(buffer, max_buffer_size);

            if (!buffer) {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **parse_line(char *line) {
    int position = 0;
    int max_token_size = MAX_TOKEN_SIZE;
    int max_token_num = MAX_TOKEN_NUM;
    char **tokens = malloc(max_token_num * sizeof(char *));
    char *token, **tokens_backup;

    if (!tokens) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= max_token_num) {
            max_token_num += MAX_TOKEN_NUM;
            tokens_backup = tokens;
            tokens = realloc(tokens, max_token_num * sizeof(char *));

            if (!tokens) {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }

    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    int i;

    if (args[0] == NULL) {
        return 1;
    }

    char *command = args[0];

    if (strcmp(command, "cd") == 0) {
        return cd(args);
    } else if (strcmp(command, "pwd") == 0) {
        return pwd_cmd(args);
    } else if (strcmp(command, "echo") == 0) {
        return echo(args);
    } else if (strcmp(command, "ls") == 0) {
        return ls(args);
    } else if (strcmp(command, "mkdir") == 0) {
        return mkdir_cmd(args);
    } else if (strcmp(command, "rmdir") == 0) {
        return rmdir_cmd(args);
    } else if (strcmp(command, "rm") == 0) {
        return rm_cmd(args);
    } else if (strcmp(command, "touch") == 0) {
        return touch(args);
    } else if (strcmp(command, "exit") == 0) {
        return exit_shell(args);
    }

    // Execute non built-in commands
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(command, args) == -1) {
            perror("Shell");
        }

        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("Shell");
        } else {
            if (getcwd(pwd, sizeof(pwd)) == NULL) {
                perror("getcwd() error");
                return EXIT_FAILURE;
            }
        }
    }

    return 1;
}

int pwd_cmd(char **args) {
    printf("%s\n", pwd);
    return 1;
}

int echo(char **args) {
    for (int i = 1; args[i]; i++) {
        printf("%s ", trim(args[i]));
    }
    printf("\n");
    return 1;
}

int ls(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *ls_args[] = {"ls", "-lh", NULL};
        if (args[1]) {
            ls_args[1] = args[1];
            ls_args[2] = NULL;
        }

        if (execvp("ls", ls_args) == -1) {
            perror("Shell");
        }

        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Shell");
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int mkdir_cmd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: expected argument to \"mkdir\"\n");
    } else {
        char *mkdir_args[] = {"mkdir", args[1], NULL};
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp("mkdir", mkdir_args) == -1) {
                perror("Shell");
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("Shell");
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

int rmdir_cmd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: expected argument to \"rmdir\"\n");
    } else {
        char *rmdir_args[] = {"rmdir", args[1], NULL};
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp("rmdir", rmdir_args) == -1) {
                perror("Shell");
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("Shell");
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

int rm_cmd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: expected argument to \"rm\"\n");
    } else {
        char *rm_args[] = {"rm", "-rf", args[1], NULL};
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp("rm", rm_args) == -1) {
                perror("Shell");
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("Shell");
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

int touch(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Shell: expected argument to \"touch\"\n");
    } else {
        char *touch_args[] = {"touch", args[1], NULL};
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp("touch", touch_args) == -1) {
                perror("Shell");
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("Shell");
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

int exit_shell(char **args) {
    printf("Exiting shell...\n");
    return 0;
}

// Trim leading and trailing whitespace from a string
char* trim(char *s) {
    while (isspace(*s)) s++;
    char *end = s + strlen(s) - 1;
    while (end > s && isspace(*end)) end--;
    *(end + 1) = '\0';
    return s;
}