//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char *phone;
} Person;

Person people[MAX_SIZE];
int num_people = 0;

void add_person(char *name, int age, char *phone) {
    if (num_people >= MAX_SIZE) {
        printf("Error: Maximum number of people reached.\n");
        return;
    }

    people[num_people].name = malloc(strlen(name) + 1);
    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    people[num_people].phone = malloc(strlen(phone) + 1);
    strcpy(people[num_people].phone, phone);

    num_people++;
}

void search_person(char *name) {
    int i;

    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\nPhone: %s\n", people[i].name, people[i].age, people[i].phone);
            return;
        }
    }

    printf("Person not found.\n");
}

int main() {
    add_person("John Doe", 25, "555-1234");
    add_person("Jane Smith", 30, "555-5678");

    search_person("John Doe");
    search_person("Jane Smith");

    return 0;
}