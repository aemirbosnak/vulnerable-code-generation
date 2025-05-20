//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
    struct word_count_t *next;
} word_count_t;

word_count_t *parse_line(char *line) {
    char *token, *delim = " \t\n\r\f\v\a";
    word_count_t *head = NULL;
    word_count_t *tail = NULL;
    char *word = strtok_r(line, delim, &line);

    while (word!= NULL) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            fprintf(stderr, "Error: Word '%s' is too long.\n", word);
            exit(1);
        }

        tail = (word_count_t *)malloc(sizeof(word_count_t));
        if (tail == NULL) {
            fprintf(stderr, "Error: Out of memory.\n");
            exit(1);
        }

        tail->word = strdup(word);
        tail->count = 1;
        tail->next = NULL;

        if (head == NULL) {
            head = tail;
        } else {
            tail->next = head;
            head = tail;
        }

        word = strtok_r(NULL, delim, &line);
    }

    return head;
}

void print_word_counts(word_count_t *head) {
    while (head!= NULL) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

void free_word_counts(word_count_t *head) {
    while (head!= NULL) {
        free(head->word);
        free(head);
        head = head->next;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    word_count_t *head = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        head = parse_line(line);
    }

    fclose(fp);
    print_word_counts(head);
    free_word_counts(head);

    return 0;
}