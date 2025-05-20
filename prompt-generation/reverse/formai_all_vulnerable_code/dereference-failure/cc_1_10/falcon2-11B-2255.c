//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char* name;
    int age;
    float weight;
} Person;

typedef struct {
    char* name;
    int value;
} Index;

void create_index(char* name, int value) {
    Index* new_index = malloc(sizeof(Index));
    strcpy(new_index->name, name);
    new_index->value = value;
    return;
}

void insert_person(Person* person) {
    Index* index = malloc(sizeof(Index));
    strcpy(index->name, person->name);
    index->value = person->age;
    create_index(index->name, index->value);
    free(index);
    return;
}

void search_person(Person* person) {
    Index* index = malloc(sizeof(Index));
    strcpy(index->name, person->name);
    if (strcmp(index->name, "No_match") == 0) {
        printf("No person found with name '%s'\n", index->name);
    } else {
        printf("Person found with name '%s'\n", index->name);
    }
    free(index);
    return;
}

int main() {
    Person person1 = {"Robin Hood", 35, 175.5f};
    Person person2 = {"Sir Lancelot", 45, 190.2f};
    insert_person(&person1);
    insert_person(&person2);
    search_person(&person1);
    search_person(&person2);
    return 0;
}