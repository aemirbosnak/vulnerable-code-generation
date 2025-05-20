//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Field;

typedef struct {
    int num_fields;
    Field fields[10];
} Resume;

Resume* parse_resume(char* text) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    int num_fields = 0;
    char* curr_field_name = NULL;
    char* curr_field_value = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    resume->num_fields = 0;

    while ((read = getline(&line, &len, text))!= -1) {
        if (num_fields >= 10) {
            break;
        }

        line[read - 1] = '\0';
        curr_field_name = strtok(line, ":");
        curr_field_value = strtok(NULL, ":");

        if (curr_field_name == NULL || curr_field_value == NULL) {
            continue;
        }

        strncpy(resume->fields[num_fields].name, curr_field_name, MAX_NAME_LEN - 1);
        strncpy(resume->fields[num_fields].value, curr_field_value, MAX_VALUE_LEN - 1);
        num_fields++;
    }

    if (num_fields == 0) {
        free(resume);
        return NULL;
    }

    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->fields[0].value);
    printf("Email: %s\n", resume->fields[1].value);
    printf("Phone: %s\n", resume->fields[2].value);
    printf("Address: %s\n", resume->fields[3].value);
    printf("Objective: %s\n", resume->fields[4].value);
    printf("Education:\n");
    printf("  Institution: %s\n", resume->fields[5].value);
    printf("  Degree: %s\n", resume->fields[6].value);
    printf("  GPA: %s\n", resume->fields[7].value);
    printf("Experience:\n");
    int i;
    for (i = 8; i < resume->num_fields; i++) {
        printf("  %s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main() {
    char* text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 555-555-5555\nAddress: 123 Main St.\nObjective: To obtain a challenging position in a dynamic organization.\nEducation:\n  Institution: Example University\n  Degree: Bachelor of Science in Computer Science\n  GPA: 3.5/4.0\nExperience:\n  Software Engineer: Example Corp.\n    Responsibilities:\n     - Designed and implemented software solutions.\n     - Collaborated with cross-functional teams.\n     - Conducted code reviews.\n  Intern: Example Inc.\n    Responsibilities:\n     - Assisted in software development.\n     - Conducted research on emerging technologies.\n     - Prepared reports on project progress.\n";

    Resume* resume = parse_resume(text);

    if (resume!= NULL) {
        print_resume(resume);
        free(resume);
    }

    return 0;
}