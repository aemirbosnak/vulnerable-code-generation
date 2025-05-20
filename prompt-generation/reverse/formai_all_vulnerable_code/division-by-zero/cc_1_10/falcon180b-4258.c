//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    int fitness_level;
} Person;

void add_person(Person *people, int count) {
    printf("Enter name: ");
    scanf("%s", people[count].name);
    printf("Enter age: ");
    scanf("%d", &people[count].age);
    printf("Enter weight (in kg): ");
    scanf("%d", &people[count].weight);
    printf("Enter height (in cm): ");
    scanf("%d", &people[count].height);
    people[count].fitness_level = calculate_fitness_level(people[count].age, people[count].weight, people[count].height);
    printf("Fitness level: %d\n", people[count].fitness_level);
}

int calculate_fitness_level(int age, int weight, int height) {
    int bmi = weight / (height * height);
    int fitness_level = 0;

    if (bmi < 18.5) {
        fitness_level = 1;
    } else if (bmi >= 18.5 && bmi < 25) {
        fitness_level = 2;
    } else if (bmi >= 25 && bmi < 30) {
        fitness_level = 3;
    } else {
        fitness_level = 4;
    }

    if (age < 20) {
        fitness_level += 1;
    } else if (age >= 20 && age < 30) {
        fitness_level += 2;
    } else if (age >= 30 && age < 40) {
        fitness_level += 3;
    } else if (age >= 40 && age < 50) {
        fitness_level += 4;
    } else {
        fitness_level += 5;
    }

    return fitness_level;
}

void display_people(Person *people, int count) {
    printf("Name\tAge\tWeight\tHeight\tFitness Level\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", people[i].name, people[i].age, people[i].weight, people[i].height, people[i].fitness_level);
    }
}

int main() {
    Person people[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        printf("1. Add person\n2. Display people\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_person(people, count);
            count++;
            break;
        case 2:
            display_people(people, count);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}