//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int age;
    float grade;
};

// Function to add a new student to the database
void add_student(struct Student *students, int num_students) {
    int index = rand() % num_students;
    students[index].name[0] = 'A';
    students[index].age = rand() % 100;
    students[index].grade = (float) rand() / (float) RAND_MAX;
}

// Function to print all students in the database
void print_students(struct Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s, %d years old, grade %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

// Main function
int main() {
    // Create an array to hold the students
    struct Student students[100];
    int num_students = 0;

    // Open the database file
    FILE *database = fopen("students.db", "w");
    if (database == NULL) {
        printf("Error opening database file\n");
        return 1;
    }

    // Add some students to the database
    for (int i = 0; i < 10; i++) {
        add_student(students, num_students);
        fwrite(students, sizeof(struct Student), num_students, database);
        fflush(database);
    }

    // Close the database file
    fclose(database);

    // Print all students in the database
    printf("Printing all students in the database:\n");
    print_students(students, num_students);

    return 0;
}