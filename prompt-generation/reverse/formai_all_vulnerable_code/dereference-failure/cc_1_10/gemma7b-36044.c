//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a structure to store a student's information
typedef struct Student {
    char name[20];
    int rollNo;
    float marks;
} Student;

// Create a linked list of students
typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// Function to insert a student at the end of the linked list
void insertAtEnd(Node** head, Student student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = student;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to print the students in the linked list
void printStudents(Node* head) {
    while (head) {
        printf("%s, %d, %.2f\n", head->data.name, head->data.rollNo, head->data.marks);
        head = head->next;
    }
}

int main() {
    // Create a linked list of students
    Node* head = NULL;

    // Insert some students into the linked list
    Student student1 = {"John Doe", 123, 90.5};
    insertAtEnd(&head, student1);

    Student student2 = {"Jane Doe", 456, 85.2};
    insertAtEnd(&head, student2);

    Student student3 = {"Peter Pan", 789, 95.1};
    insertAtEnd(&head, student3);

    // Print the students in the linked list
    printStudents(head);

    return 0;
}