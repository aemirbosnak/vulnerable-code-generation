//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
    char *address;
} Person;

typedef struct {
    int id;
    char *name;
    int num_people;
    Person *people;
} Family;

typedef struct {
    int id;
    char *name;
    int num_families;
    Family *families;
} City;

int main() {
    // Create a city
    City city = {
        .id = 1,
        .name = "New York City",
        .num_families = 3,
        .families = malloc(sizeof(Family) * 3)
    };

    // Create some families
    Family family1 = {
        .id = 1,
        .name = "Smith",
        .num_people = 4,
        .people = malloc(sizeof(Person) * 4)
    };

    Family family2 = {
        .id = 2,
        .name = "Jones",
        .num_people = 3,
        .people = malloc(sizeof(Person) * 3)
    };

    Family family3 = {
        .id = 3,
        .name = "Williams",
        .num_people = 2,
        .people = malloc(sizeof(Person) * 2)
    };

    // Add the families to the city
    city.families[0] = family1;
    city.families[1] = family2;
    city.families[2] = family3;

    // Create some people
    Person person1 = {
        .id = 1,
        .name = "John",
        .age = 30,
        .address = "123 Main Street"
    };

    Person person2 = {
        .id = 2,
        .name = "Mary",
        .age = 25,
        .address = "456 Elm Street"
    };

    Person person3 = {
        .id = 3,
        .name = "Bob",
        .age = 20,
        .address = "789 Oak Street"
    };

    Person person4 = {
        .id = 4,
        .name = "Alice",
        .age = 15,
        .address = "1011 Pine Street"
    };

    Person person5 = {
        .id = 5,
        .name = "Tom",
        .age = 10,
        .address = "1213 Cedar Street"
    };

    Person person6 = {
        .id = 6,
        .name = "Susan",
        .age = 5,
        .address = "1415 Maple Street"
    };

    // Add the people to the families
    family1.people[0] = person1;
    family1.people[1] = person2;
    family1.people[2] = person3;
    family1.people[3] = person4;

    family2.people[0] = person5;
    family2.people[1] = person6;

    family3.people[0] = person1;
    family3.people[1] = person2;

    // Print the city's data
    printf("City: %s\n", city.name);
    for (int i = 0; i < city.num_families; i++) {
        printf("  Family: %s\n", city.families[i].name);
        for (int j = 0; j < city.families[i].num_people; j++) {
            printf("    Person: %s, %d, %s\n", city.families[i].people[j].name, city.families[i].people[j].age, city.families[i].people[j].address);
        }
    }

    // Free the memory allocated for the city and its families and people
    for (int i = 0; i < city.num_families; i++) {
        free(city.families[i].people);
    }
    free(city.families);
    free(city.name);

    return 0;
}