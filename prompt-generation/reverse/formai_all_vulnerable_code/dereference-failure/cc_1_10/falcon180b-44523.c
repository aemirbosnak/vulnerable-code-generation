//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* name;
    int age;
} Person;

void create_person(Person* person, char* name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void destroy_person(Person* person) {
    free(person->name);
    person->name = NULL;
}

int compare_persons(const void* a, const void* b) {
    const Person* person_a = a;
    const Person* person_b = b;
    
    int result = strcmp(person_a->name, person_b->name);
    
    if (result == 0) {
        result = person_a->age - person_b->age;
    }
    
    return result;
}

void search_persons(Person* persons, int num_persons, char* name, int* index) {
    qsort(persons, num_persons, sizeof(Person), compare_persons);
    
    for (int i = 0; i < num_persons; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            *index = i;
            return;
        }
    }
}

int main() {
    Person persons[MAX_SIZE];
    int num_persons = 0;
    
    create_person(&persons[num_persons], "Alice", 25);
    num_persons++;
    
    create_person(&persons[num_persons], "Bob", 30);
    num_persons++;
    
    create_person(&persons[num_persons], "Charlie", 20);
    num_persons++;
    
    char* name = "Bob";
    int index = -1;
    
    search_persons(persons, num_persons, name, &index);
    
    if (index!= -1) {
        printf("Found person with name '%s' and age %d at index %d.\n", persons[index].name, persons[index].age, index);
    } else {
        printf("Person with name '%s' not found.\n", name);
    }
    
    for (int i = 0; i < num_persons; i++) {
        destroy_person(&persons[i]);
    }
    
    return 0;
}