//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade[MAX_GRADE_LENGTH];
} student_t;

// Function to create a new student
student_t* create_student(char* name, int grade) {
    student_t* new_student = (student_t*) malloc(sizeof(student_t));
    strcpy(new_student->name, name);
    new_student->grade[0] = grade;
    return new_student;
}

// Function to print student information
void print_student(student_t* student) {
    printf("Name: %s\nGrade: %d\n", student->name, student->grade[0]);
}

// Function to calculate and print the average grade
void print_average(student_t* student) {
    int sum = 0;
    for (int i = 0; i < MAX_GRADE_LENGTH; i++) {
        sum += student->grade[i];
    }
    printf("Average grade: %d\n", sum / MAX_GRADE_LENGTH);
}

int main() {
    student_t* john = create_student("John", 80);
    student_t* jane = create_student("Jane", 90);
    student_t* bob = create_student("Bob", 75);

    print_student(john);
    print_student(jane);
    print_student(bob);

    print_average(john);
    print_average(jane);
    print_average(bob);

    return 0;
}