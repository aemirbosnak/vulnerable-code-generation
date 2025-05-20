//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Define a struct to hold a node in our linked list
typedef struct node {
    Student data;
    struct node *next;
} Node;

// Function prototypes
void insertStudent(Node **head, Student newStudent);
void deleteStudent(Node **head, int id);
void printList(Node *head);
int findSize(Node *head);

int main() {
    // Create an empty linked list to hold our students
    Node *head = NULL;
    int choice;
    char buffer[50];
    Student newStudent;

    // Loop to display menu and get user input
    while (1) {
        printf("\nC Database Simulation\n");
        printf("----------------------\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");

        fgets(buffer, 50, stdin); // Get input as a string
        sscanf(buffer, "%d", &choice); // Convert string to integer

        if (choice == 1) { // Add Student
            printf("\nEnter student ID: ");
            fgets(buffer, 50, stdin);
            sscanf(buffer, "%d", &newStudent.id);

            printf("Enter student name: ");
            fgets(newStudent.name, 50, stdin);
            newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline character

            printf("Enter student age: ");
            fgets(buffer, 50, stdin);
            sscanf(buffer, "%d", &newStudent.age);

            printf("Enter student GPA: ");
            fgets(buffer, 50, stdin);
            sscanf(buffer, "%f", &newStudent.gpa);

            insertStudent(&head, newStudent); // Add the new student to the list
            printf("\nStudent added successfully!\n");
        } else if (choice == 2) { // Delete Student
            int id;
            printf("\nEnter ID of student to delete: ");
            fgets(buffer, 50, stdin);
            sscanf(buffer, "%d", &id);

            deleteStudent(&head, id); // Delete the student from the list
        } else if (choice == 3) { // Print List
            printf("\n");
            printList(head); // Print the list of students
        } else if (choice == 4) { // Exit
            break;
        } else {
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}

// Function to insert a new student into the list
void insertStudent(Node **head, Student newStudent) {
    Node *curr = *head;
    Node *prev = NULL;
    Node *newNode = (Node*) malloc(sizeof(Node));

    // Set the data for the new node
    newNode->data = newStudent;
    newNode->next = NULL;

    // Find the position to insert the new node
    while (curr != NULL && curr->data.id < newStudent.id) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) { // Insert at beginning of list
        newNode->next = *head;
        *head = newNode;
    } else { // Insert somewhere within the list
        newNode->next = curr;
        prev->next = newNode;
    }
}

// Function to delete a student from the list
void deleteStudent(Node **head, int id) {
    Node *curr = *head;
    Node *prev = NULL;

    // Find the node with the specified ID
    while (curr != NULL && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) { // ID not found
        printf("\nStudent with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) { // Delete at beginning of list
        *head = curr->next;
    } else { // Delete somewhere within the list
        prev->next = curr->next;
    }

    free(curr); // Free memory of the deleted node
    printf("\nStudent with ID %d deleted successfully!\n", id);
}

// Function to print the list of students
void printList(Node *head) {
    if (head == NULL) { // Empty list
        printf("No students in the database.\n");
        return;
    }

    printf("ID\tName\t\tAge\tGPA\n");
    printf("------------------------------------\n");

    // Loop through all nodes in the list and print their data
    while (head != NULL) {
        printf("%d\t%s\t\t%d\t%.2f\n", head->data.id, head->data.name, head->data.age, head->data.gpa);
        head = head->next;
    }

    printf("------------------------------------\n");
    printf("Total students: %d\n", findSize(head));
}

// Function to find the size of the list
int findSize(Node *head) {
    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }

    return size;
}