//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declare the struct for a student
struct Student {
    char name[20];
    int age;
    float gpa;
    struct Student* next;
};

// Declare the functions for our database simulation
void addStudent(struct Student** headRef);
void removeStudent(struct Student** headRef);
void printDatabase(struct Student* head);

int main() {
    // Declare the variables for our menu
    int choice;
    bool running = true;
    
    // Declare the head pointer for our linked list
    struct Student* head = NULL;
    
    // Loop through the menu system until the user chooses to exit
    while (running) {
        printf("Welcome to the Student Database Simulation!\n");
        printf("Please select an option:\n");
        printf("1. Add a Student\n");
        printf("2. Remove a Student\n");
        printf("3. Print the Database\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        // Use a switch statement to determine user's choice
        switch (choice) {
            case 1:
                addStudent(&head); // Pass in the address of the head pointer
                break;
            case 2:
                removeStudent(&head); // Pass in the address of the head pointer
                break;
            case 3:
                printDatabase(head); // Pass in the value of the head pointer
                break;
            case 4:
                running = false; // Set running to false to exit the loop
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
        printf("\n");
    }
    
    printf("Thank you for using the Student Database Simulation!\n");
    
    return 0;
}

/* A function to add a new student to the head of the linked list */
void addStudent(struct Student** headRef) {
    // Allocate memory for the new student node
    struct Student* newNode = (struct Student*) malloc(sizeof(struct Student));
    
    // Prompt user for student information
    printf("Please enter the student's name: ");
    scanf("%s", newNode->name);
    printf("Please enter the student's age: ");
    scanf("%d", &newNode->age);
    printf("Please enter the student's GPA: ");
    scanf("%f", &newNode->gpa);
    
    // Set the new node's next pointer to the current head
    newNode->next = *headRef;
    
    // Set the head pointer to the new node
    *headRef = newNode;
    
    printf("Student added!\n");
}

/* A function to remove a student from the linked list */
void removeStudent(struct Student** headRef) {
    // Prompt user for student name to remove
    char name[20];
    printf("Please enter the name of the student to remove: ");
    scanf("%s", name);
    
    // Declare two pointers to traverse the linked list
    struct Student* current = *headRef;
    struct Student* previous = NULL;
    
    // Loop through the linked list until we find the desired student or reach the end
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    
    // If current is not NULL, we found the desired student, so remove it
    if (current != NULL) {
        // If previous is NULL, we are removing the head node
        if (previous == NULL) {
            *headRef = current->next; // Set the head to the next node
        } else {
            previous->next = current->next; // Set the previous node's next to the next node
        }
        
        // Free the memory for the removed node
        free(current);
        
        printf("Student removed!\n");
    } else {
        printf("Student not found.\n");
    }
}

/* A function to print the entire database */
void printDatabase(struct Student* head) {
    // Loop through the entire linked list and print each student's information
    struct Student* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("GPA: %0.2f\n", current->gpa);
        printf("\n");
        current = current->next;
    }
}