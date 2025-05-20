//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 10
#define MAX_FIELD_SIZE 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_NUM_FIELDS];
} resume_t;

resume_t *parse_resume(FILE *fp) {
    resume_t *r = malloc(sizeof(resume_t));
    r->num_fields = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            field_t *f = malloc(sizeof(field_t));
            f->name = strdup(token);
            f->value = strdup(strtok(NULL, ","));

            if (r->num_fields >= MAX_NUM_FIELDS) {
                fprintf(stderr, "Error: Maximum number of fields exceeded.\n");
                exit(1);
            }

            r->fields[r->num_fields++] = *f;
            free(f->name);
            free(f->value);
            free(f);
        }
    }

    return r;
}

void print_resume(resume_t *r) {
    printf("Name: %s\n", r->fields[0].value);
    printf("Email: %s\n", r->fields[1].value);
    printf("Phone: %s\n", r->fields[2].value);
    printf("Address: %s\n", r->fields[3].value);
    printf("Education: %s\n", r->fields[4].value);
    printf("Experience: %s\n", r->fields[5].value);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    resume_t *r = parse_resume(fp);
    fclose(fp);

    print_resume(r);

    free(r);
    return 0;
}