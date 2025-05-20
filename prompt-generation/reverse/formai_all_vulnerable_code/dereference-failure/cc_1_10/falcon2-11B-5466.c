//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* gender;
    char* phone_number;
} Student;

int main() {
    int n = 5;
    Student students[n];
    int i, j;
    int choice;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        students[i].name = (char*)malloc(10 * sizeof(char));
        students[i].age = rand() % 100 + 18;
        students[i].gender = (char*)malloc(10 * sizeof(char));
        students[i].phone_number = (char*)malloc(15 * sizeof(char));

        sprintf(students[i].name, "Student %d", i+1);
        sprintf(students[i].gender, "%s", (rand() % 2)? "Male" : "Female");
        sprintf(students[i].phone_number, "%s", (rand() % 3)? "1234567890" : "9876543210");

        printf("Student %d\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Gender: %s\n", students[i].gender);
        printf("Phone Number: %s\n\n", students[i].phone_number);
    }

    printf("Enter your choice:\n");
    printf("1. View all students\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < n; i++) {
                printf("Student %d\n", i+1);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Gender: %s\n", students[i].gender);
                printf("Phone Number: %s\n\n", students[i].phone_number);
            }
            break;
        case 2:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}