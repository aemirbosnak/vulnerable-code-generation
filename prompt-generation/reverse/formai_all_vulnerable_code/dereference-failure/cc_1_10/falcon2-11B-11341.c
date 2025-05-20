//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    int roll_no;
    int marks[3];
};

void insert_student(struct Student *students, int n) {
    char name[50];
    int age, roll_no;
    int marks[3];

    printf("Enter student details:\n");
    scanf("%d %s %d %d %d %d %d %d %d %d\n", &students[n].id, name, &age, &roll_no, marks, &marks[1], &marks[2], &marks[3], &marks[4], &marks[5]);
}

void print_student(struct Student *students, int n) {
    printf("%d %s %d %d %d %d %d %d %d %d\n", students[n].id, students[n].name, students[n].age, students[n].roll_no, students[n].marks[0], students[n].marks[1], students[n].marks[2], students[n].marks[3], students[n].marks[4], students[n].marks[5]);
}

void search_student(struct Student *students, int n) {
    char name[50];
    int id;

    printf("Enter student id:\n");
    scanf("%d\n", &id);

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("%s %d %d %d %d %d %d %d %d %d\n", students[i].name, students[i].age, students[i].roll_no, students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].marks[3], students[i].marks[4], students[i].marks[5]);
        }
    }
}

void update_student(struct Student *students, int n) {
    char name[50];
    int age, roll_no;
    int marks[3];

    printf("Enter student id:\n");
    scanf("%d\n", &students[n].id);

    printf("Enter new student details:\n");
    scanf("%s %d %d %d %d %d %d %d %d %d\n", name, &age, &roll_no, marks, &marks[1], &marks[2], &marks[3], &marks[4], &marks[5]);
}

void delete_student(struct Student *students, int n) {
    char name[50];
    int id;

    printf("Enter student id:\n");
    scanf("%d\n", &id);

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            strcpy(name, students[i].name);
            strcpy(students[i].name, "");
            for (int j = 0; j < 3; j++) {
                strcpy(students[i].marks[j], "");
            }
            for (int j = 0; j < 3; j++) {
                students[i].marks[j] = students[i].marks[j + 1];
            }
            students[i].marks[3] = 0;
            students[i].marks[4] = 0;
            students[i].marks[5] = 0;
            n--;
            printf("%s %d %d %d %d %d %d %d %d %d\n", name, students[i].age, students[i].roll_no, students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].marks[3], students[i].marks[4], students[i].marks[5]);
            break;
        }
    }
}

int main() {
    int n = 5;
    struct Student students[n];
    int choice, id;

    do {
        printf("Enter your choice:\n");
        printf("1. Insert student\n");
        printf("2. Print student\n");
        printf("3. Search student\n");
        printf("4. Update student\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_student(students, n);
                break;
            case 2:
                print_student(students, n);
                break;
            case 3:
                search_student(students, n);
                break;
            case 4:
                update_student(students, n);
                break;
            case 5:
                delete_student(students, n);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}