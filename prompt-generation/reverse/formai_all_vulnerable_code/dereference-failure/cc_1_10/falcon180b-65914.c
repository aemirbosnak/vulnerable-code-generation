//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 20
#define MAX_FIELD_LEN 100

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = (Resume *)malloc(sizeof(Resume));
    resume->num_fields = 0;

    char line[MAX_FIELD_LEN];
    char *token = NULL;
    while (fgets(line, MAX_FIELD_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        token = strtok(line, ":");
        while (token!= NULL) {
            if (resume->num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Error: Too many fields in resume.\n");
                exit(1);
            }

            Field *field = &resume->fields[resume->num_fields];
            field->name = strdup(token);
            field->value = strdup(strtok(NULL, ":"));

            resume->num_fields++;

            token = strtok(NULL, ":");
        }
    }

    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

void free_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        free(resume->fields[i].name);
        free(resume->fields[i].value);
    }
    free(resume);
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open resume file.\n");
        exit(1);
    }

    Resume *resume = parse_resume(fp);
    print_resume(resume);
    free_resume(resume);

    fclose(fp);
    return 0;
}