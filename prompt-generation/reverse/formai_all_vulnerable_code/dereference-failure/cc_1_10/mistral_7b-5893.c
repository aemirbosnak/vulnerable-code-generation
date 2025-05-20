//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int roll_no;
    float percentage;
} Student;

void read_students(FILE *file) {
    Student student;
    while (fread(&student, sizeof(Student), 1, file) > 0) {
        printf("\nName: %s", student.name);
        printf("\nRoll Number: %d", student.roll_no);
        printf("\nPercentage: %.2f\n", student.percentage);
    }
}

void write_student(FILE *file, Student student) {
    fwrite(&student, sizeof(Student), 1, file);
}

int main() {
    FILE *file;
    Student new_student;
    char filename[20] = "students.bin";

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_students(file);

    printf("\nDo you want to add a new student? (y/n)\n");
    char add_student;
    scanf("%c", &add_student);

    if (add_student == 'y') {
        printf("\nEnter student name: ");
        scanf("%s", new_student.name);

        printf("\nEnter student roll number: ");
        scanf("%d", &new_student.roll_no);

        printf("\nEnter student percentage: ");
        scanf("%f", &new_student.percentage);

        file = fopen(filename, "ab");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            exit(1);
        }

        write_student(file, new_student);
        printf("\nStudent added successfully.\n");

        fclose(file);
        file = fopen(filename, "rb");
        read_students(file);

        fclose(file);
    }

    fclose(file);
    return 0;
}