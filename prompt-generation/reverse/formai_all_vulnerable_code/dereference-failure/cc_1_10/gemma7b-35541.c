//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate
{
    char name[50];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

void parse_resume(char* resume_text)
{
    Candidate* head = NULL;
    Candidate* current = NULL;

    // Tokenize the resume text
    char* token = strtok(resume_text, " ");

    // Iterate over the tokens
    while (token)
    {
        // Create a new candidate if necessary
        if (head == NULL)
        {
            head = current = malloc(sizeof(Candidate));
        }
        else
        {
            current = current->next = malloc(sizeof(Candidate));
            current = current->next;
        }

        // Set the candidate's name, age, and salary
        if (strcmp(token, "Name:") == 0)
        {
            token = strtok(NULL, " ");
            strcpy(current->name, token);
        }
        else if (strcmp(token, "Age:") == 0)
        {
            token = strtok(NULL, " ");
            current->age = atoi(token);
        }
        else if (strcmp(token, "Salary:") == 0)
        {
            token = strtok(NULL, " ");
            current->salary = atof(token);
        }
    }

    // Print the candidates
    current = head;
    while (current)
    {
        printf("Name: %s, Age: %d, Salary: %.2f\n", current->name, current->age, current->salary);
        current = current->next;
    }
}

int main()
{
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: 50000\n\nName: Jane Doe\nAge: 30\nSalary: 60000\n";

    parse_resume(resume_text);

    return 0;
}