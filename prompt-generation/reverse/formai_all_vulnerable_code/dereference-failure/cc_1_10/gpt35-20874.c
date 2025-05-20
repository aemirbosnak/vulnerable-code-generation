//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure that represents a student in class
typedef struct {
    int student_id;
    char name[20];
    float gpa;
} Student;

// Function to create a new student and return a pointer to it
Student *create_student(int id, char *name, float gpa) {
    Student *student = malloc(sizeof(Student));
    student->student_id = id;
    strncpy(student->name, name, sizeof(student->name));
    student->gpa = gpa;
    return student;
}

// Structure that represents a class of students
typedef struct {
    int capacity; // Maximum number of students in this class
    int size; // Current number of students in this class
    Student **students; // Pointer to an array of pointers to students
} Class;

// Function to create a new class with a given capacity
Class *create_class(int capacity) {
    Class *class = malloc(sizeof(Class));
    class->capacity = capacity;
    class->size = 0;
    class->students = calloc(capacity, sizeof(Student *));
    return class;
}

// Function to add a student to a class
void add_student(Class *class, Student *student) {
    if (class->size < class->capacity) {
        class->students[class->size] = student;
        class->size++;
    } else {
        printf("Class is full, unable to add student %s (ID: %d)\n", student->name, student->student_id);
    }
}

// Function to print the details of all students in a class
void print_class(Class *class) {
    printf("Class size: %d / %d\n", class->size, class->capacity);
    printf("Students:\n");
    for (int i = 0; i < class->size; i++) {
        printf("- ID: %d, Name: %s, GPA: %.2f\n", class->students[i]->student_id, class->students[i]->name, class->students[i]->gpa);
    }
}

int main() {
    // Create a new class with capacity for 3 students
    Class *my_class = create_class(3);

    // Create some sample students and add them to the class
    Student *student1 = create_student(1, "Alice", 3.7);
    add_student(my_class, student1);

    Student *student2 = create_student(2, "Bob", 3.9);
    add_student(my_class, student2);

    // This student won't fit in the class, as it's already at capacity
    Student *student3 = create_student(3, "Charlie", 2.8);
    add_student(my_class, student3);

    // Print out the class details
    print_class(my_class);

    // Free all memory allocated for students and the class itself
    free(student1);
    free(student2);
    free(student3);
    free(my_class->students);
    free(my_class);

    return 0;
}