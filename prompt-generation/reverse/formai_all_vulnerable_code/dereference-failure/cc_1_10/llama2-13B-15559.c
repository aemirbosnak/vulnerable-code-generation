//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 5

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float grade[MAX_GRADE_LENGTH];
} student_t;

// Function to create a new student
student_t* create_student(char* name, float grade) {
    student_t* new_student = (student_t*) malloc(sizeof(student_t));
    strcpy(new_student->name, name);
    new_student->grade[0] = grade;
    return new_student;
}

// Function to print a student's information
void print_student(student_t* student) {
    printf("Name: %s\nGrade: %f\n", student->name, student->grade[0]);
}

// Function to calculate the average grade
float calculate_average(student_t* student) {
    int i;
    float average = 0;
    for (i = 0; i < MAX_GRADE_LENGTH; i++) {
        average += student->grade[i];
    }
    average /= MAX_GRADE_LENGTH;
    return average;
}

// Function to display the top 3 students
void display_top_students(student_t** students, int num_students) {
    int i, j;
    float highest_average = 0;
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < MAX_GRADE_LENGTH; j++) {
            if (students[i]->grade[j] > highest_average) {
                highest_average = students[i]->grade[j];
            }
        }
    }
    for (i = 0; i < num_students; i++) {
        printf("Top Student: %s (Average: %f)\n", students[i]->name, highest_average);
    }
}

int main() {
    srand(time(NULL));

    // Create 5 students
    student_t* students[5];
    for (int i = 0; i < 5; i++) {
        char* name = "Student " + (i + 1) < 10 ? "1-9" : "10-19";
        float grade = (i % 2) ? 80.0f + (rand() % 20 - 10) / 10.0f : 90.0f + (rand() % 20 - 10) / 10.0f;
        students[i] = create_student(name, grade);
    }

    // Calculate the average grade for each student
    for (int i = 0; i < 5; i++) {
        students[i]->grade[1] = calculate_average(students[i]);
    }

    // Display the top 3 students
    display_top_students(students, 5);

    return 0;
}