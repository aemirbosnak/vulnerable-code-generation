//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
    int budget;
} Person;

void add_person(Person* person, char* name, int age, float salary, int budget) {
    strcpy(person->name, name);
    person->age = age;
    person->salary = salary;
    person->budget = budget;
}

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Salary: $%.2f\n", person->salary);
    printf("Budget: $%.2f\n", person->budget);
}

int main() {
    Person* people = malloc(100 * sizeof(Person));
    int n = 0;

    while (1) {
        char name[50];
        int age, budget;
        float salary;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter salary: ");
        scanf("%f", &salary);

        printf("Enter budget: ");
        scanf("%d", &budget);

        add_person(people + n, name, age, salary, budget);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Added person %s (%d years old, $%.2f salary, $%.2f budget)\n", name, age, salary, budget);

        n++;
    }

    for (int i = 0; i < n; i++) {
        print_person(people + i);
    }

    free(people);

    return 0;
}