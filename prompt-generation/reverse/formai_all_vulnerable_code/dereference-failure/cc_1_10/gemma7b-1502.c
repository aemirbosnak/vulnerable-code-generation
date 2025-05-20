//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
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

Candidate* parseResume(char* resumeText) {
    Candidate* head = NULL;
    Candidate* current = NULL;

    // Extract candidate name, age, and salary from the resume text
    char* name = strstr(resumeText, "Name:");
    char* ageStr = strstr(resumeText, "Age:");
    char* salaryStr = strstr(resumeText, "Salary:");

    // Check if the candidate information was extracted
    if (name && ageStr && salaryStr) {
        // Allocate memory for the candidate
        current = malloc(sizeof(Candidate));

        // Set the candidate's name, age, and salary
        strcpy(current->name, name + 5);
        current->age = atoi(ageStr + 5);
        current->salary = atof(salaryStr + 8);

        // Link the candidate to the head of the list
        if (head) {
            current->next = head;
        } else {
            head = current;
        }

        // Traverse the linked list to print the candidate information
        Candidate* temp = head;
        while (temp) {
            printf("Name: %s, Age: %d, Salary: %.2f\n", temp->name, temp->age, temp->salary);
            temp = temp->next;
        }
    } else {
        printf("Error parsing resume text.\n");
    }

    return head;
}

int main() {
    char resumeText[] = "Name: John Doe\nAge: 25\nSalary: $50,000\n";

    Candidate* head = parseResume(resumeText);

    return 0;
}