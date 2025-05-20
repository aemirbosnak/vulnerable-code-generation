//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

// Struct for storing student information
typedef struct {
    char name[30];
    int age;
    char gender;
    float gpa;
} Student;

// Prototype for readStudent function
void readStudent(Student *s);

int main() {
    int n, i;
    float avgGPA = 0;
    
    // Ask for number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    // Allocate memory for array of n students
    Student *students = (Student*) malloc(n * sizeof(Student));
    
    // Read in student information
    for (i = 0; i < n; i++) {
        readStudent(&students[i]);
        avgGPA += students[i].gpa;  // Add to running total for average GPA calculation
    }
    
    // Calculate average GPA
    avgGPA /= n;
    
    // Print out student information and average GPA
    printf("\nStudent Information:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s\nAge: %d\nGender: %c\nGPA: %.2f\n\n", students[i].name, students[i].age, students[i].gender, students[i].gpa);
    }
    printf("Average GPA: %.2f\n", avgGPA);
    
    // Free allocated memory
    free(students);
    
    return 0;
}

// Function for reading in student information
void readStudent(Student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter student age: ");
    scanf("%d", &s->age);
    printf("Enter student gender (M/F): ");
    scanf(" %c", &s->gender);
    printf("Enter student GPA: ");
    scanf("%f", &s->gpa);
}