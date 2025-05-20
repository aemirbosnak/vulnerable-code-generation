//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char *name;
    int id;
} person_t;

person_t *people = NULL;
int num_people = 0;

void add_person(char *name, int id) {
    person_t *new_person = (person_t *) malloc(sizeof(person_t));
    new_person->name = strdup(name);
    new_person->id = id;
    people = (person_t *) realloc(people, sizeof(person_t) * (num_people + 1));
    people[num_people] = *new_person;
    num_people++;
}

int main() {
    FILE *fp = fopen("people.csv", "r");
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    char *token = NULL;
    int field_count = 0;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        field_count = 0;
        token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (field_count == 0) {
                add_person(token, 0);
            } else if (field_count == 1) {
                person_t *current_person = people;
                while (current_person->name!= NULL) {
                    if (strcmp(current_person->name, token) == 0) {
                        current_person->id = atoi(token);
                        break;
                    }
                    current_person++;
                }
            }
            field_count++;
            token = strtok(NULL, &delimiter);
        }
    }

    fclose(fp);

    printf("Number of people: %d\n", num_people);

    return 0;
}