//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50

// structure for a student
typedef struct {
    int id;
    char name[MAX_SIZE];
    float grade;
} Student;

// function prototypes
void add_student(Student *students, int *num_students);
void print_students(Student *students, int num_students);
void search_student(Student *students, int num_students, int search_id);

int main() {
    int option, num_students = 0, search_id;
    Student *students = malloc(sizeof(Student));
    do {
        printf("\nEnter 1 to add a student\n");
        printf("Enter 2 to print the list of students\n");
        printf("Enter 3 to search for a student\n");
        printf("Enter 0 to exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                print_students(students, num_students);
                break;
            case 3:
                printf("\nEnter student ID to search: ");
                scanf("%d", &search_id);
                search_student(students, num_students, search_id);
                break;
            case 0:
                free(students);
                printf("\nThank you for using our program!\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    } while(option != 0);
    return 0;
}

// function to add a student
void add_student(Student *students, int *num_students) {
    // allocate memory for a new student
    Student new_student;
    printf("\nEnter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student grade: ");
    scanf("%f", &new_student.grade);
    students[*num_students] = new_student;
    (*num_students)++;
    // reallocate memory for the students array
    Student *temp = realloc(students, (*num_students + 1) * sizeof(Student));
    if(temp != NULL) {
        students = temp;
    }
}

// function to print the list of students
void print_students(Student *students, int num_students) {
    printf("\nList of students:\n");
    for(int i=0; i<num_students; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// function to search for a student
void search_student(Student *students, int num_students, int search_id) {
    for(int i=0; i<num_students; i++) {
        if(students[i].id == search_id) {
            printf("\nStudent found:\n");
            printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }
    printf("\nStudent not found.\n");
}