//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
} Person;

void create(Person* people, int n) {
    for (int i = 0; i < n; i++) {
        Person p;
        p.id = i + 1;

        printf("\nCreating person %d:\n", p.id);
        printf("Enter name: ");
        fgets(p.name, 50, stdin);
        p.name[strcspn(p.name, "\n")] = 0; // remove newline character
        printf("Enter age: ");
        scanf("%d", &p.age);
        fflush(stdin);
        printf("Enter gender: ");
        fgets(p.gender, 10, stdin);
        p.gender[strcspn(p.gender, "\n")] = 0; // remove newline character

        people[i] = p;
    }
}

void read(Person* people, int n) {
    printf("\nID \t Name \t Age \t Gender\n");
    printf("----------------------------------\n");
    for (int i = 0; i < n; i++) {
        Person p = people[i];
        printf("%d \t %s \t %d \t %s\n", p.id, p.name, p.age, p.gender);
    }
}

void update(Person* people, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (people[i].id == id) {
            printf("\nUpdating person %d:\n", id);
            printf("Enter name: ");
            fgets(people[i].name, 50, stdin);
            people[i].name[strcspn(people[i].name, "\n")] = 0; // remove newline character
            printf("Enter age: ");
            scanf("%d", &people[i].age);
            fflush(stdin);
            printf("Enter gender: ");
            fgets(people[i].gender, 10, stdin);
            people[i].gender[strcspn(people[i].gender, "\n")] = 0; // remove newline character
            return; // exit loop after updating
        }
    }

    printf("\nPerson %d not found!\n", id);
}

void delete(Person* people, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (people[i].id == id) {
            printf("\nDeleting person %d...\n", id);
            for (int j = i; j < n - 1; j++) {
                people[j] = people[j + 1]; // shift array left
            }
            return; // exit loop after deleting
        }
    }

    printf("\nPerson %d not found!\n", id);
}


int main() {
    int n = 0;
    printf("Welcome to the Happy People Database Simulation!\n\n");
    printf("How many people would you like to add?: ");
    scanf("%d", &n);
    fflush(stdin);

    Person* people = (Person*) malloc(n * sizeof(Person));

    create(people, n);

    printf("\n\nDisplaying all created people:\n");
    read(people, n);

    int id = 0;
    printf("\n\nWhich person would you like to update? (Enter ID): ");
    scanf("%d", &id);
    fflush(stdin);

    update(people, n, id);

    printf("\n\nDisplaying all updated people:\n");
    read(people, n);

    printf("\n\nWhich person would you like to delete? (Enter ID): ");
    scanf("%d", &id);
    fflush(stdin);

    delete(people, n, id);

    printf("\n\nDisplaying all remaining people:\n");
    read(people, n);

    free(people);
    printf("\n\nThank you for using the Happy People Database Simulation!");

    return 0;
}