//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>

#define MAX_LINE 1024

typedef struct {
    jmp_buf buf;
    char line[MAX_LINE];
} line_t;

static void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("Interrupted by SIGINT\n");
    } else if (signo == SIGSEGV) {
        printf("Segmentation fault occurred\n");
    } else {
        printf("Unknown signal %d\n", signo);
    }
    exit(1);
}

static void read_line(FILE *fp, line_t *ln) {
    char c;
    size_t len = 0;

    if (setjmp(ln->buf) == 0) {
        while ((c = fgetc(fp))!= EOF && len < MAX_LINE - 1) {
            ln->line[len++] = c;
            if (c == '\n') {
                break;
            }
        }
        if (ferror(fp)) {
            printf("Error reading file: %s\n", strerror(errno));
            exit(1);
        }
        ln->line[len] = '\0';
    } else {
        printf("Interrupted by user\n");
    }
}

static void process_line(line_t *ln) {
    char *token;
    int count = 0;

    token = strtok(ln->line, " ");
    while (token!= NULL) {
        printf("%s ", token);
        count++;
        if (count >= 10) {
            printf("\n");
            break;
        }
        token = strtok(NULL, " ");
    }
    if (ferror(stdin)) {
        printf("Error reading input: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    line_t ln;
    FILE *fp;

    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        printf("Error setting signal handler: %s\n", strerror(errno));
        exit(1);
    }
    if (signal(SIGSEGV, sig_handler) == SIG_ERR) {
        printf("Error setting signal handler: %s\n", strerror(errno));
        exit(1);
    }

    if ((fp = fopen("input.txt", "r")) == NULL) {
        printf("Error opening input file: %s\n", strerror(errno));
        exit(1);
    }

    if (setjmp(ln.buf) == 0) {
        while (fgets(ln.line, MAX_LINE, fp)!= NULL) {
            read_line(fp, &ln);
        }
    } else {
        fclose(fp);
    }

    return 0;
}