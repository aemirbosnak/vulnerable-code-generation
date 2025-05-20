//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Cv {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Cv* next;
} Cv;

int main() {
    Cv* head = NULL;

    // Parse resume data from a text file
    FILE* resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        return EXIT_FAILURE;
    }

    // Read the resume line by line
    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL) {
        // Extract the candidate's name, age, and salary
        char* name = strchr(line, "Name:");
        char* age_str = strchr(line, "Age:");
        char* salary_str = strchr(line, "Salary:");

        // Convert the age and salary strings to integers and floats
        int age = atoi(age_str);
        float salary = atof(salary_str);

        // Allocate memory for a new Cv node
        Cv* new_cv = malloc(sizeof(Cv));

        // Set the candidate's name, age, and salary
        strcpy(new_cv->name, name);
        new_cv->age = age;
        new_cv->salary = salary;

        // Add the new node to the linked list
        if (head == NULL) {
            head = new_cv;
        } else {
            new_cv->next = head;
            head = new_cv;
        }
    }

    // Print the candidate's name, age, and salary
    Cv* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2f\n", current->salary);
        printf("\n");
        current = current->next;
    }

    // Close the resume file
    fclose(resume_file);

    return EXIT_SUCCESS;
}