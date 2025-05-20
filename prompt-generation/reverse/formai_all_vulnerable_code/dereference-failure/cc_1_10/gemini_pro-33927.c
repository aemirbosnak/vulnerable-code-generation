//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct {
    int rollno;
    char name[50];
    int marks;
} student;

// Function to create a new student
student* create_student(int rollno, char *name, int marks) {
    student *new_student = (student*)malloc(sizeof(student));
    new_student->rollno = rollno;
    strcpy(new_student->name, name);
    new_student->marks = marks;
    return new_student;
}

// Function to print student data
void print_student(student *student) {
    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %d\n", student->marks);
}

// Function to compare two students by roll number
int compare_students(const void *a, const void *b) {
    student *student1 = (student*)a;
    student *student2 = (student*)b;
    return student1->rollno - student2->rollno;
}

// Function to sort students by roll number
void sort_students(student *students, int num_students) {
    qsort(students, num_students, sizeof(student), compare_students);
}

// Function to search for a student by roll number
student* search_student(student *students, int num_students, int rollno) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].rollno == rollno) {
            return &students[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Create an array of students
    student students[] = {
        create_student(1, "John Doe", 85),
        create_student(2, "Jane Smith", 90),
        create_student(3, "Michael Jones", 75),
        create_student(4, "Mary Johnson", 80),
        create_student(5, "David Williams", 95)
    };
    
    // Print the original array of students
    printf("Original array of students:\n");
    for (int i = 0; i < 5; i++) {
        print_student(&students[i]);
        printf("\n");
    }

    // Sort the array of students by roll number
    sort_students(students, 5);

    // Print the sorted array of students
    printf("\nSorted array of students:\n");
    for (int i = 0; i < 5; i++) {
        print_student(&students[i]);
        printf("\n");
    }

    // Search for a student by roll number
    int rollno = 3;
    student *found_student = search_student(students, 5, rollno);
    if (found_student != NULL) {
        printf("\nStudent with roll number %d found:\n", rollno);
        print_student(found_student);
    } else {
        printf("\nStudent with roll number %d not found.\n", rollno);
    }

    return 0;
}