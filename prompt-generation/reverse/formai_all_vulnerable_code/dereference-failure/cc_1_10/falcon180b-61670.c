//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    char *name;
    int age;
    char *gender;
    int id;
} PersonRow;

typedef struct {
    Person *data;
    int num_rows;
    int num_cols;
} Database;

int main() {
    Database db = {0};
    Person *person = (Person *)malloc(sizeof(Person));
    PersonRow *row = (PersonRow *)malloc(sizeof(PersonRow));

    db.data = person;
    db.num_rows = 1;
    db.num_cols = 3;

    strcpy(person->name, "John Doe");
    person->age = 30;
    strcpy(person->gender, "Male");

    row->name = strdup(person->name);
    row->age = person->age;
    row->gender = strdup(person->gender);
    row->id = 1;

    printf("Name: %s\n", row->name);
    printf("Age: %d\n", row->age);
    printf("Gender: %s\n", row->gender);
    printf("ID: %d\n", row->id);

    return 0;
}