//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct to hold student information
typedef struct {
    int id;
    char name[20];
    int age;
    float gpa;
} Student;

// global array of students
Student *students;
int num_students = 0;

// function to add a student to the array
void add_student(int id, char *name, int age, float gpa) {
    // increase size of student array
    num_students++;
    students = realloc(students, num_students * sizeof(Student));
    // create new student and add to array
    int index = num_students - 1;
    students[index].id = id;
    strcpy(students[index].name, name);
    students[index].age = age;
    students[index].gpa = gpa;
}

// function to print all students in array
void print_students() {
    printf("ID\tName\tAge\tGPA\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%d\t%.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
}

// main function
int main() {
    // allocate initial memory for student array
    students = malloc(sizeof(Student));

    // add sample students to array
    add_student(1001, "John", 19, 3.6);
    add_student(1002, "Michelle", 20, 3.8);
    add_student(1003, "David", 19, 3.4);
    add_student(1004, "Sarah", 21, 3.9);

    // print all students
    print_students();

    // search for student by name
    char search_name[20];
    printf("Enter name of student to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Student found:\n");
            printf("ID\tName\tAge\tGPA\n");
            printf("%d\t%s\t%d\t%.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
            break;
        }
        if (i == num_students - 1) {
            printf("Student not found.\n");
        }
    }

    // free memory and exit
    free(students);
    return 0;
}