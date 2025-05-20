//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
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

    // Extract candidate's name, age, and salary from the resume text
    char* name = strstr(resume_text, "Name:");
    char* age_str = strstr(resume_text, "Age:");
    char* salary_str = strstr(resume_text, "Salary:");

    // Allocate memory for the candidate
    current = malloc(sizeof(Candidate));

    // Set candidate's name, age, and salary
    strcpy(current->name, name + 5);
    current->age = atoi(age_str + 5);
    current->salary = atof(salary_str + 8);

    // Add the candidate to the linked list
    if (head == NULL) {
        head = current;
    } else {
        current->next = head;
        head = current;
    }

    // Return the head of the linked list
    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate's name, age, and salary
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: $%f\n", head->salary);

    return 0;
}