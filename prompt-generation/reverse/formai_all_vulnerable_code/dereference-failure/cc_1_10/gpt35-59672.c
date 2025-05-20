//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[20];
    int age;
    float gpa;
} Student;

void insert_record(Student **students, int *num_students) {
    char name[20];
    int age;
    float gpa;

    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter student age: ");
    scanf("%d", &age);
    printf("Enter student GPA: ");
    scanf("%f", &gpa);

    (*num_students)++;
    *students = (Student *) realloc(*students, *num_students * sizeof(Student));
    strcpy((*students)[*num_students - 1].name, name);
    (*students)[*num_students - 1].age = age;
    (*students)[*num_students - 1].gpa = gpa;

    printf("Record added successfully!\n");
}

void view_records(Student *students, int num_students) {
    if (num_students == 0) {
        printf("No records found!\n");
        return;
    }

    printf("Name\tAge\tGPA\n");

    for (int i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

void search_record(Student *students, int num_students) {
    if (num_students == 0) {
        printf("No records found!\n");
        return;
    }

    char search_name[20];
    printf("Enter the name to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            found = 1;
            printf("Record found!\n");
            printf("Name\tAge\tGPA\n");
            printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
            break;
        }
    }

    if (!found) {
        printf("Record not found!\n");
    }
}

int main() {
    Student *students = NULL;
    int num_students = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record(&students, &num_students);
                break;

            case 2:
                view_records(students, num_students);
                break;

            case 3:
                search_record(students, num_students);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    free(students);

    return 0;
}