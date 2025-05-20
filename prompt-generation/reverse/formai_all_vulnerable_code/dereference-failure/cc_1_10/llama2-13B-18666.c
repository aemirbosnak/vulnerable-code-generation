//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Definition of a struct to hold a person's name and age
struct Person {
    char name[50];
    int age;
};

// Function to swap two struct Person pointers
void swap_persons(struct Person **a, struct Person **b) {
    struct Person *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two struct Person pointers based on their age
int compare_persons(const void *a, const void *b) {
    struct Person *person_a = (struct Person *)a;
    struct Person *person_b = (struct Person *)b;
    if (person_a->age < person_b->age) return -1;
    if (person_a->age > person_b->age) return 1;
    return 0;
}

// Function to sort an array of struct Person pointers based on their age
void sort_persons(struct Person *array[], int size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (compare_persons(array[i], array[j]) > 0) {
                swap_persons(&array[i], &array[j]);
            }
        }
    }
}

int main() {
    struct Person persons[MAX_SIZE] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35},
        {"David", 20},
        {"Eve", 28},
        {"Frank", 40},
        {"Grace", 32},
        {"Helen", 22},
        {"Ivy", 27},
        {"Jerry", 38},
        {"Kathy", 33},
        {"Lily", 29}
    };
    int size = sizeof(persons) / sizeof(persons[0]);
    sort_persons(persons, size);
    for (int i = 0; i < size; i++) {
        printf("%d. %s (%d)\n", i + 1, persons[i].name, persons[i].age);
    }
    return 0;
}