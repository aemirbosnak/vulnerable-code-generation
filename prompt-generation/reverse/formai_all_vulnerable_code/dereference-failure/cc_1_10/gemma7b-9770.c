//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct ResumeEntry {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct ResumeEntry* next;
} ResumeEntry;

ResumeEntry* parseResume(char* resumeText) {
    ResumeEntry* head = NULL;
    char* name = NULL;
    int age = 0;
    float salary = 0.0f;

    // Split the resume text into sections
    char* sections = strtok(resumeText, ":");

    // Iterate over the sections
    for (char* section = sections; section; section = strtok(NULL, ":")) {
        // Extract the name, age, and salary
        if (strcmp(section, "Name:") == 0) {
            name = strtok(section, ":");
        } else if (strcmp(section, "Age:") == 0) {
            age = atoi(strtok(section, ":"));
        } else if (strcmp(section, "Salary:") == 0) {
            salary = atof(strtok(section, ":"));
        }

        // Create a new resume entry
        ResumeEntry* newEntry = malloc(sizeof(ResumeEntry));
        strcpy(newEntry->name, name);
        newEntry->age = age;
        newEntry->salary = salary;
        newEntry->next = head;
        head = newEntry;
    }

    return head;
}

int main() {
    char* resumeText = "Name: John Doe\nAge: 30\nSalary: 50000\n";

    ResumeEntry* head = parseResume(resumeText);

    // Print the resume entries
    for (ResumeEntry* entry = head; entry; entry = entry->next) {
        printf("Name: %s\n", entry->name);
        printf("Age: %d\n", entry->age);
        printf("Salary: %.2f\n", entry->salary);
        printf("\n");
    }

    return 0;
}