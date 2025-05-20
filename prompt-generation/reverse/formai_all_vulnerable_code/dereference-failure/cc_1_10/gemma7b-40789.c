//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ADDRESS_LENGTH 255

typedef struct Student
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    struct Student* next;
} Student;

Student* insertStudent(Student* head, char* name, char* address, int age)
{
    Student* newStudent = malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    strcpy(newStudent->address, address);
    newStudent->age = age;
    newStudent->next = NULL;

    if (head == NULL)
    {
        return newStudent;
    }

    head->next = newStudent;
    return head;
}

void printStudents(Student* head)
{
    Student* currentStudent = head;
    while (currentStudent)
    {
        printf("%s, %s, %d\n", currentStudent->name, currentStudent->address, currentStudent->age);
        currentStudent = currentStudent->next;
    }
}

int main()
{
    Student* head = NULL;

    insertStudent(head, "John Doe", "123 Main St.", 20);
    insertStudent(head, "Jane Doe", "456 Oak Ave.", 21);
    insertStudent(head, "Peter Pan", "Neverland", 12);

    printStudents(head);

    return 0;
}