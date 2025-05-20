//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* roll_no;
} Student;

void exam(Student* student) {
    printf("Exam started\n");
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Roll Number: %s\n", student->roll_no);
    printf("Enter your answer: ");
    char answer[100];
    scanf("%s", answer);
    if (strcmp(answer, "Correct Answer") == 0) {
        printf("Congratulations! You got the answer right.\n");
    } else {
        printf("Sorry, the answer was 'Correct Answer'.\n");
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    Student* students = malloc(num_students * sizeof(Student));

    printf("Enter the details of each student:\n");
    for (int i = 0; i < num_students; i++) {
        char name[100];
        int age;
        char roll_no[100];
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Roll Number: ");
        scanf("%s", roll_no);
        students[i].name = strdup(name);
        students[i].age = age;
        students[i].roll_no = strdup(roll_no);
    }

    for (int i = 0; i < num_students; i++) {
        exam(students + i);
        free(students[i].name);
        free(students[i].roll_no);
        free(students[i].name);
    }

    free(students);

    return 0;
}