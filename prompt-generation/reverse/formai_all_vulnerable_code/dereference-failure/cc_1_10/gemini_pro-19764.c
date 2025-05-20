//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int score;
    int rank;
} student;

void swap(student *a, student *b) {
    student temp = *a;
    *a = *b;
    *b = temp;
}

void sort_students(student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void assign_ranks(student *students, int n) {
    int rank = 1;
    students[0].rank = rank;
    for (int i = 1; i < n; i++) {
        if (students[i].score == students[i - 1].score) {
            students[i].rank = rank;
        } else {
            rank++;
            students[i].rank = rank;
        }
    }
}

void print_students(student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", students[i].name, students[i].score, students[i].rank);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    student *students = malloc(n * sizeof(student));
    for (int i = 0; i < n; i++) {
        char name[101];
        scanf("%s", name);
        int score;
        scanf("%d", &score);

        students[i].name = malloc(strlen(name) + 1);
        strcpy(students[i].name, name);
        students[i].score = score;
    }

    sort_students(students, n);
    assign_ranks(students, n);
    print_students(students, n);

    return 0;
}