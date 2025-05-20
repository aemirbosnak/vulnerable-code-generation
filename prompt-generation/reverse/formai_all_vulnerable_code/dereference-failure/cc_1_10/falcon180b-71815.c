//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char *name;
    char *value;
} field_t;

field_t *fields = NULL;
int num_fields = 0;

int read_csv_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (num_fields >= MAX_FIELDS) {
                printf("Error: too many fields in line\n");
                return 1;
            }
            field_t *field = malloc(sizeof(field_t));
            field->name = strdup(token);
            field->value = strdup("");
            fields = realloc(fields, sizeof(field_t) * ++num_fields);
            fields[num_fields - 1] = *field;
            free(field);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}

void print_fields() {
    for (int i = 0; i < num_fields; i++) {
        printf("%s: %s\n", fields[i].name, fields[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    if (read_csv_file(argv[1])!= 0) {
        return 1;
    }

    print_fields();

    for (int i = 0; i < num_fields; i++) {
        free(fields[i].name);
        free(fields[i].value);
    }
    free(fields);

    return 0;
}