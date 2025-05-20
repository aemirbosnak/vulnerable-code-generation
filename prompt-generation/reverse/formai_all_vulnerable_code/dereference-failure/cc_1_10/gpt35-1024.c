//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing student info
typedef struct {
    char name[50];
    int roll_no;
    float gpa;
} Student;

// Function prototypes
void add_record(Student *students, int *num_students);
void delete_record(Student *students, int *num_students);
void display_records(Student *students, int num_students);

int main() {
    int num_students = 0, option;

    // Allocate memory for 20 students
    Student *students = (Student *) malloc(20 * sizeof(Student));

    while(1) {
        printf("\nMenu:\n1. Add student record\n2. Delete student record\n3. Display all student records\n4. Exit\nChoose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_record(students, &num_students);
                break;
            case 2:
                delete_record(students, &num_students);
                break;
            case 3:
                display_records(students, num_students);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    free(students);
    return 0;
}

void add_record(Student *students, int *num_students) {
    // Validate that we still have space for a new student
    if(*num_students >= 20) {
        printf("Error: cannot add more students. Database is full.\n");
        return;
    }

    // Get student info from user
    printf("\nEnter student name: ");
    scanf("%s", students[*num_students].name);
    printf("Enter student roll number: ");
    scanf("%d", &students[*num_students].roll_no);
    printf("Enter student GPA: ");
    scanf("%f", &students[*num_students].gpa);

    // Increment number of students in database
    (*num_students)++;

    printf("Record added successfully.\n");
}

void delete_record(Student *students, int *num_students) {
    int roll_no, i, found = 0;

    // Get roll number of student to delete
    printf("\nEnter roll number of student to delete: ");
    scanf("%d", &roll_no);

    // Find student in database and delete their record
    for(i = 0; i < *num_students; i++) {
        if(students[i].roll_no == roll_no) {
            found = 1;
            break;
        }
    }

    if(found) {
        // Shift all records after deleted record back one position in array
        for(; i < (*num_students) - 1; i++) {
            students[i] = students[i + 1];
        }

        // Decrement number of students in database
        (*num_students)--;

        printf("Record deleted successfully.\n");
    } else {
        printf("Error: student record not found.\n");
    }
}

void display_records(Student *students, int num_students) {
    // Validate that we have at least one student in database
    if(num_students == 0) {
        printf("Error: no student records found.\n");
        return;
    }

    printf("\n%-20s%-20s%-20s\n", "Name", "Roll Number", "GPA");
    printf("----------------------------------------------------\n");

    // Print all student records
    for(int i = 0; i < num_students; i++) {
        printf("%-20s%-20d%-20.2f\n", students[i].name, students[i].roll_no, students[i].gpa);
    }
}