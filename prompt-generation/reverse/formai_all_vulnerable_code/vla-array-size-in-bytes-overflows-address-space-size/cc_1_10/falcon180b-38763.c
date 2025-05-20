//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    int roll_no;
    int marks[5];
    int total_marks;
    float percentage;
} student;

void add_student(student* stu_arr, int num_students) {
    printf("\nEnter student details:\n");
    printf("Name: ");
    scanf("%s", stu_arr[num_students].name);
    printf("Age: ");
    scanf("%d", &stu_arr[num_students].age);
    printf("Roll No: ");
    scanf("%d", &stu_arr[num_students].roll_no);
    printf("Enter marks for 5 subjects:\n");
    for(int i=0; i<5; i++) {
        scanf("%d", &stu_arr[num_students].marks[i]);
    }
    stu_arr[num_students].total_marks = 0;
    for(int i=0; i<5; i++) {
        stu_arr[num_students].total_marks += stu_arr[num_students].marks[i];
    }
    stu_arr[num_students].percentage = (stu_arr[num_students].total_marks/500.0)*100;
}

void display_students(student* stu_arr, int num_students) {
    printf("\nStudents Details:\n");
    for(int i=0; i<num_students; i++) {
        printf("\nName: %s\n", stu_arr[i].name);
        printf("Age: %d\n", stu_arr[i].age);
        printf("Roll No: %d\n", stu_arr[i].roll_no);
        printf("Marks: ");
        for(int j=0; j<5; j++) {
            printf("%d ", stu_arr[i].marks[j]);
        }
        printf("\nTotal Marks: %d\n", stu_arr[i].total_marks);
        printf("Percentage: %.2f%\n\n", stu_arr[i].percentage);
    }
}

int main() {
    int num_students;
    printf("\nEnter number of students: ");
    scanf("%d", &num_students);
    student stu_arr[num_students];
    for(int i=0; i<num_students; i++) {
        add_student(stu_arr, num_students);
    }
    display_students(stu_arr, num_students);
    return 0;
}