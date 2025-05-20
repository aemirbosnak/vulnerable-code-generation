//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_VALUE 100

// Structure to hold a person's name and grade
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} person;

// Function to sort an array of people by their names
void sort_by_name(person *array, int num_people) {
    // Declare a pointer to the first unsorted person
    person *unsorted = array;

    // Declare a pointer to the last sorted person
    person *sorted = array + num_people - 1;

    // While there are still unsorted people
    while (unsorted <= sorted) {
        // Find the next unsorted person
        person *next = unsorted + 1;

        // If the current unsorted person's name is less than the next unsorted person's name
        if (strcmp(unsorted->name, next->name) < 0) {
            // Swap the current unsorted person with the next unsorted person
            person temp = *unsorted;
            *unsorted = *next;
            *next = temp;
        }

        // Move the sorted person forward one position
        unsorted++;
    }
}

// Function to sort an array of people by their grades
void sort_by_grade(person *array, int num_people) {
    // Declare a pointer to the first unsorted person
    person *unsorted = array;

    // Declare a pointer to the last sorted person
    person *sorted = array + num_people - 1;

    // While there are still unsorted people
    while (unsorted <= sorted) {
        // Find the next unsorted person
        person *next = unsorted + 1;

        // If the current unsorted person's grade is less than the next unsorted person's grade
        if (unsorted->grade < next->grade) {
            // Swap the current unsorted person with the next unsorted person
            person temp = *unsorted;
            *unsorted = *next;
            *next = temp;
        }

        // Move the sorted person forward one position
        unsorted++;
    }
}

// Function to print the sorted array of people
void print_array(person *array, int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("%s has a grade of %d\n", array[i].name, array[i].grade);
    }
}

int main() {
    // Declare an array of people
    person array[5] = {
        {"Alice", 80},
        {"Bob", 70},
        {"Charlie", 90},
        {"David", 60},
        {"Eve", 85}
    };

    // Sort the array of people by their names
    sort_by_name(array, 5);

    // Sort the array of people by their grades
    sort_by_grade(array, 5);

    // Print the sorted array of people
    print_array(array, 5);

    return 0;
}