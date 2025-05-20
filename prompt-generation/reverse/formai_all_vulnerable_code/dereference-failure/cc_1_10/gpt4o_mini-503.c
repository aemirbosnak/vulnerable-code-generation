//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Function Prototypes
Student* createStudent(int id, const char* name, int age);
void addStudent(Student** head, int id, const char* name, int age);
void listStudents(Student* head);
Student* searchStudent(Student* head, int id);
void freeList(Student* head);

// Main function
int main() {
    Student* head = NULL;
    int choice, id, age;
    char name[50];

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                printf("Enter Student Name: ");
                scanf(" %[^\n]", name);  // Read string with spaces
                printf("Enter Student Age: ");
                scanf("%d", &age);
                addStudent(&head, id, name, age);
                printf("Student added successfully!\n");
                break;
            case 2:
                listStudents(head);
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                Student* foundStudent = searchStudent(head, id);
                if (foundStudent) {
                    printf("Student found: ID: %d, Name: %s, Age: %d\n", foundStudent->id, foundStudent->name, foundStudent->age);
                } else {
                    printf("Student with ID %d not found!\n", id);
                }
                break;
            case 4:
                freeList(head);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Function to create a new student
Student* createStudent(int id, const char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the linked list
void addStudent(Student** head, int id, const char* name, int age) {
    Student* newStudent = createStudent(id, name, age);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to list all students
void listStudents(Student* head) {
    if (head == NULL) {
        printf("No students in the database.\n");
        return;
    }
    
    Student* temp = head;
    printf("=== List of Students ===\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", temp->id, temp->name, temp->age);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudent(Student* head, int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to free the linked list
void freeList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}