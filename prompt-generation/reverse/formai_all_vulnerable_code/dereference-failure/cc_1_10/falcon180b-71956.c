//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t *fields;
} resume_t;

resume_t *parse_resume(FILE *fp) {
    resume_t *r = NULL;
    field_t *f = NULL;
    char line[MAX_LINE_SIZE];
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (num_fields >= MAX_NUM_FIELDS) {
            printf("Error: Too many fields in resume.\n");
            exit(1);
        }

        char *token = strtok(line, ":");
        if (token == NULL) {
            printf("Error: Invalid field format.\n");
            exit(1);
        }

        f = realloc(f, sizeof(field_t) * ++num_fields);
        f[num_fields - 1].name = strdup(token);

        token = strtok(NULL, ":");
        if (token == NULL) {
            printf("Error: Missing field value.\n");
            exit(1);
        }

        f[num_fields - 1].value = strdup(token);
    }

    r = malloc(sizeof(resume_t));
    r->num_fields = num_fields;
    r->fields = f;

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
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open resume file.\n");
        exit(1);
    }

    resume_t *r = parse_resume(fp);
    if (r == NULL) {
        exit(1);
    }

    print_resume(r);

    free_resume(r);
    fclose(fp);

    return 0;
}