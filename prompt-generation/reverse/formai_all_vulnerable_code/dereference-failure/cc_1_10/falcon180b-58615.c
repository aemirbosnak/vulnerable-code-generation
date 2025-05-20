//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

Person *create_person(char *name, int age, float height) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    char input[1000];
    Person *person = NULL;

    printf("Enter your name: ");
    scanf("%s", input);
    person = create_person(input, 0, 0);

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add information\n");
        printf("2. Print information\n");
        printf("3. Delete person\n");
        printf("4. Exit\n");

        scanf("%d", &person->age);
        getchar(); // consume newline

        switch (person->age) {
        case 1:
            printf("Enter your height: ");
            scanf("%f", &person->height);
            break;

        case 2:
            print_person(person);
            break;

        case 3:
            delete_person(person);
            person = NULL;
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}