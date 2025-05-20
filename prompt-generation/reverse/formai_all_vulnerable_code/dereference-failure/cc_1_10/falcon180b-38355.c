//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *p) {
    p->name = (char *)malloc(MAX_SIZE * sizeof(char));
    printf("Enter name: ");
    scanf("%s", p->name);

    printf("Enter age: ");
    scanf("%d", &p->age);
}

void display_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    Person *people = (Person *)malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        create_person(&people[num_people]);
        num_people++;
    }

    int search_age;
    printf("Enter age to search for: ");
    scanf("%d", &search_age);

    int found_count = 0;
    for (int i = 0; i < num_people; i++) {
        if (people[i].age == search_age) {
            display_person(people[i]);
            found_count++;
        }
    }

    if (found_count == 0) {
        printf("No person found with age %d.\n", search_age);
    } else {
        printf("%d person(s) found with age %d.\n", found_count, search_age);
    }

    free(people);
    return 0;
}