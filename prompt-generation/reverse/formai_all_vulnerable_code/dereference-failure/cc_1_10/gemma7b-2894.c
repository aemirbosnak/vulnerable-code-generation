//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about a student
typedef struct student {
    char name[50];
    int roll_no;
    float marks;
} student;

// Function to insert a student into the database
void insert_student(student *s) {
    printf("Enter student's name: ");
    scanf("%s", s->name);

    printf("Enter student's roll number: ");
    scanf("%d", &s->roll_no);

    printf("Enter student's marks: ");
    scanf("%f", &s->marks);
}

// Function to display a student's information
void display_student(student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("Marks: %.2f\n", s.marks);
}

// Function to search for a student
student *search_student(student *s, int roll_no) {
    for (int i = 0; i < 100; i++) {
        if (s[i].roll_no == roll_no) {
            return &s[i];
        }
    }

    return NULL;
}

int main() {
    // Create an array of students
    student *s = (student *)malloc(100 * sizeof(student));

    // Insert some students into the database
    insert_student(s);
    insert_student(s);
    insert_student(s);

    // Display a student's information
    display_student(s[0]);

    // Search for a student
    student *found_student = search_student(s, 12);

    // If the student is found, display their information
    if (found_student) {
        display_student(*found_student);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}