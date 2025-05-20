//Falcon-180B DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ROWS_PER_QUERY 100

typedef struct {
    char *name;
    int age;
    char *email;
} person;

person *data = NULL;
int num_rows = 0;
int num_cols = 3;

void init() {
    data = (person *)malloc(MAX_ROWS * sizeof(person));
    num_rows = 0;
}

void add_person(char *name, int age, char *email) {
    if (num_rows >= MAX_ROWS) {
        printf("Error: maximum number of rows reached.\n");
        return;
    }

    person *new_person = (person *)malloc(sizeof(person));
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->email = strdup(email);

    data[num_rows] = *new_person;
    num_rows++;
}

void print_data() {
    for (int i = 0; i < num_rows; i++) {
        printf("%s %d %s\n", data[i].name, data[i].age, data[i].email);
    }
}

int main() {
    init();

    add_person("John Doe", 25, "john.doe@example.com");
    add_person("Jane Doe", 30, "jane.doe@example.com");
    add_person("Bob Smith", 40, "bob.smith@example.com");

    print_data();

    return 0;
}