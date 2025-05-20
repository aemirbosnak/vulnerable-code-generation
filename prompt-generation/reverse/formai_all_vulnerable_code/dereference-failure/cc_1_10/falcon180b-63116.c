//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1000
#define MAX_INTEGER_VALUE 10000000

typedef struct {
    char *name;
    int age;
    double height;
    char gender;
} Person;

Person *create_person(char *name, int age, double height, char gender) {
    Person *new_person = (Person *) malloc(sizeof(Person));
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->height = height;
    new_person->gender = gender;
    return new_person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %lf\n", person->height);
    printf("Gender: %c\n", person->gender);
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    Person *person;

    while (true) {
        printf("Enter a name (or type 'exit' to quit): ");
        fgets(input_string, MAX_STRING_LENGTH, stdin);
        input_string[strcspn(input_string, "\n")] = '\0';

        if (strcmp(input_string, "exit") == 0) {
            break;
        }

        person = create_person(input_string, rand() % MAX_INTEGER_VALUE, rand() % 1000 / 10.0, rand() % 2? 'M' : 'F');
        print_person(person);
        delete_person(person);
    }

    return 0;
}