//FormAI DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void printMenu() {
    printf("1. Add a student\n");
    printf("2. Display all students\n");
    printf("3. Search for a student\n");
    printf("4. Delete a student\n");
    printf("5. Exit\n");
}

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    struct Student *students = NULL;
    int numStudents = 0;
    int choice;

    do {
        printMenu();
        printf(">> ");
        scanf("%d", &choice);
        clearInput();

        switch (choice) {
            case 1: {
                // add a student
                struct Student s;
                printf("Enter student ID: ");
                scanf("%d", &s.id);
                clearInput();
                printf("Enter student name: ");
                fgets(s.name, 50, stdin);
                s.name[strcspn(s.name, "\n")] = 0; // remove newline character
                printf("Enter student age: ");
                scanf("%d", &s.age);
                clearInput();

                // add student to array
                numStudents++;
                students = realloc(students, numStudents * sizeof(struct Student));
                students[numStudents - 1] = s;

                printf("Student added successfully.\n\n");
                break;
            }
            case 2: {
                // display all students
                if (numStudents == 0) {
                    printf("There are no students.\n\n");
                } else {
                    printf("ID | Name               | Age\n");
                    printf("-----------------------------------\n");
                    for (int i = 0; i < numStudents; i++) {
                        printf("%-2d | %-18s | %-2d\n", students[i].id, students[i].name, students[i].age);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                // search for a student
                if (numStudents == 0) {
                    printf("There are no students.\n\n");
                } else {
                    int id;
                    printf("Enter student ID: ");
                    scanf("%d", &id);
                    clearInput();

                    int found = 0;
                    for (int i = 0; i < numStudents; i++) {
                        if (students[i].id == id) {
                            printf("ID | Name               | Age\n");
                            printf("-----------------------------------\n");
                            printf("%-2d | %-18s | %-2d\n", students[i].id, students[i].name, students[i].age);
                            printf("\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Student not found.\n\n");
                    }
                }
                break;
            }
            case 4: {
                // delete a student
                if (numStudents == 0) {
                    printf("There are no students.\n\n");
                } else {
                    int id;
                    printf("Enter student ID: ");
                    scanf("%d", &id);
                    clearInput();

                    int found = 0;
                    for (int i = 0; i < numStudents; i++) {
                        if (students[i].id == id) {
                            // delete student
                            for (int j = i; j < numStudents-1; j++) {
                                students[j] = students[j+1];
                            }
                            numStudents--;
                            students = realloc(students, numStudents * sizeof(struct Student));
                            printf("Student deleted successfully.\n\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Student not found.\n\n");
                    }
                }
                break;
            }
            case 5:
                // do nothing, the loop will end
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }

    } while (choice != 5);

    // free memory
    free(students);

    return 0;
}