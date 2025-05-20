//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Student arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].grade > arr[largest].grade)
        largest = l;

    if (r < n && arr[r].grade > arr[largest].grade)
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    Student students[MAX_SIZE];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the student data:\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    heapSort(students, n);

    printf("\nSorted Students:\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grade: %.2f\n", students[i].grade);
    }

    return 0;
}