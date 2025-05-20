//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing employee information
typedef struct {
    int id;
    char name[50];
    char email[50];
    char skills[100];
} Employee;

// Function for parsing resume and creating Employee object
Employee* parseResume(char* resume) {
    Employee* emp = (Employee*) malloc(sizeof(Employee));

    // Parse resume and extract employee information
    char* token = strtok(resume, "\n");

    while(token != NULL) {
        // Assuming resume format to be:
        // Name: [name]
        // Email: [email]
        // Skills: [skills]
        if(strstr(token, "Name: ") != NULL) {
            strcpy(emp->name, token + 6);
        }
        else if(strstr(token, "Email: ") != NULL) {
            strcpy(emp->email, token + 7);
        }
        else if(strstr(token, "Skills: ") != NULL) {
            strcpy(emp->skills, token + 8);
        }

        token = strtok(NULL, "\n");
    }

    // Assign random employee id
    emp->id = rand() % 10000 + 1000;

    return emp;
}

int main() {
    char resume[500];
    printf("Enter resume:\n");
    fgets(resume, 500, stdin);

    // Parse resume and create Employee object
    Employee* emp = parseResume(resume);

    // Print employee information
    printf("ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Email: %s\n", emp->email);
    printf("Skills: %s\n", emp->skills);

    free(emp);

    return 0;
}