//Falcon-180B DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *email;
    int age;
} Person;

Person *people = NULL;
int num_people = 0;

void add_person(char *name, char *email, int age) {
    Person *new_person = malloc(sizeof(Person));
    new_person->name = strdup(name);
    new_person->email = strdup(email);
    new_person->age = age;
    people = realloc(people, sizeof(Person) * ++num_people);
    people[num_people-1] = *new_person;
    free(new_person);
}

void print_people() {
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%s\t%d\n", people[i].name, people[i].email, people[i].age);
    }
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        int age = atoi(strtok(NULL, ","));
        add_person(name, email, age);
    }

    fclose(file);

    print_people();

    return 0;
}