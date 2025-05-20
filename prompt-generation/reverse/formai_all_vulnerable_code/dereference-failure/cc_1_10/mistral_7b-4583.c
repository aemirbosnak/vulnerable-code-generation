//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 256

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    char city[MAX_FIELD_LENGTH];
} Record;

void parse_line(char *line, Record *record) {
    char *token[MAX_FIELDS];
    int fields_count = 0;
    char *delimiter = ",";

    record->age = -1;

    line += strlen(line) - 1;
    while (*line != '\n') {
        if (*line == ',') {
            *line = '\0';
            line--;
            token[fields_count++] = strtok(NULL, delimiter);
        }
        line--;
    }

    if (fields_count >= 3) {
        strcpy(record->name, token[0]);
        record->age = atoi(token[1]);
        strcpy(record->city, token[2]);
    }
}

int main() {
    FILE *file;
    Record record;
    char line[MAX_LINE_LENGTH];

    file = fopen("input.csv", "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", "input.csv");
        return 1;
    }

    printf("Name,Age,City\n");

    while (fgets(line, sizeof(line), file)) {
        parse_line(line, &record);
        if (record.age != -1) {
            printf("%s,%d,%s\n", record.name, record.age, record.city);
        }
    }

    fclose(file);

    return 0;
}