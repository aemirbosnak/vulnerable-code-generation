//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[50];
    int roll_no;
    int marks;
};

typedef struct student Student;

void readFile(FILE *csv_file, Student *students, int *num_students) {
    char line[100];
    char *token;

    while(fgets(line, 100, csv_file)) {
        // get name
        token = strtok(line, ",");
        strcpy(students[*num_students].name, token);

        // get roll_no
        token = strtok(NULL, ",");
        students[*num_students].roll_no = atoi(token);

        // get marks
        token = strtok(NULL, ",");
        students[*num_students].marks = atoi(token);

        (*num_students)++;
    }
}

void printStudents(Student *students, int num_students) {
    int i;
    printf("Name\t\tRoll No.\tMarks\n");
    for(i=0; i<num_students; i++) {
        printf("%s\t\t%d\t\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

void readCSVFile(char *filename) {
    FILE *csv_file;
    Student students[100];
    int num_students = 0;

    csv_file = fopen(filename, "r");
    if(csv_file == NULL) {
        printf("Unable to open file");
        return;
    }

    readFile(csv_file, students, &num_students);
    fclose(csv_file);

    printStudents(students, num_students);
}

int main() {
    char *filename = "students.csv";
    readCSVFile(filename);

    return 0;
}