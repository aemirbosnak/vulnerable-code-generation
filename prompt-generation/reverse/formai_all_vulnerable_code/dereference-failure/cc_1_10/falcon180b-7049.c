//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 3
#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

Person people[MAX_ROWS];

int num_rows = 0;

void add_person(char *name, int age, char *occupation) {
    if (num_rows >= MAX_ROWS) {
        printf("Error: Maximum number of rows reached.\n");
        return;
    }

    Person *person = &people[num_rows];
    person->name = strdup(name);
    person->age = age;
    person->occupation = strdup(occupation);

    num_rows++;
}

void print_table() {
    printf("Name\tAge\tOccupation\n");
    for (int i = 0; i < num_rows; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].occupation);
    }
}

void query_people_by_occupation(char *occupation) {
    int count = 0;

    for (int i = 0; i < num_rows; i++) {
        if (strcmp(people[i].occupation, occupation) == 0) {
            printf("Name: %s\nAge: %d\n", people[i].name, people[i].age);
            count++;
        }
    }

    if (count == 0) {
        printf("No results found.\n");
    }
}

int main() {
    add_person("Mad Max", 35, "Survivor");
    add_person("Furiosa", 30, "Warrior");
    add_person("Immortan Joe", 60, "Dictator");
    add_person("Nux", 25, "War Boy");

    print_table();

    query_people_by_occupation("Survivor");

    return 0;
}