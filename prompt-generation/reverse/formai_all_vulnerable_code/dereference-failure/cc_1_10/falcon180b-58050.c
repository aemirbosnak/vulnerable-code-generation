//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_NUM_FIELDS 100

typedef struct {
    char* name;
    char* value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_NUM_FIELDS];
} resume_t;

resume_t* parse_resume(FILE* fp) {
    resume_t* r = malloc(sizeof(resume_t));
    if (r == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for resume.\n");
        exit(1);
    }

    r->num_fields = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (r->num_fields >= MAX_NUM_FIELDS) {
                fprintf(stderr, "Error: Maximum number of fields reached.\n");
                exit(1);
            }

            field_t* f = malloc(sizeof(field_t));
            if (f == NULL) {
                fprintf(stderr, "Error: Failed to allocate memory for field.\n");
                exit(1);
            }

            f->name = strdup(word);
            f->value = NULL;

            r->fields[r->num_fields++] = *f;

            word = strtok(NULL, " ");
        }
    }

    return r;
}

void print_resume(resume_t* r) {
    for (int i = 0; i < r->num_fields; i++) {
        printf("%s: %s\n", r->fields[i].name, r->fields[i].value);
    }
}

void free_resume(resume_t* r) {
    for (int i = 0; i < r->num_fields; i++) {
        free(r->fields[i].name);
        free(r->fields[i].value);
    }
    free(r);
}

int main() {
    FILE* fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open resume file.\n");
        exit(1);
    }

    resume_t* r = parse_resume(fp);
    if (r == NULL) {
        exit(1);
    }

    print_resume(r);

    free_resume(r);

    fclose(fp);

    return 0;
}