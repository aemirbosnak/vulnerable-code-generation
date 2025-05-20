//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_FIELDS];
} resume_t;

field_t *parse_line(char *line, int *num_fields) {
    char *token = strtok(line, ":");
    field_t *fields = malloc(sizeof(field_t) * MAX_FIELDS);
    int i = 0;

    while (token!= NULL && i < MAX_FIELDS) {
        fields[i].name = strdup(token);
        fields[i].value = strdup(strtok(NULL, ":"));
        i++;
        token = strtok(NULL, ":");
    }

    *num_fields = i;
    return fields;
}

resume_t *parse_resume(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    resume_t *resume = malloc(sizeof(resume_t));
    int num_fields;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        field_t *fields = parse_line(line, &num_fields);
        if (num_fields > 0) {
            resume->num_fields = num_fields;
            memcpy(resume->fields, fields, sizeof(field_t) * num_fields);
        }
    }

    return resume;
}

void print_resume(resume_t *resume) {
    int i;

    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    resume_t *resume;

    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    resume = parse_resume(fp);
    print_resume(resume);

    free(resume->fields);
    free(resume);
    fclose(fp);

    return 0;
}