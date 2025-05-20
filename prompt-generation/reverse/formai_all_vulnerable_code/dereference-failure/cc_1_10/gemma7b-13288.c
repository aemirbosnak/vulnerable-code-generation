//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char *name;
    int age;
    float salary;
    struct Candidate *next;
} Candidate;

Candidate *parse_resume(char *resume_text) {
    Candidate *head = NULL;
    Candidate *tail = NULL;
    char *line = strtok(resume_text, "\n");

    while (line) {
        char *name = strstr(line, "Name:");
        char *age_str = strstr(line, "Age:");
        char *salary_str = strstr(line, "Salary:");

        if (name && age_str && salary_str) {
            int age = atoi(age_str);
            float salary = atof(salary_str);
            Candidate *new_candidate = malloc(sizeof(Candidate));
            new_candidate->name = strdup(name);
            new_candidate->age = age;
            new_candidate->salary = salary;
            new_candidate->next = NULL;

            if (head == NULL) {
                head = new_candidate;
                tail = new_candidate;
            } else {
                tail->next = new_candidate;
                tail = new_candidate;
            }
        }

        line = strtok(NULL, "\n");
    }

    return head;
}

int main() {
    char *resume_text = "Name: John Doe\nAge: 25\nSalary: 50000\n\nName: Jane Doe\nAge: 30\nSalary: 60000";

    Candidate *head = parse_resume(resume_text);

    Candidate *current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2f\n", current->salary);
        printf("\n");
        current = current->next;
    }

    return 0;
}