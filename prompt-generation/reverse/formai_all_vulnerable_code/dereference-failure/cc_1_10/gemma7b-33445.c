//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct CvRecord
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct CvRecord* next;
} CvRecord;

void parse_resume(CvRecord** head)
{
    FILE* resume_file = fopen("resume.txt", "r");
    char line[MAX_NAME_LENGTH];

    if (resume_file)
    {
        while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL)
        {
            // Extract name, age, and salary from the line
            char* name = strtok(line, ":");
            char* age_str = strtok(NULL, ":");
            char* salary_str = strtok(NULL, ":");

            int age = atoi(age_str);
            float salary = atof(salary_str);

            // Create a new CvRecord node
            CvRecord* new_node = malloc(sizeof(CvRecord));
            strcpy(new_node->name, name);
            new_node->age = age;
            new_node->salary = salary;
            new_node->next = NULL;

            // Insert the new node into the head of the linked list
            if (*head == NULL)
            {
                *head = new_node;
            }
            else
            {
                (*head)->next = new_node;
                *head = new_node;
            }
        }

        fclose(resume_file);
    }
}

int main()
{
    CvRecord* head = NULL;
    parse_resume(&head);

    // Print the list of CvRecord nodes
    CvRecord* current = head;
    while (current)
    {
        printf("Name: %s, Age: %d, Salary: %.2f\n", current->name, current->age, current->salary);
        current = current->next;
    }

    return 0;
}