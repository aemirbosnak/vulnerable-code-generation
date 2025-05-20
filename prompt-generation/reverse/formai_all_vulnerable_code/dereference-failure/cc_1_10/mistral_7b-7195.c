//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

typedef struct Person {
    int age;
    char name[20];
} Person;

int main() {

    // Allocating memory for an array of integers
    int *numbers = (int *) malloc(ARRAY_SIZE * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = i * 2;
        printf(" numbers[%d] = %d\n", i, numbers[i]);
    }

    free(numbers);

    // Allocating and deallocating memory for a single integer
    int *singleInt = (int *) malloc(sizeof(int));
    if (singleInt == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *singleInt = 42;
    printf("singleInt = %d\n", *singleInt);

    free(singleInt);

    // Allocating memory for a structure and accessing its fields
    Person *person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    person->age = 25;
    strcpy(person->name, "John Doe");

    printf("person->age = %d\n", person->age);
    printf("person->name = %s\n", person->name);

    free(person);

    // Using pointers for dynamic memory allocation
    int *arrSize;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    int *array = (int *) malloc(*arrSize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < *arrSize; i++) {
        array[i] = i * 2;
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}