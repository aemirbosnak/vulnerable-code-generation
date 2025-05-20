//Gemma-7B DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to store student data
typedef struct Student {
    char name[50];
    int rollno;
    float marks;
    struct Student *next;
} Student;

// Function to insert a student at the end
void insertStudent(Student **head) {
    Student *newNode = (Student *)malloc(sizeof(Student));
    scanf("Enter name: ", newNode->name);
    scanf("Enter roll no: ", &newNode->rollno);
    scanf("Enter marks: ", &newNode->marks);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
    (*head)->next = NULL;
}

// Function to calculate the average marks of a student
float calculateAverageMarks(Student *head) {
    float totalMarks = 0.0f;
    int totalStudents = 0;

    while (head) {
        totalMarks += head->marks;
        totalStudents++;
        head = head->next;
    }

    return totalMarks / totalStudents;
}

int main() {
    Student *head = NULL;

    // Insert students into the linked list
    insertStudent(&head);
    insertStudent(&head);
    insertStudent(&head);

    // Calculate the average marks of a student
    float averageMarks = calculateAverageMarks(head);

    // Print the average marks
    printf("The average marks of the students are: %f", averageMarks);

    return 0;
}