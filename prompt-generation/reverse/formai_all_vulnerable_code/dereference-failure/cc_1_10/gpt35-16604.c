//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct student {
    char name[MAX_SIZE];
    int age;
    float gpa;
};

void write_student(FILE* file, struct student* s) {
    fwrite(s, sizeof(struct student), 1, file);
}

void read_student(FILE* file, struct student* s) {
    fread(s, sizeof(struct student), 1, file);
}

void print_student(struct student* s) {
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("GPA: %.2f\n\n", s->gpa);
}

int main() {
    FILE* file;
    char filename[MAX_SIZE];
    int choice, n;
    struct student s;

    printf("Welcome to the student file handler.\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Create a new file.\n");
        printf("2. Open an existing file.\n");
        printf("3. Write a student's record to the file.\n");
        printf("4. Display all student's records in the file.\n");
        printf("5. Remove a student's record from the file.\n");
        printf("6. Exit the program.\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                file = fopen(filename, "wb");
                if (file == NULL) {
                    printf("Error: Could not create file.\n");
                    continue;
                }
                printf("File created successfully.\n");
                break;
            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                file = fopen(filename, "rb+");
                if (file == NULL) {
                    printf("Error: Could not open file.\n");
                    continue;
                }
                printf("File opened successfully.\n");
                break;
            case 3:
                if (file == NULL) {
                    printf("Error: No file open.\n");
                    continue;
                }
                printf("Enter the name of the student: ");
                scanf("%s", s.name);
                printf("Enter the student's age: ");
                scanf("%d", &s.age);
                printf("Enter the student's GPA: ");
                scanf("%f", &s.gpa);
                write_student(file, &s);
                printf("Student record added.\n");
                break;
            case 4:
                if (file == NULL) {
                    printf("Error: No file open.\n");
                    continue;
                }
                rewind(file);
                fread(&n, sizeof(int), 1, file);
                printf("There are %d student records in the file.\n\n", n);
                for (int i = 0; i < n; i++) {
                    read_student(file, &s);
                    print_student(&s);
                }
                break;
            case 5:
                if (file == NULL) {
                    printf("Error: No file open.\n");
                    continue;
                }
                char name[MAX_SIZE];
                printf("Enter the name of the student: ");
                scanf("%s", name);
                int found = 0;
                rewind(file);
                fread(&n, sizeof(int), 1, file);
                for (int i = 0; i < n; i++) {
                    read_student(file, &s);
                    if (strcmp(name, s.name) == 0) {
                        printf("Record found and removed.\n");
                        n--;
                        fseek(file, 0, SEEK_SET);
                        fwrite(&n, sizeof(int), 1, file);
                        fseek(file, -sizeof(struct student), SEEK_CUR);
                        fwrite(&s, sizeof(struct student), 1, file);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: Record not found.\n");
                }
                break;
            case 6:
                if (file != NULL) {
                    fclose(file);
                }
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}