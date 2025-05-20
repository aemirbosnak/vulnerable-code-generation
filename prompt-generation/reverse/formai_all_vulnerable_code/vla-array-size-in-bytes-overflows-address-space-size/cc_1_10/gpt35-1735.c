//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void insertData(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter student %d ID: ", i+1);
        scanf("%d", &s[i].id);
        printf("Enter student %d name: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter student %d GPA: ", i+1);
        scanf("%f", &s[i].gpa);
    }
}

void displayData(struct Student s[], int n) {
    printf("\nID\tName\t\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-20s%.2f\n", s[i].id, s[i].name, s[i].gpa);
    }
}

void queryData(struct Student s[], int n) {
    int choice;
    printf("Select search criteria:\n");
    printf("1. By ID\n");
    printf("2. By Name\n");
    printf("3. By GPA\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int id;
            printf("Enter student ID: ");
            scanf("%d", &id);
            for (int i = 0; i < n; i++) {
                if (s[i].id == id) {
                    printf("\nID\tName\t\tGPA\n");
                    printf("%d\t%-20s%.2f\n", s[i].id, s[i].name, s[i].gpa);
                    return;
                }
            }
            printf("Student with ID %d not found.\n", id);
            break;
        }
        case 2: {
            char name[50];
            printf("Enter student name: ");
            scanf("%s", name);
            for (int i = 0; i < n; i++) {
                if (strcmp(s[i].name, name) == 0) {
                    printf("\nID\tName\t\tGPA\n");
                    printf("%d\t%-20s%.2f\n", s[i].id, s[i].name, s[i].gpa);
                    return;
                }
            }
            printf("Student with name %s not found.\n", name);
            break;
        }
        case 3: {
            float gpa;
            printf("Enter student GPA: ");
            scanf("%f", &gpa);
            for (int i = 0; i < n; i++) {
                if (s[i].gpa == gpa) {
                    printf("\nID\tName\t\tGPA\n");
                    printf("%d\t%-20s%.2f\n", s[i].id, s[i].name, s[i].gpa);
                    return;
                }
            }
            printf("Student with GPA %.2f not found.\n", gpa);
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    insertData(students, n);
    displayData(students, n);
    queryData(students, n);
    return 0;
}