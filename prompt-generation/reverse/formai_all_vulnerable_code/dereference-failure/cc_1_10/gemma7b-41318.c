//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct Student
{
    char name[50];
    int rollno;
    float marks;
    struct Student* next;
} Student;

// Function to insert a student at the end
void insertAtEnd(Student** head, Student* newStudent)
{
    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        (*head)->next = newStudent;
        *head = (*head)->next;
    }
}

// Function to print the students
void printStudents(Student* head)
{
    while (head)
    {
        printf("%s (Roll No. %d), Marks: %.2f\n", head->name, head->rollno, head->marks);
        head = head->next;
    }
}

int main()
{
    // Create a student structure
    Student* head = NULL;

    // Insert some students
    insertAtEnd(&head, (Student*)malloc(sizeof(Student)));
    strcpy(head->name, "John Doe");
    head->rollno = 123;
    head->marks = 90.5;

    insertAtEnd(&head, (Student*)malloc(sizeof(Student)));
    strcpy(head->name, "Jane Doe");
    head->rollno = 456;
    head->marks = 80.2;

    insertAtEnd(&head, (Student*)malloc(sizeof(Student)));
    strcpy(head->name, "Peter Pan");
    head->rollno = 789;
    head->marks = 70.1;

    // Print the students
    printStudents(head);

    return 0;
}