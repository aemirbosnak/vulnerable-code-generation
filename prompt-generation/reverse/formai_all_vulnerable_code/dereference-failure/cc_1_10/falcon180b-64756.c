//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float grade;
} Student;

typedef struct {
    Student *data;
    int size;
    int capacity;
} DynamicArray;

void initDynamicArray(DynamicArray *array) {
    array->data = (Student *)malloc(MAX_SIZE * sizeof(Student));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resizeDynamicArray(DynamicArray *array) {
    array->capacity *= 2;
    Student *newData = (Student *)malloc(array->capacity * sizeof(Student));
    memcpy(newData, array->data, array->size * sizeof(Student));
    free(array->data);
    array->data = newData;
}

void addStudent(DynamicArray *array, char *name, int age, float grade) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    strcpy(array->data[array->size].name, name);
    array->data[array->size].age = age;
    array->data[array->size].grade = grade;
    array->size++;
}

void printStudents(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", array->data[i].name, array->data[i].age, array->data[i].grade);
    }
}

int main() {
    DynamicArray students;
    initDynamicArray(&students);

    addStudent(&students, "John Doe", 20, 90.5);
    addStudent(&students, "Jane Smith", 22, 85.3);
    addStudent(&students, "Alice Johnson", 19, 95.7);

    printStudents(&students);

    return 0;
}