//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_GRADE_LEN 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LEN];
    int grade[MAX_GRADE_LEN];
} Student;

// Function to print student information
void print_student(Student *student) {
    printf("Name: %s\nGrade: ", student->name);
    for (int i = 0; i < MAX_GRADE_LEN; i++) {
        printf("%d ", student->grade[i]);
    }
    printf("\n");
}

// Function to get student information
int get_student_info(Student **student) {
    int choice;
    char name[MAX_NAME_LEN];
    int grade[MAX_GRADE_LEN];

    do {
        printf("Enter your name: ");
        fgets(name, MAX_NAME_LEN, stdin);
        printf("Enter your grade: ");
        scanf("%d%*c", grade);
        choice = getch();

        // Handle invalid input
        if (choice == '\n' || choice == EOF) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Check if the name is too long
        if (strlen(name) > MAX_NAME_LEN) {
            printf("Name too long. Please try again.\n");
            continue;
        }

        // Check if the grade is too large
        for (int i = 0; i < MAX_GRADE_LEN; i++) {
            if (grade[i] > 100) {
                printf("Grade too large. Please try again.\n");
                continue;
            }
        }

        // Store the student information
        *student = (Student *)malloc(sizeof(Student));
        strcpy((*student)->name, name);
        for (int i = 0; i < MAX_GRADE_LEN; i++) {
            (*student)->grade[i] = grade[i];
        }
        break;
    } while (1);

    return 0;
}

int main() {
    Student *student = NULL;

    // Get student information
    get_student_info(&student);

    // Print student information
    print_student(student);

    return 0;
}