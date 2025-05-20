//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void str_trim(char *str, size_t size) {
    size_t i = 0, j = 0;

    while (isspace(str[i])) i++;
    if (i >= size) return;

    while (size > i && isspace(str[size - 1])) size--;

    if (size > i) {
        memmove(str, str + i, size - i);
        str[size - 1] = '\0';
    }
}

void read_csv(FILE *fp, Person *persons, size_t capacity) {
    size_t i = 0, line_size = 0;
    char line[256];
    char *token = NULL;
    Person person;

    while (getline(&line, sizeof(line), fp) > 0) {
        line_size = strlen(line);
        str_trim(line, line_size);

        token = strtok(line, ",");
        if (!token) continue;
        person.name = malloc(strlen(token) + 1);
        strcpy(person.name, token);

        token = strtok(NULL, ",");
        person.age = atoi(token);

        token = strtok(NULL, ",");
        person.height = atof(token);

        if (i >= capacity) {
            size_t new_capacity = capacity * 2;
            Person *new_persons = realloc(persons, new_capacity * sizeof(Person));
            if (!new_persons) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            persons = new_persons;
            capacity = new_capacity;
        }

        persons[i++] = person;
    }
}

int main() {
    FILE *file;
    Person *people;
    size_t capacity = 10;
    size_t num_people = 0;

    file = fopen("people.csv", "r");
    if (!file) {
        fprintf(stderr, "Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    people = malloc(capacity * sizeof(Person));
    if (!people) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    read_csv(file, people, capacity);
    fclose(file);

    printf("Name\tAge\tHeight\n");
    for (size_t i = 0; i < num_people; i++) {
        printf("%s\t%d\t%.2f\n", people[i].name, people[i].age, people[i].height);
    }

    for (size_t i = 0; i < num_people; i++) free(people[i].name);
    free(people);

    return EXIT_SUCCESS;
}