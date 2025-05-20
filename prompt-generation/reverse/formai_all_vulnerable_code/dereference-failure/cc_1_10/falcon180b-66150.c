//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float grade;
} Student;

void init_student(Student *s) {
    s->name = malloc(MAX_SIZE * sizeof(char));
    s->age = 0;
    s->grade = 0.0;
}

void free_student(Student *s) {
    free(s->name);
    s->name = NULL;
}

int compare_students(const void *a, const void *b) {
    const Student *student1 = a;
    const Student *student2 = b;

    if (student1->age > student2->age) {
        return 1;
    } else if (student1->age < student2->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Student students[MAX_SIZE];
    int num_students = 0;

    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        if (num_students >= MAX_SIZE) {
            printf("Error: Maximum number of students reached.\n");
            break;
        }

        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        float grade = atof(strtok(NULL, ","));

        init_student(&students[num_students]);
        strcpy(students[num_students].name, name);
        students[num_students].age = age;
        students[num_students].grade = grade;

        num_students++;
    }

    fclose(file);

    qsort(students, num_students, sizeof(Student), compare_students);

    printf("Name\tAge\tGrade\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    for (int i = 0; i < num_students; i++) {
        free_student(&students[i]);
    }

    return 0;
}