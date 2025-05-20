//FormAI DATASET v1.0 Category: Database simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char name[20];
    int id;
    float cgpa;
};

void create(struct Student *students, int n_students) {

    for(int i=0; i<n_students; i++) {
        printf("Enter name, ID and CGPA of student %d: ", i+1);
        scanf("%s %d %f", &students[i].name, &students[i].id, &students[i].cgpa);
    }
}

void insert(struct Student *students, int n_students) {

    int idx;
    printf("Enter index to insert: ");
    scanf("%d", &idx);

    if(idx >= 0 && idx <= n_students) {
        for(int i=n_students; i>=idx; i--) {
            students[i+1] = students[i];
        }
        printf("Enter name, ID and CGPA of new student: ");
        scanf("%s %d %f", &students[idx].name, &students[idx].id, &students[idx].cgpa);
    } else {
        printf("Invalid index\n");
    }
}

void display(struct Student *students, int n_students) {

    printf("Name\tID\tCGPA\n");
    for(int i=0; i<n_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].id, students[i].cgpa);
    }
}

void delete(struct Student *students, int n_students) {

    int idx;
    printf("Enter index to delete: ");
    scanf("%d", &idx);

    if(idx >= 0 && idx < n_students) {
        for(int i=idx+1; i<n_students; i++) {
            students[i-1] = students[i];
        }
    } else {
        printf("Invalid index\n");
    }
}

int main() {

    int choice, n_students;
    struct Student *students;

    printf("Enter number of students: ");
    scanf("%d", &n_students);

    students = (struct Student *)malloc(n_students * sizeof(struct Student));

    printf("Enter details of all students:\n");
    create(students, n_students);

    do {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(students, n_students); n_students++; break;
            case 2: display(students, n_students); break;
            case 3: delete(students, n_students); n_students--; break;
            case 4: break;
            default: printf("Invalid choice\n"); break;
        }

    } while(choice != 4);

    free(students);
    return 0;
}