//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a student
typedef struct {
    int roll_number;
    char name[50];
    float marks;
} Student;

// Function to read student data from a file
void read_students(const char *filename, Student **students, int *num_students) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    *students = malloc(1 * sizeof(Student));
    (*num_students) = 0;

    while (fscanf(file, "%d%s%f", &((*students)[*num_students].roll_number), (*students)[*num_students].name, &((*students)[*num_students].marks)) != EOF) {
        (*num_students)++;
        *students = realloc(*students, ((*num_students) + 1) * sizeof(Student));
    }

    fclose(file);
}

// Function to display student data
void display_students(const Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n", students[i].roll_number, students[i].name, students[i].marks);
    }
}

// Function to search for a student by name
int search_student(const Student *students, int num_students, const char *name) {
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return students[i].roll_number;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <students.txt>\n", argv[0]);
        exit(1);
    }

    Student *students = NULL;
    int num_students = 0;

    read_students(argv[1], &students, &num_students);

    printf("Students:\n");
    display_students(students, num_students);

    char name[50];
    int roll_number;

    printf("\nEnter the name of the student you are looking for: ");
    scanf("%s", name);

    roll_number = search_student(students, num_students, name);

    if (roll_number == -1) {
        printf("Student not found.\n");
    } else {
        printf("Student with roll number %d found.\n", roll_number);
    }

    free(students);

    return 0;
}