//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct tuple {
    char **data;
    struct tuple *next;
};

struct csv {
    char **headers;
    int num_columns;
    struct tuple *tuples_head;
};

void print_csv(struct csv *csv) {
    int i;
    struct tuple *curr_tuple;

    // Print headers
    for (i = 0; i < csv->num_columns; ++i) {
        printf("%s,\t", csv->headers[i]);
    }
    printf("\n");

    // Print tuples
    curr_tuple = csv->tuples_head;
    while (curr_tuple != NULL) {
        for (i = 0; i < csv->num_columns; ++i) {
            printf("%s,\t", curr_tuple->data[i]);
        }
        printf("\n");
        curr_tuple = curr_tuple->next;
    }
}

void free_csv(struct csv *csv) {
    int i;
    struct tuple *curr_tuple;
    struct tuple *next_tuple;

    // Free headers
    for (i = 0; i < csv->num_columns; ++i) {
        free(csv->headers[i]);
    }
    free(csv->headers);

    // Free tuples
    curr_tuple = csv->tuples_head;
    while (curr_tuple != NULL) {
        next_tuple = curr_tuple->next;
        for (i = 0; i < csv->num_columns; ++i) {
            free(curr_tuple->data[i]);
        }
        free(curr_tuple->data);
        free(curr_tuple);
        curr_tuple = next_tuple;
    }

    free(csv);
}

int count_columns(char *line) {
    int i;
    int len = strlen(line);
    int count = 1;

    for (i = 0; i < len; ++i) {
        if (line[i] == ',') {
            ++count;
        }
    }

    return count;
}

char **parse_line(char *line, int num_columns) {
    char **data = (char **)malloc(num_columns * sizeof(char *));
    int i;
    char *tok;

    for (i = 0; i < num_columns; ++i) {
        tok = strtok(i == 0 ? line : NULL, ",");
        data[i] = (char *)malloc(strlen(tok) + 1);
        strcpy(data[i], tok);
    }

    return data;
}

struct tuple *parse_tuples(FILE *fp, int num_columns) {
    char line[MAX_LINE_LENGTH];
    struct tuple *head_tuple = NULL;
    struct tuple *prev_tuple = NULL;
    struct tuple *curr_tuple;
    char **data;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove newline character
        strtok(line, "\n");

        // Parse line
        data = parse_line(line, num_columns);

        // Create tuple
        curr_tuple = (struct tuple *)malloc(sizeof(struct tuple));
        curr_tuple->data = data;
        curr_tuple->next = NULL;

        // Add tuple to list
        if (head_tuple == NULL) {
            head_tuple = curr_tuple;
        } else {
            prev_tuple->next = curr_tuple;
        }
        prev_tuple = curr_tuple;
    }

    return head_tuple;
}

struct csv *load_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    char **headers;
    int num_columns;
    struct csv *csv;

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Parse headers
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    strtok(line, "\n");
    num_columns = count_columns(line);
    headers = parse_line(line, num_columns);

    // Parse tuples
    struct tuple *tuples_head = parse_tuples(fp, num_columns);

    // Create CSV struct
    csv = (struct csv *)malloc(sizeof(struct csv));
    csv->num_columns = num_columns;
    csv->headers = headers;
    csv->tuples_head = tuples_head;

    fclose(fp);

    return csv;
}

int main() {
    struct csv *csv = load_csv("example.csv");
    print_csv(csv);
    free_csv(csv);
    return 0;
}