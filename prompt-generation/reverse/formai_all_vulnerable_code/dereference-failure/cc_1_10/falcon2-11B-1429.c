//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure to hold data for each student
struct student {
    char name[50];
    int age;
    double gpa;
    int test_scores[10];
    struct student* next;
};

// Define a linked list to hold all students
struct student* head = NULL;

// Function to add a new student to the list
void add_student(struct student* new_student) {
    new_student->next = head;
    head = new_student;
}

// Function to print the list of students
void print_list() {
    struct student* current = head;
    printf("Student List:\n");
    while (current!= NULL) {
        printf("%s (%d) - GPA: %.2f\n", current->name, current->age, current->gpa);
        for (int i = 0; i < 10; i++) {
            printf("Test Score %d: %.2f\n", i+1, current->test_scores[i]);
        }
        current = current->next;
    }
}

// Function to generate random test scores for a student
void generate_random_scores(struct student* student) {
    for (int i = 0; i < 10; i++) {
        student->test_scores[i] = rand() % 100 + 1;
    }
}

// Function to sort the list of students by GPA
void sort_list() {
    struct student* current = head;
    struct student* next = NULL;
    while (current!= NULL) {
        struct student* temp = current->next;
        for (int i = 0; i < 10; i++) {
            if (current->gpa > temp->gpa) {
                struct student* swapped = current;
                current = temp;
                temp = swapped;
            }
        }
        current->next = next;
        next = current;
        current = temp;
    }
    head = next;
}

// Function to calculate the average GPA for all students
double calculate_average_gpa() {
    double sum = 0;
    struct student* current = head;
    while (current!= NULL) {
        sum += current->gpa;
        current = current->next;
    }
    return sum / (sizeof(head) / sizeof(struct student*));
}

int main() {
    srand(time(NULL));

    // Add some students to the list
    add_student(malloc(sizeof(struct student)));
    add_student(malloc(sizeof(struct student)));
    add_student(malloc(sizeof(struct student)));
    add_student(malloc(sizeof(struct student)));

    // Generate random test scores for each student
    struct student* student1 = head;
    while (student1!= NULL) {
        generate_random_scores(student1);
        student1 = student1->next;
    }

    // Sort the list of students by GPA
    sort_list();

    // Print the sorted list of students
    printf("Sorted List:\n");
    print_list();

    // Calculate and print the average GPA for all students
    printf("Average GPA: %.2f\n", calculate_average_gpa());

    return 0;
}