//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_STACK_SIZE 100

typedef struct {
    char *line;
    size_t len;
} line_t;

static line_t stack[MAX_STACK_SIZE];
static size_t stack_top = 0;

void push_line(const char *line) {
    if (stack_top == MAX_STACK_SIZE) {
        printf("Stack full! Line ignored.\n");
        return;
    }

    line_t *new_line = malloc(sizeof(line_t) + strlen(line));
    new_line->line = line;
    new_line->len = strlen(line);
    stack[stack_top++] = *new_line;
}

void pop_line(void) {
    if (stack_top == 0) {
        printf("Stack empty! Nothing to pop.\n");
        return;
    }

    stack_top--;
    free(stack[stack_top].line);
}

void process_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)) {
        push_line(line);
    }

    fclose(file);

    while (!stack_top) {
        pop_line();
    }
}

int main(void) {
    srand(time(NULL));

    char *filenames[10];
    for (size_t i = 0; i < 10; i++) {
        filenames[i] = (char *)malloc(20);
        snprintf(filenames[i], 20, "example_%zu.txt", i);
        process_lines(filenames[i]);
        free(filenames[i]);
    }

    return 0;
}