//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Read a line from a file, ignoring leading whitespace and comments. */
char *read_line(FILE *fp) {
    size_t len = 0;
    char *line = NULL;
    int c;

    while ((c = getc(fp)) != EOF) {
        if (c == '\n') {
            break;
        } else if (c == ' ' || c == '\t') {
            continue;
        } else if (c == '#') {
            while ((c = getc(fp)) != '\n' && c != EOF)
                ;
            continue;
        } else {
            line = realloc(line, len + 2);
            line[len++] = c;
        }
    }

    if (line) {
        line[len] = '\0';
    }

    return line;
}

/* Parse a line into a list of words. */
char **parse_line(char *line) {
    size_t len = 0;
    char **words = NULL;
    char *word;

    while (*line) {
        while (*line && (*line == ' ' || *line == '\t'))
            line++;

        if (*line) {
            word = line;
            while (*line && *line != ' ' && *line != '\t')
                line++;
            if (*line) {
                *line++ = '\0';
            }
            words = realloc(words, (len + 1) * sizeof(char *));
            words[len++] = word;
        }
    }

    if (words) {
        words[len] = NULL;
    }

    return words;
}

/* Execute a command. */
int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        return -1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

/* Main loop. */
int main(int argc, char **argv) {
    FILE *fp;
    char *line;
    char **words;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        return 1;
    }

    while ((line = read_line(fp)) != NULL) {
        if ((words = parse_line(line)) == NULL) {
            perror("parse_line");
            continue;
        }

        for (i = 0; words[i]; i++) {
            if (strcmp(words[i], "load") == 0) {
                if (words[i + 1]) {
                    execute_command(words + i + 1);
                }
            } else if (strcmp(words[i], "sleep") == 0) {
                if (words[i + 1]) {
                    sleep(atoi(words[i + 1]));
                }
            } else if (strcmp(words[i], "exit") == 0) {
                break;
            }
        }

        free(words);
        free(line);
    }

    fclose(fp);

    return 0;
}