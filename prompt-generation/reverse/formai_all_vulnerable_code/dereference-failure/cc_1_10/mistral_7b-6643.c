//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Resume;

int parse_resume(Resume *resume, char *input) {
    char line[MAX_LINE_LENGTH];
    char *token, *key, *value;
    int num_fields = 0;

    memset(resume, 0, sizeof(Resume));

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        token = strtok(line, ":");
        if (!token) continue;

        key = malloc(strlen(token) + 1);
        strcpy(key, token);

        token = strtok(NULL, "\n");
        if (!token) {
            free(key);
            continue;
        }

        value = malloc(strlen(token) + 1);
        strcpy(value, token);

        if (num_fields >= MAX_FIELDS) {
            printf("Error: Too many fields in resume.\n");
            free(key);
            free(value);
            continue;
        }

        strcpy(resume->fields[num_fields].key, key);
        strcpy(resume->fields[num_fields].value, value);
        num_fields++;
    }

    resume->num_fields = num_fields;

    return num_fields;
}

int main() {
    Resume resume;
    char input[MAX_LINE_LENGTH];

    printf("Enter resume text:\n");
    fgets(input, MAX_LINE_LENGTH, stdin);

    int num_fields = parse_resume(&resume, input);

    if (num_fields <= 0) {
        printf("Error parsing resume.\n");
        return 1;
    }

    printf("Parsed resume:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("%s: %s\n", resume.fields[i].key, resume.fields[i].value);
    }

    return 0;
}