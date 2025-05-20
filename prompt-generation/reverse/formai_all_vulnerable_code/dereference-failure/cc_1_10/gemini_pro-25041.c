//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LogNode {
    char *message;
    struct LogNode *next;
} LogNode;

LogNode *parse_log(FILE *fp) {
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        return NULL;
    }

    LogNode *node = malloc(sizeof(LogNode));
    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->message = strdup(line);
    if (node->message == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    node->next = parse_log(fp);

    return node;
}

void print_log(LogNode *node) {
    if (node == NULL) {
        return;
    }

    printf("%s", node->message);

    print_log(node->next);

    free(node->message);
    free(node);
}

void free_log(LogNode *node) {
    if (node == NULL) {
        return;
    }

    free_log(node->next);

    free(node->message);
    free(node);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    LogNode *log = parse_log(fp);

    print_log(log);

    free_log(log);

    fclose(fp);

    return EXIT_SUCCESS;
}