//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024  // Maximum size of a CSV line
#define MAX_FIELD_SIZE 128  // Maximum size of a field

struct csv_field {
    char value[MAX_FIELD_SIZE];
    struct csv_field *next;
};

struct csv_line {
    struct csv_field *fields;
    struct csv_line *next;
};

struct csv_file {
    struct csv_line *lines;
};

void add_csv_field(struct csv_line *line, char *value) {
    struct csv_field *new_field = (struct csv_field*) malloc(sizeof(struct csv_field));
    strncpy(new_field->value, value, MAX_FIELD_SIZE);
    new_field->next = NULL;
    if (line->fields == NULL) {
        line->fields = new_field;
    }
    else {
        struct csv_field *field = line->fields;
        while (field->next != NULL) {
            field = field->next;
        }
        field->next = new_field;
    }
}

void parse_csv_line(struct csv_line *line, char *text) {
    char *field = strtok(text, ",");
    while (field != NULL) {
        add_csv_field(line, field);
        field = strtok(NULL, ",");
    }
}

struct csv_file* read_csv_file(FILE *fp) {
    char line_text[MAX_LINE_SIZE];
    struct csv_file *csv = (struct csv_file*) malloc(sizeof(struct csv_file));
    csv->lines = NULL;
    while (fgets(line_text, MAX_LINE_SIZE, fp) != NULL) {
        struct csv_line *new_line = (struct csv_line*) malloc(sizeof(struct csv_line));
        new_line->fields = NULL;
        parse_csv_line(new_line, line_text);
        if (csv->lines == NULL) {
            csv->lines = new_line;
        }
        else {
            struct csv_line *line = csv->lines;
            while (line->next != NULL) {
                line = line->next;
            }
            line->next = new_line;
        }
    }
    return csv;
}

void free_csv_file(struct csv_file *csv) {
    struct csv_line *line = csv->lines;
    while (line != NULL) {
        struct csv_field *field = line->fields;
        while (field != NULL) {
            struct csv_field *next_field = field->next;
            free(field);
            field = next_field;
        }
        struct csv_line *next_line = line->next;
        free(line);
        line = next_line;
    }
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    struct csv_file *csv = read_csv_file(fp);
    fclose(fp);
    struct csv_line *line = csv->lines;
    while (line != NULL) {
        struct csv_field *field = line->fields;
        while (field != NULL) {
            printf("%s,", field->value);
            field = field->next;
        }
        printf("\n");
        line = line->next;
    }
    free_csv_file(csv);
    return 0;
}