//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_LINE_LENGTH 1024

char* read_csv_line(FILE* fp) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        free(line);
        return NULL;
    }
    int length = strlen(line);
    if (line[length-1] == '\n') line[length-1] = '\0';
    return line;
}

int count_csv_columns(const char* line) {
    int count = 0;
    char* token;
    char* str = strdup(line);
    while ((token = strsep(&str, ",")) != NULL && count < MAX_COLUMNS) {
        count++;
    }
    return count;
}

void parse_csv_line(const char* line, char** columns, int num_columns) {
    char* token;
    char* str = strdup(line);
    for (int i = 0; i < num_columns && (token = strsep(&str, ",")) != NULL; i++) {
        columns[i] = strdup(token);
    }
}

int main() {
    FILE* fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* line = read_csv_line(fp);
    int num_columns = count_csv_columns(line);
    char* columns[num_columns];
    parse_csv_line(line, columns, num_columns);

    printf("CSV Columns (%d total):\n", num_columns);
    for (int i = 0; i < num_columns; i++) {
        printf("%s\n", columns[i]);
    }

    free(line);
    for (int i = 0; i < num_columns; i++) {
        free(columns[i]);
    }
    fclose(fp);
    return 0;
}