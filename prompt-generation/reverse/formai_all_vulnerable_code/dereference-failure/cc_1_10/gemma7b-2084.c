//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* head = NULL;
    Candidate* current = NULL;

    // Extract candidate name, age, and salary
    char* name = strstr(resume_text, "Name:");
    if (name) {
        name += 5;
        current = malloc(sizeof(Candidate));
        strcpy(current->name, name);
    }

    char* age_str = strstr(resume_text, "Age:");
    if (age_str) {
        age_str += 5;
        current->age = atoi(age_str);
    }

    char* salary_str = strstr(resume_text, "Salary:");
    if (salary_str) {
        salary_str += 8;
        current->salary = atof(salary_str);
    }

    // Add candidate to linked list
    if (current) {
        if (head) {
            current->next = head;
            head = current;
        } else {
            head = current;
        }
    }

    return head;
}

int main() {
    char resume_text[] = "Name: John Doe\nAge: 30\nSalary: 50000\n";

    Candidate* head = parse_resume(resume_text);

    // Print candidate information
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: %.2f\n", head->salary);

    return 0;
}