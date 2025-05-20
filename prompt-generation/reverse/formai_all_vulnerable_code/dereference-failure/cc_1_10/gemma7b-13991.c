//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student information
typedef struct Student
{
    char name[50];
    int rollno;
    float marks;
} Student;

// Create a linked list of students
struct Node
{
    Student data;
    struct Node* next;
};

// Insert a student into the linked list
void insertStudent(struct Node** head, Student student)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

// Print the students in the linked list
void printStudents(struct Node* head)
{
    struct Node* current = head;
    while (current)
    {
        printf("%s (%d) - %.2f\n", current->data.name, current->data.rollno, current->data.marks);
        current = current->next;
    }
}

int main()
{
    // Create a linked list of students
    struct Node* head = NULL;

    // Insert some students into the linked list
    Student student1 = {"John Doe", 12345, 90.5};
    insertStudent(&head, student1);

    Student student2 = {"Jane Doe", 67890, 85.2};
    insertStudent(&head, student2);

    Student student3 = {"Peter Pan", 32146, 70.8};
    insertStudent(&head, student3);

    // Print the students in the linked list
    printStudents(head);

    return 0;
}