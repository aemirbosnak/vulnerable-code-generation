//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_NUM_FIELDS];
} resume_t;

static int parse_line(char *line, field_t *field) {
    char *token = strtok(line, ":");
    if (token == NULL) {
        return -1;
    }
    strcpy(field->name, token);
    token = strtok(NULL, ":");
    if (token == NULL) {
        return -1;
    }
    strcpy(field->value, token);
    return 0;
}

static int add_field(resume_t *resume, char *name, char *value) {
    int i;
    for (i = 0; i < resume->num_fields; i++) {
        if (strcmp(resume->fields[i].name, name) == 0) {
            strcpy(resume->fields[i].value, value);
            return 0;
        }
    }
    if (resume->num_fields >= MAX_NUM_FIELDS) {
        return -1;
    }
    strcpy(resume->fields[resume->num_fields].name, name);
    strcpy(resume->fields[resume->num_fields].value, value);
    resume->num_fields++;
    return 0;
}

static int parse_resume(FILE *fp, resume_t *resume) {
    char line[MAX_LINE_LENGTH];
    field_t field;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (parse_line(line, &field) == 0) {
            if (add_field(resume, field.name, field.value)!= 0) {
                return -1;
            }
        }
    }
    return 0;
}

static void print_resume(resume_t *resume) {
    int i;
    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    resume_t resume;

    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (parse_resume(fp, &resume)!= 0) {
        printf("Error parsing resume.\n");
        fclose(fp);
        return 1;
    }

    print_resume(&resume);

    fclose(fp);
    return 0;
}