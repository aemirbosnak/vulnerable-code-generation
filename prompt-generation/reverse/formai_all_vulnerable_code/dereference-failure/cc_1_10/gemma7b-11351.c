//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(FILE* resume_file) {
    Candidate* head = NULL;

    // Read the resume file line by line
    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL) {
        // Extract the candidate's name, age, and salary
        char* name = strchr(line, ' ');
        int age = atoi(strchr(name, ' ') + 1);
        float salary = atof(strchr(strchr(line, ' ') + 1, '$') + 1);

        // Create a new candidate
        Candidate* new_candidate = malloc(sizeof(Candidate));
        new_candidate->name[0] = '\0';
        strncpy(new_candidate->name, name, MAX_NAME_LENGTH - 1);
        new_candidate->age = age;
        new_candidate->salary = salary;
        new_candidate->next = NULL;

        // Add the new candidate to the linked list
        if (head == NULL) {
            head = new_candidate;
        } else {
            new_candidate->next = head;
            head = new_candidate;
        }
    }

    return head;
}

int main() {
    FILE* resume_file = fopen("resume.txt", "r");
    Candidate* head = parse_resume(resume_file);

    // Print the candidate's name, age, and salary
    Candidate* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: $%.2f\n", current->salary);
        printf("\n");
        current = current->next;
    }

    fclose(resume_file);

    return 0;
}