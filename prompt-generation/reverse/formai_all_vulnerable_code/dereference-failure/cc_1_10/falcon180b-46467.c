//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

void read_csv(FILE *file, void (*callback)(Person *)) {
    char line[MAX_LINE_SIZE];
    char *token;
    Person person = {NULL, 0, NULL};

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        person.name = strdup(token);

        token = strtok(NULL, ",");
        person.age = atoi(token);

        token = strtok(NULL, ",");
        person.email = strdup(token);

        callback(&person);
    }
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n\n", person->email);
}

int main() {
    FILE *file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_csv(file, print_person);

    fclose(file);

    return 0;
}