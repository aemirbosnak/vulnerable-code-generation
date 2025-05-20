//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
    char *location;
    char *fortune;
} Person;

Person *create_person(char *name, int age, char *occupation, char *location, char *fortune) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->occupation = strdup(occupation);
    person->location = strdup(location);
    person->fortune = strdup(fortune);
    return person;
}

void free_person(Person *person) {
    free(person->name);
    free(person->occupation);
    free(person->location);
    free(person->fortune);
    free(person);
}

int main() {
    srand(time(NULL));

    Person *people[] = {
        create_person("John", 30, "Software Engineer", "San Francisco", "You will find success in your career."),
        create_person("Mary", 25, "Teacher", "New York City", "You will find love in your life."),
        create_person("Bob", 40, "Doctor", "Los Angeles", "You will find happiness in your family."),
        create_person("Alice", 35, "Lawyer", "Chicago", "You will find wealth in your future."),
        create_person("Tom", 28, "Student", "Boston", "You will find knowledge in your studies.")
    };

    int num_people = sizeof(people) / sizeof(people[0]);

    char *name = malloc(256);
    printf("What is your name? ");
    scanf("%s", name);

    int age;
    printf("What is your age? ");
    scanf("%d", &age);

    char *occupation = malloc(256);
    printf("What is your occupation? ");
    scanf("%s", occupation);

    char *location = malloc(256);
    printf("Where do you live? ");
    scanf("%s", location);

    Person *person = create_person(name, age, occupation, location, NULL);

    int index = rand() % num_people;
    person->fortune = people[index]->fortune;

    printf("Your fortune is: %s\n", person->fortune);

    free_person(person);

    return 0;
}