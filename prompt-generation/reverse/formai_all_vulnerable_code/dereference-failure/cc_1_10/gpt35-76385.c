//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

void write_to_file(struct student *st, int num_students) {
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(st, sizeof(struct student), num_students, fp);
    fclose(fp);
}

void read_from_file(struct student *st, int num_students) {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fread(st, sizeof(struct student), num_students, fp);
    fclose(fp);
}

void print_student(struct student st) {
    printf("Name: %s\n", st.name);
    printf("Age: %d\n", st.age);
    printf("GPA: %.2f\n", st.gpa);
}

void print_all_students(struct student *st, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student #%d:\n", i+1);
        print_student(st[i]);
        printf("\n");
    }
}

int main() {
    int num_students;

    printf("How many students do you want to enter? ");
    scanf("%d", &num_students);

    struct student *students = malloc(num_students * sizeof(struct student));
    if (students == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    for (int i = 0; i < num_students; i++) {
        printf("Enter name of student #%d: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter age of student #%d: ", i+1);
        scanf("%d", &students[i].age);

        printf("Enter GPA of student #%d: ", i+1);
        scanf("%f", &students[i].gpa);

        printf("\n");
    }

    write_to_file(students, num_students);
    free(students);

    printf("Now reading from file...\n");
    students = malloc(num_students * sizeof(struct student));
    if (students == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    read_from_file(students, num_students);
    printf("Printing all students...\n");
    print_all_students(students, num_students);

    free(students);
    return 0;
}