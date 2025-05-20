//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 100000
#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

struct log_line {
    char *line;
    int length;
    struct log_line *next;
};

struct log_line *log_head = NULL;

void add_log_line(char *line) {
    struct log_line *new_line = malloc(sizeof(struct log_line));
    if (new_line == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_line->line = strdup(line);
    new_line->length = strlen(line);
    new_line->next = NULL;

    if (log_head == NULL) {
        log_head = new_line;
    } else {
        struct log_line *tail = log_head;
        while (tail->next!= NULL) {
            tail = tail->next;
        }
        tail->next = new_line;
    }
}

void print_log_lines() {
    struct log_line *current = log_head;
    while (current!= NULL) {
        printf("%s\n", current->line);
        current = current->next;
    }
}

void free_log_lines() {
    struct log_line *current = log_head;
    while (current!= NULL) {
        free(current->line);
        free(current);
        current = current->next;
    }
    log_head = NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        add_log_line(line);
    }

    fclose(log_file);

    print_log_lines();

    free_log_lines();

    return 0;
}