//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int num;
    char name[20];
} Student;

void swap(Student *a, Student *b) {
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].num;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].num < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Student students[MAX_SIZE];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the name and roll number of each student:\n");

    for (i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].num);
    }

    quickSort(students, 0, n - 1);

    printf("\nSorted array: \n");

    for (i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].num);
    }

    free(students);

    return 0;
}