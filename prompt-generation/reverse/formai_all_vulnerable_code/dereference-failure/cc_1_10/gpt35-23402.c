//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100 // maximum number of students
#define MAX_NAME_LENGTH 50 // maximum length of student name
#define FILENAME "students.txt" // name of file to read/write to

// structure to represent a student
typedef struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
} Student;

// function to read students from file
void read_students(Student students[], int *num_students) {
    FILE *file;
    char line[MAX_NAME_LENGTH + 20];

    // open file for reading
    file = fopen(FILENAME, "r");

    if (!file) {
        printf("Error: could not open file for reading");
        exit(1);
    }

    // read each line of file
    while (fgets(line, sizeof(line), file)) {
        char *token;
        int id;
        char name[MAX_NAME_LENGTH];
        float gpa;

        // tokenize line by comma
        token = strtok(line, ",");
        id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(name, token);

        token = strtok(NULL, ",");
        gpa = atof(token);

        // add student to array
        students[*num_students].id = id;
        strcpy(students[*num_students].name, name);
        students[*num_students].gpa = gpa;

        (*num_students)++;
    }

    // close file
    fclose(file);
}

// function to write students to file
void write_students(Student students[], int num_students) {
    FILE *file;
    int i;

    // open file for writing
    file = fopen(FILENAME, "w");

    if (!file) {
        printf("Error: could not open file for writing");
        exit(1);
    }

    // write each student to file
    for (i = 0; i < num_students; i++) {
        fprintf(file, "%d,%s,%f\n", students[i].id, students[i].name, students[i].gpa);
    }

    // close file
    fclose(file);
}


int main(void) {
    int choice;
    int num_students = 0;
    Student students[MAX_STUDENTS];

    // read initial students from file
    read_students(students, &num_students);

    // loop until user quits
    do {
        // display menu
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Display all students\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // perform action based on user's choice
        switch (choice) {
            case 1:
                // add student
                if (num_students == MAX_STUDENTS) {
                    printf("Error: maximum number of students reached\n");
                } else {
                    Student s;
                    printf("Enter student ID: ");
                    scanf("%d", &s.id);
                    printf("Enter student name: ");
                    scanf("%s", s.name);
                    printf("Enter student GPA: ");
                    scanf("%f", &s.gpa);
                    students[num_students] = s;
                    num_students++;
                    write_students(students, num_students);
                }
                break;
            case 2:
                // remove student
                if (num_students == 0) {
                    printf("Error: no students to remove\n");
                } else {
                    int id;
                    int i, j;
                    printf("Enter student ID to remove: ");
                    scanf("%d", &id);
                    for (i = 0; i < num_students; i++) {
                        if (students[i].id == id) {
                            // shift all students after this one down by one
                            for (j = i; j < num_students - 1; j++) {
                                students[j] = students[j+1];
                            }
                            num_students--;
                            write_students(students, num_students);
                            break;
                        }
                    }
                    if (i == num_students) {
                        printf("Error: student with ID %d not found\n", id);
                    }
                }
                break;
            case 3:
                // display all students
                if (num_students == 0) {
                    printf("No students\n");
                } else {
                    int i;
                    printf("Students:\n");
                    for (i = 0; i < num_students; i++) {
                        printf("ID: %d, Name: %s, GPA: %f\n", students[i].id, students[i].name, students[i].gpa);
                    }
                }
                break;
            case 4:
                // quit
                printf("Goodbye!\n");
                break;
            default:
                // invalid choice
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}