//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// A structure to store a student's data
typedef struct student {
    char name[50];
    int roll_number;
    float marks;
    struct student *next;
} student;

// A function to create a new student node
student *create_student(char *name, int roll_number, float marks) {
    student *new_student = (student *)malloc(sizeof(student));
    strcpy(new_student->name, name);
    new_student->roll_number = roll_number;
    new_student->marks = marks;
    new_student->next = NULL;
    return new_student;
}

// A function to insert a new student node into a linked list in sorted order (ascending order of roll numbers)
void insert_student(student **head, student *new_student) {
    if (*head == NULL) {
        *head = new_student;
    } else {
        student *current = *head;
        while (current->next != NULL && current->next->roll_number < new_student->roll_number) {
            current = current->next;
        }
        new_student->next = current->next;
        current->next = new_student;
    }
}

// A function to print the student data in a linked list
void print_students(student *head) {
    student *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Roll Number: %d\n", current->roll_number);
        printf("Marks: %.2f\n\n", current->marks);
        current = current->next;
    }
}

// A function to free the memory allocated to a linked list
void free_students(student *head) {
    student *current, *next;
    current = head;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// The main function
int main() {
    // Create a linked list of students
    student *head = NULL;
    insert_student(&head, create_student("John Doe", 1, 85.5));
    insert_student(&head, create_student("Jane Doe", 2, 90.0));
    insert_student(&head, create_student("Peter Parker", 3, 87.5));
    insert_student(&head, create_student("Mary Jane Watson", 4, 82.0));
    insert_student(&head, create_student("Harry Osborn", 5, 78.5));

    // Print the student data
    printf("Students:\n");
    print_students(head);

    // Free the memory allocated to the linked list
    free_students(head);

    return 0;
}