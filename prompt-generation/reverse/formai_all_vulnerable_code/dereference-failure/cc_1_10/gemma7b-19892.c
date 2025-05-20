//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct CSV_Entry {
    char **data;
    int num_cols;
    struct CSV_Entry **next;
} CSV_Entry;

CSV_Entry **readCSV(char *filename) {
    CSV_Entry **head = NULL;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    int line_num = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        line_num++;
        CSV_Entry *entry = malloc(sizeof(CSV_Entry));
        entry->data = malloc(sizeof(char *) * 10);
        entry->num_cols = 0;

        char *token = strtok(line, ",");
        while (token) {
            entry->data[entry->num_cols++] = strdup(token);
            token = strtok(NULL, ",");
        }

        entry->next = head;
        head = entry;
    }

    fclose(fp);
    return head;
}

int main() {
    CSV_Entry *entries = readCSV("test.csv");
    for (CSV_Entry *entry = entries; entry; entry = entry->next) {
        for (int i = 0; i < entry->num_cols; i++) {
            printf("%s,", entry->data[i]);
        }
        printf("\n");
    }

    return 0;
}