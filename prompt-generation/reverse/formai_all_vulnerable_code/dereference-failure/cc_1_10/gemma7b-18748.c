//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* head = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* age_start = NULL;
    char* age_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Find the start and end of the name, age, and salary sections
    name_start = strstr(resume_text, "Name:");
    name_end = strstr(name_start, "Age:");

    age_start = strstr(name_end, "Age:");
    age_end = strstr(age_start, "Salary:");

    salary_start = strstr(age_end, "Salary:");
    salary_end = strstr(salary_start, "End");

    // Allocate memory for the candidate
    Candidate* new_candidate = malloc(sizeof(Candidate));

    // Copy the candidate's name, age, and salary
    strcpy(new_candidate->name, name_start + 5);
    new_candidate->age = atoi(age_start + 5);
    new_candidate->salary = atof(salary_start + 5);

    // Link the candidate to the head of the list
    if (head == NULL) {
        head = new_candidate;
    } else {
        new_candidate->next = head;
        head = new_candidate;
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000\nEnd";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate's name, age, and salary
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: $%f\n", head->salary);

    return 0;
}