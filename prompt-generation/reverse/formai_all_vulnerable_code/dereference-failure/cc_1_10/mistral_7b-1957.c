//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void print_student(Student s) {
    printf("Student %d: %s, GPA: %.2f\n", s.id, s.name, s.gpa);
}

void generate_students(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        sprintf(students[i].name, "Student %d", students[i].id);
        students[i].gpa = (float) rand() / RAND_MAX;
    }
}

int main() {
    Student* students;
    clock_t start, end;

    double time_taken;

    printf("\n***** CHEERFUL STUDENTS BENCHMARK *****\n");

    students = (Student*) malloc(N * sizeof(Student));

    start = clock();

    generate_students(students, N);

    end = clock();

    time_taken = (end - start) / (double) CLOCKS_PER_SEC;

    printf("\nGenerated %d students in %.6f seconds.\n", N, time_taken);

    for (int i = 0; i < N; i++) {
        print_student(students[i]);
    }

    free(students);

    printf("\n***** CHEERFUL STUDENTS BENCHMARK FINISHED *****\n");

    return 0;
}