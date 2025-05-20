//Falcon-180B DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a structure for our data
typedef struct {
    int id;
    char name[20];
    float score;
} Student;

// Function to initialize a student with default values
void init_student(Student* s) {
    s->id = -1;
    strcpy(s->name, "Unknown");
    s->score = 0.0;
}

// Function to allocate memory for a new student
Student* new_student() {
    Student* s = (Student*)malloc(sizeof(Student));
    if (s == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    init_student(s);
    return s;
}

// Function to free memory used by a student
void free_student(Student* s) {
    free(s);
}

// Function to print a student's information
void print_student(Student* s) {
    printf("ID: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Score: %.2f\n", s->score);
}

int main() {
    // Create some students
    Student* s1 = new_student();
    init_student(s1);
    s1->id = 1;
    strcpy(s1->name, "John Doe");
    s1->score = 85.5;

    Student* s2 = new_student();
    init_student(s2);
    s2->id = 2;
    strcpy(s2->name, "Jane Smith");
    s2->score = 92.0;

    // Print their information
    print_student(s1);
    print_student(s2);

    // Free their memory
    free_student(s1);
    free_student(s2);

    return 0;
}