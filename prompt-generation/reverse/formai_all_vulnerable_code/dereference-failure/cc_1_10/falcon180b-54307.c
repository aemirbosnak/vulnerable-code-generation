//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 1024
#define MAX_FIELDS 50

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t *fields;
} resume_t;

resume_t *parse_resume(FILE *fp) {
    resume_t *r = malloc(sizeof(resume_t));
    r->num_fields = 0;
    r->fields = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (r->num_fields >= MAX_FIELDS) {
            printf("Error: Too many fields\n");
            exit(1);
        }

        char *name = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (name == NULL || value == NULL) {
            printf("Error: Invalid field\n");
            exit(1);
        }

        field_t *f = malloc(sizeof(field_t));
        f->name = strdup(name);
        f->value = strdup(value);

        r->fields = realloc(r->fields, sizeof(field_t) * (r->num_fields + 1));
        r->fields[r->num_fields++] = *f;
    }

    return r;
}

void print_resume(resume_t *r) {
    for (int i = 0; i < r->num_fields; i++) {
        printf("%s: %s\n", r->fields[i].name, r->fields[i].value);
    }
}

void free_resume(resume_t *r) {
    for (int i = 0; i < r->num_fields; i++) {
        free(r->fields[i].name);
        free(r->fields[i].value);
    }
    free(r->fields);
    free(r);
}

int main() {
    FILE *fp;
    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }

    resume_t *r = parse_resume(fp);

    print_resume(r);

    free_resume(r);

    fclose(fp);
    return 0;
}