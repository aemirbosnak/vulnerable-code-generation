//LLAMA2-13B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 5
#define MAX_SUBJECT_LENGTH 10

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char grade[MAX_GRADE_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
} student_t;

// Function to print a message on the screen
void print_message(const char* message) {
    printf("%s\n", message);
}

// Function to get user input and store it in a struct
student_t get_student_info() {
    student_t student;

    printf("Enter your name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);

    printf("Enter your grade (e.g., A, B, C, etc.): ");
    fgets(student.grade, MAX_GRADE_LENGTH, stdin);

    printf("Enter your subject (e.g., Math, English, Science, etc.): ");
    fgets(student.subject, MAX_SUBJECT_LENGTH, stdin);

    return student;
}

// Function to calculate and print the student's average grade
void calculate_average(student_t* student) {
    int i;
    int sum = 0;

    for (i = 0; i < strlen(student->grade); i++) {
        sum += (student->grade[i] - 'A') + 1;
    }

    printf("Your average grade is: %d\n", sum / strlen(student->grade));
}

int main() {
    student_t student;

    do {
        // Get user input and store it in the struct
        student = get_student_info();

        // Calculate and print the student's average grade
        calculate_average(&student);

        // Print a message asking the user if they want to continue
        print_message("Do you want to enter another student? (y/n)");

        // Get the user's response and exit if they say no
        char response;
        scanf("%c", &response);
        if (response == 'n' || response == 'N') {
            break;
        }
    } while (1);

    return 0;
}