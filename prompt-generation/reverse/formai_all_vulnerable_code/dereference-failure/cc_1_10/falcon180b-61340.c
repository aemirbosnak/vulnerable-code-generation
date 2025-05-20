//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_HISTORY_SIZE 10

typedef struct {
    char* line;
    int line_num;
} Line;

typedef struct {
    Line lines[MAX_HISTORY_SIZE];
    int curr_line_num;
} History;

void init_history(History* history) {
    history->curr_line_num = 0;
    for (int i = 0; i < MAX_HISTORY_SIZE; i++) {
        history->lines[i].line = NULL;
        history->lines[i].line_num = -1;
    }
}

int add_line(History* history, char* line, int line_num) {
    if (history->curr_line_num >= MAX_HISTORY_SIZE) {
        fprintf(stderr, "Error: History buffer full.\n");
        return -1;
    }

    Line* curr_line = &history->lines[history->curr_line_num];
    curr_line->line = strdup(line);
    curr_line->line_num = line_num;
    history->curr_line_num++;

    return 0;
}

int print_history(History* history) {
    for (int i = 0; i < history->curr_line_num; i++) {
        Line* curr_line = &history->lines[i];
        printf("%4d: %s\n", curr_line->line_num, curr_line->line);
    }

    return 0;
}

void free_history(History* history) {
    for (int i = 0; i < history->curr_line_num; i++) {
        Line* curr_line = &history->lines[i];
        free(curr_line->line);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file - %s\n", strerror(errno));
        return -1;
    }

    History history;
    init_history(&history);

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        int line_num = 1;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\n') {
                line_num++;
            }
        }

        if (add_line(&history, line, line_num)!= 0) {
            fprintf(stderr, "Error: Failed to add line to history buffer.\n");
            fclose(file);
            free_history(&history);
            return -1;
        }
    }

    fclose(file);
    print_history(&history);
    free_history(&history);

    return 0;
}