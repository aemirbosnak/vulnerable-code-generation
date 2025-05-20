//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Candidate
{
    char name[MAX];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* insertCandidate(Candidate* head, char* name, int age, float salary)
{
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));

    strcpy(newCandidate->name, name);
    newCandidate->age = age;
    newCandidate->salary = salary;
    newCandidate->next = NULL;

    if (head == NULL)
    {
        head = newCandidate;
    }
    else
    {
        head->next = newCandidate;
    }

    return head;
}

void parseResumes(Candidate* head)
{
    Candidate* currentCandidate = head;

    while (currentCandidate)
    {
        printf("Name: %s\n", currentCandidate->name);
        printf("Age: %d\n", currentCandidate->age);
        printf("Salary: %.2f\n", currentCandidate->salary);
        printf("\n");

        currentCandidate = currentCandidate->next;
    }
}

int main()
{
    Candidate* head = NULL;

    insertCandidate(head, "John Doe", 25, 50000);
    insertCandidate(head, "Jane Doe", 30, 60000);
    insertCandidate(head, "Peter Pan", 12, 30000);

    parseResumes(head);

    return 0;
}