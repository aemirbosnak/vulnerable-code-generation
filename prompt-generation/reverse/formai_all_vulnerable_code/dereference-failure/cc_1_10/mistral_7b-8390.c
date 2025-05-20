//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
    int *numbers;
} Person;

void free_person(Person *p) {
    if (p->numbers) free(p->numbers);
    free(p);
}

int main() {
    char *str = malloc(100);
    int *numbers = malloc(10 * sizeof(int));
    Person *person1 = malloc(sizeof(Person));
    Person *person2 = malloc(sizeof(Person));

    strcpy(str, "Hello World!");

    person1->age = 25;
    person1->height = 1.75;
    person1->numbers = numbers;
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;
    numbers[5] = 6;
    numbers[6] = 7;
    numbers[7] = 8;
    numbers[8] = 9;
    numbers[9] = 10;

    strcat(str, " How are you?");

    person2->age = 30;
    person2->height = 1.80;
    person2->numbers = numbers;

    printf("Person 1: %s, %d, %.2f\n", str, person1->age, person1->height);
    printf("Person 2: %s, %d, %.2f\n", str, person2->age, person2->height);

    free_person(person1);
    free_person(person2);
    free(str);
    free(numbers);

    printf("Memory freed.\n");

    return 0;
}