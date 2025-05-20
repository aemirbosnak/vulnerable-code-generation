//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char *name;
    int index;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} csv_t;

csv_t *csv_open(FILE *fp)
{
    csv_t *csv = malloc(sizeof(csv_t));
    csv->fields = NULL;
    csv->num_fields = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            field_t *field = malloc(sizeof(field_t));
            field->name = strdup(token);
            field->index = csv->num_fields;
            csv->fields = realloc(csv->fields, sizeof(field_t) * ++csv->num_fields);
            csv->fields[csv->num_fields - 1] = *field;
            free(field);

            token = strtok(NULL, ",");
        }
    }

    return csv;
}

void csv_close(csv_t *csv)
{
    for (int i = 0; i < csv->num_fields; i++) {
        free(csv->fields[i].name);
    }
    free(csv->fields);
    free(csv);
}

int csv_get_field_index(csv_t *csv, char *name)
{
    for (int i = 0; i < csv->num_fields; i++) {
        if (strcmp(csv->fields[i].name, name) == 0) {
            return csv->fields[i].index;
        }
    }
    return -1;
}

int csv_get_num_fields(csv_t *csv)
{
    return csv->num_fields;
}

void csv_print_fields(csv_t *csv)
{
    for (int i = 0; i < csv->num_fields; i++) {
        printf("%s (%d)\n", csv->fields[i].name, csv->fields[i].index);
    }
}

int main()
{
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    csv_t *csv = csv_open(fp);
    if (csv == NULL) {
        printf("Error: Could not parse CSV file.\n");
        return 1;
    }

    int num_fields = csv_get_num_fields(csv);
    printf("Number of fields: %d\n", num_fields);

    for (int i = 0; i < num_fields; i++) {
        int field_index = csv_get_field_index(csv, "field1");
        if (field_index == -1) {
            printf("Field not found.\n");
        } else {
            printf("Field index: %d\n", field_index);
        }
    }

    csv_print_fields(csv);

    csv_close(csv);
    fclose(fp);

    return 0;
}