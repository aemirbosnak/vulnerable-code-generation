//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 100

typedef struct {
    char name[MAX];
    int roll;
    int age;
} Student;

void create(Student arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i+1);
        scanf("%s", arr[i].name);
        printf("Enter roll number for student %s: ", arr[i].name);
        scanf("%d", &arr[i].roll);
        printf("Enter age for student %s: ", arr[i].name);
        scanf("%d", &arr[i].age);
    }
}

int compare(const void *a, const void *b) {
    Student *stud1 = (Student *)a;
    Student *stud2 = (Student *)b;
    if(strcmp(stud1->name, stud2->name) == 0) {
        return 0;
    }
    else if(stud1->roll > stud2->roll) {
        return 1;
    }
    else {
        return -1;
    }
}

void display(Student arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%s %d %d\n", arr[i].name, arr[i].roll, arr[i].age);
    }
}

void search(Student arr[], int n, char name[]) {
    qsort(arr, n, sizeof(Student), compare);
    for(int i = 0; i < n; i++) {
        if(strcmp(arr[i].name, name) == 0) {
            printf("Student found with name %s\n", name);
            printf("Roll number: %d\n", arr[i].roll);
            printf("Age: %d\n", arr[i].age);
            return;
        }
    }
    printf("Student not found\n");
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student arr[n];
    create(arr, n);
    char name[MAX];
    printf("Enter name to search: ");
    scanf("%s", name);
    search(arr, n, name);
    return 0;
}