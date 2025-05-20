//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 10

typedef struct {
    char field_name[50];
    char field_value[MAX_LINE_LENGTH];
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_NUM_FIELDS];
} Resume;

Resume *read_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    Resume *resume = (Resume *)malloc(sizeof(Resume));
    resume->num_fields = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        strcpy(resume->fields[resume->num_fields].field_name, token);
        strcpy(resume->fields[resume->num_fields].field_value, strtok(NULL, ":"));
        resume->num_fields++;
    }

    fclose(fp);
    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].field_name, resume->fields[i].field_value);
    }
}

int main() {
    char filename[50];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    Resume *resume = read_resume(filename);
    print_resume(resume);

    free(resume);
    return 0;
}