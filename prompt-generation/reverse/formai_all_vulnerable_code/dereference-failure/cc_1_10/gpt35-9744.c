//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* first_name;
    char* last_name;
    int age;
} Person;

Person* create_person(char* first_name, char* last_name, int age) {
    Person* person = malloc(sizeof(Person));
    person->first_name = strdup(first_name);
    person->last_name = strdup(last_name);
    person->age = age;
    return person;
}

void free_person(Person* person) {
    free(person->first_name);
    free(person->last_name);
    free(person);
}

void parse_csv(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(-1);
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* first_name = strtok(line, ",");
        char* last_name = strtok(NULL, ",");
        char* age_str = strtok(NULL, ",");
        int age = atoi(age_str);

        Person* person = create_person(first_name, last_name, age);
        printf("Name: %s %s, Age: %d\n", person->first_name, person->last_name, person->age);
        free_person(person);
    }

    fclose(file);
}

int main() {
    parse_csv("example.csv");
    return 0;
}