//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Resume* next;
} Resume;

int main()
{
    Resume* head = NULL;
    char buffer[MAX_NAME_LENGTH];
    int age;
    float salary;

    // Open the resume file
    FILE* file = fopen("resume.txt", "r");

    // Read the resume file line by line
    while (fgets(buffer, MAX_NAME_LENGTH, file) != NULL)
    {
        // Extract the name, age, and salary from the line
        char* name = strtok(buffer, ":");
        int age_int = atoi(strtok(name, " "));
        float salary_float = atof(strtok(strtok(NULL, ":"), " "));

        // Create a new resume node
        Resume* new_node = malloc(sizeof(Resume));
        strcpy(new_node->name, name);
        new_node->age = age_int;
        new_node->salary = salary_float;
        new_node->next = head;
        head = new_node;
    }

    // Print the resume nodes
    for (Resume* node = head; node; node = node->next)
    {
        printf("%s, %d, %.2f\n", node->name, node->age, node->salary);
    }

    // Close the resume file
    fclose(file);

    return 0;
}