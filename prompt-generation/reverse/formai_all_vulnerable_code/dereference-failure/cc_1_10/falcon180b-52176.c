//Falcon-180B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    char input[100];
    while(fgets(input, sizeof(input), stdin)!= NULL) {
        if(num_people >= 10) {
            printf("Error: Too many people!\n");
            break;
        }

        Person *new_person = malloc(sizeof(Person));
        if(new_person == NULL) {
            printf("Error: Out of memory!\n");
            break;
        }

        new_person->name = strdup(input);
        new_person->age = atoi(strtok(input, ","));

        people = realloc(people, sizeof(Person) * ++num_people);
        if(people == NULL) {
            printf("Error: Out of memory!\n");
            break;
        }

        people[num_people - 1] = *new_person;
        free(new_person);
    }

    for(int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}