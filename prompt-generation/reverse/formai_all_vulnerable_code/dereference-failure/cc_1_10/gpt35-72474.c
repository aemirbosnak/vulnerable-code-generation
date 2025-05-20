//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[20];
    int age;
    char address[50];
    int marks;
};

int main() {
    int n, choice;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *students = (struct student*) malloc(n*sizeof(struct student));

    for(int i=0;i<n;i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("What do you want to do?\n");
    printf("1. Find the student with highest marks.\n");
    printf("2. Find the student with lowest marks.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int max_marks = students[0].marks;
            int max_index = 0;

            for(int i=1;i<n;i++) {
                if(students[i].marks > max_marks) {
                    max_marks = students[i].marks;
                    max_index = i;
                }
            }
            printf("The student with highest marks is %s. Their address is %s, age is %d and marks is %d.\n", students[max_index].name, students[max_index].address, students[max_index].age, students[max_index].marks);
            break;
        }
        case 2: {
            int min_marks = students[0].marks;
            int min_index = 0;

            for(int i=1;i<n;i++) {
                if(students[i].marks < min_marks) {
                    min_marks = students[i].marks;
                    min_index = i;
                }
            }
            printf("The student with lowest marks is %s. Their address is %s, age is %d and marks is %d.\n", students[min_index].name, students[min_index].address, students[min_index].age, students[min_index].marks);
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }

    free(students);

    return 0;
}