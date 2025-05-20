//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void bubbleSort(Student arr[], int n) {
    int i, j, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
            if (arr[j].id == arr[j + 1].id && strcmp(arr[j].name, arr[j + 1].name) > 0) {
                Student temp = arr[j];
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, temp.name);
                flag = 1;
            }
            if (arr[j].id == arr[j + 1].id && strcmp(arr[j].name, arr[j + 1].name) == 0 && arr[j].gpa > arr[j + 1].gpa) {
                Student temp = arr[j];
                float tempGPA = arr[j].gpa;
                arr[j].gpa = arr[j + 1].gpa;
                arr[j + 1].gpa = tempGPA;
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter student %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        fflush(stdin);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    bubbleSort(students, n);

    printf("\nSorted Student List:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d\nName: %s\nGPA: %.2f", students[i].id, students[i].name, students[i].gpa);
    }

    return 0;
}