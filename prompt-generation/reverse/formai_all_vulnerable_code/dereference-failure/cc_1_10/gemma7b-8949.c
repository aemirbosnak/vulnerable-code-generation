//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store a student's information
typedef struct student {
    char name[20];
    int roll_no;
    float marks;
    struct student *next;
} student;

// Function to insert a student at the end of the linked list
void insert_at_end(student **head) {
    student *new_node = (student *)malloc(sizeof(student));
    printf("Enter student name: ");
    scanf("%s", new_node->name);
    printf("Enter student roll number: ");
    scanf("%d", &new_node->roll_no);
    printf("Enter student marks: ");
    scanf("%f", &new_node->marks);

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }

    new_node->next = NULL;
}

// Function to display all students
void display_students(student *head) {
    while (head) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", head->name, head->roll_no, head->marks);
        head = head->next;
    }
}

int main() {
    student *head = NULL;
    int choice;

    while (1) {
        printf("1. Insert student\n");
        printf("2. Display students\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_at_end(&head);
                break;
            case 2:
                display_students(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}