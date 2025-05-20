//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 50

struct field {
    char *name;
    char *value;
};

struct resume {
    int num_fields;
    struct field *fields;
};

void parse_line(char *line, struct field *field) {
    char *token = strtok(line, ":");
    strncpy(field->name, token, MAX_FIELD_LENGTH);
    field->value = strtok(NULL, ":");
}

void add_field(struct resume *resume, char *name, char *value) {
    if (resume->num_fields >= MAX_FIELDS) {
        printf("Error: Maximum number of fields reached.\n");
        return;
    }
    struct field *new_field = malloc(sizeof(struct field));
    strncpy(new_field->name, name, MAX_FIELD_LENGTH);
    strncpy(new_field->value, value, MAX_FIELD_LENGTH);
    resume->fields[resume->num_fields] = *new_field;
    resume->num_fields++;
}

int main(int argc, char **argv) {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    struct resume resume = {0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            struct field field = {0};
            parse_line(token, &field);
            add_field(&resume, field.name, field.value);
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    printf("Name: %s\n", resume.fields[0].value);
    printf("Email: %s\n", resume.fields[1].value);
    printf("Phone: %s\n", resume.fields[2].value);

    return 0;
}