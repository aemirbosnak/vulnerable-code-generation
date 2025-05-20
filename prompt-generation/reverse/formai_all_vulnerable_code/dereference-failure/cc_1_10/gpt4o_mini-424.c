//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_MEMORY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Student;

void check_memory_allocation(Student *ptr, const char *var_name) {
    if (ptr == NULL) {
        fprintf(stderr, "Oops! Memory allocation failed for: %s\n", var_name);
        exit(EXIT_FAILURE);
    } else {
        printf("Hooray! Memory allocated successfully for: %s\n", var_name);
    }
}

void add_student(Student *students, int *count) {
    if (*count >= MAX_MEMORY) {
        fprintf(stderr, "Uh-oh! Maximum memory for students reached. Cannot add more.\n");
        return;
    }

    Student new_student;
    printf("Enter student's name: ");
    if (fgets(new_student.name, sizeof(new_student.name), stdin) == NULL) {
        fprintf(stderr, "Error reading input!\n");
        return;
    }
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove newline character

    printf("Enter student's ID: ");
    if (scanf("%d", &new_student.id) != 1) {
        fprintf(stderr, "Invalid ID entered!\n");
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }
    while(getchar() != '\n'); // Clear the input buffer after reading the ID

    students[*count] = new_student;
    (*count)++;
    printf("Success! Student added: %s (ID: %d)\n", new_student.name, new_student.id);
}

void display_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display. Let's add some!\n");
        return;
    }

    printf("\n====== Student List ======\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }
    printf("==========================\n");
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    printf("Welcome to the Student Record System! Let's get started with managing student records.\n");

    Student *students = (Student *)malloc(MAX_MEMORY * sizeof(Student));
    check_memory_allocation(students, "students array");

    int student_count = 0;
    int choice;

    do {
        printf("\nMenu:\n1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            handle_error("Invalid input! Please enter a number.");
        }

        switch (choice) {
            case 1:
                add_student(students, &student_count);
                break;
            case 2:
                display_students(students, student_count);
                break;
            case 3:
                printf("Exiting... Thank you for using the Student Record System!\n");
                break;
            default:
                handle_error("Invalid choice! Please select a valid option from the menu.");
        }
        
        while(getchar() != '\n'); // Clear the input buffer before next iteration

    } while (choice != 3);

    free(students);
    return 0;
}