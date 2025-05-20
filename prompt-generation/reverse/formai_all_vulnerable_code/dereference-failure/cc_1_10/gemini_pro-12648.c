//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct student {
    char name[50];
    int roll_no;
    int marks[5];
} student;

// Function to create a new student
student* create_student(char *name, int roll_no, int *marks) {
    student *new_student = (student*)malloc(sizeof(student));
    strcpy(new_student->name, name);
    new_student->roll_no = roll_no;
    for (int i = 0; i < 5; i++) {
        new_student->marks[i] = marks[i];
    }
    return new_student;
}

// Function to print student data
void print_student(student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->marks[i]);
    }
    printf("\n");
}

// Function to compare two students based on their roll numbers
int compare_students(const void *a, const void *b) {
    student *student1 = (student*)a;
    student *student2 = (student*)b;
    return student1->roll_no - student2->roll_no;
}

// Function to sort students based on their roll numbers
void sort_students(student **students, int num_students) {
    qsort(students, num_students, sizeof(student*), compare_students);
}

// Function to search for a student by roll number
student* search_student(student **students, int num_students, int roll_no) {
    for (int i = 0; i < num_students; i++) {
        if (students[i]->roll_no == roll_no) {
            return students[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Create an array of students
    student *students[] = {
        create_student("John Doe", 1, (int[]){90, 85, 95, 80, 92}),
        create_student("Jane Doe", 2, (int[]){85, 90, 92, 82, 88}),
        create_student("John Smith", 3, (int[]){80, 85, 90, 80, 95}),
        create_student("Jane Smith", 4, (int[]){90, 82, 88, 85, 90}),
        create_student("John Brown", 5, (int[]){85, 88, 92, 80, 93}),
    };

    // Sort the students based on their roll numbers
    sort_students(students, 5);

    // Print the sorted students
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
    }

    // Search for a student by roll number
    int roll_no = 3;
    student *student = search_student(students, 5, roll_no);
    if (student != NULL) {
        printf("Student found:\n");
        print_student(student);
    } else {
        printf("Student not found.\n");
    }

    // Free the memory allocated for the students
    for (int i = 0; i < 5; i++) {
        free(students[i]);
    }

    return 0;
}