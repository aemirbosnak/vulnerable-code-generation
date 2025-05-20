//Falcon-180B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Structure for a student
struct student {
    int roll_no;
    char name[50];
    float marks;
};

// Function to compare two students based on their marks
int compare_marks(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;

    if (student_a->marks > student_b->marks)
        return 1;
    else if (student_a->marks < student_b->marks)
        return -1;
    else
        return 0;
}

// Function to print the details of a student
void print_student(struct student student) {
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n\n", student.marks);
}

// Function to read the details of a student from the user
struct student read_student() {
    struct student student;

    printf("Enter the roll number: ");
    scanf("%d", &student.roll_no);

    printf("Enter the name: ");
    scanf("%s", student.name);

    printf("Enter the marks: ");
    scanf("%f", &student.marks);

    return student;
}

// Function to read the number of students from the user
int read_number_of_students() {
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    return num_students;
}

// Function to sort the students based on their marks
void sort_students(struct student students[], int num_students) {
    qsort(students, num_students, sizeof(struct student), compare_marks);
}

// Function to print the sorted list of students
void print_sorted_students(struct student students[], int num_students) {
    printf("Sorted list of students:\n");
    for (int i = 0; i < num_students; i++) {
        print_student(students[i]);
    }
}

int main() {
    int num_students = read_number_of_students();
    struct student students[num_students];

    for (int i = 0; i < num_students; i++) {
        students[i] = read_student();
    }

    sort_students(students, num_students);
    print_sorted_students(students, num_students);

    return 0;
}