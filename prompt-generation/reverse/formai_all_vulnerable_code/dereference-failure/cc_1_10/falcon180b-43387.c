//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
    int gender;
} Person;

typedef struct {
    char *name;
    int value;
} Attribute;

void createTable(char *tableName, Attribute *attributes, int numAttributes) {
    printf("Creating table %s:\n", tableName);
    for (int i = 0; i < numAttributes; i++) {
        printf(" - %s (%d)\n", attributes[i].name, attributes[i].value);
    }
}

void insertRow(char *tableName, Person *person) {
    printf("Inserting row into table %s:\n", tableName);
    printf("  Name: %s\n", person->name);
    printf("  Age: %d\n", person->age);
    printf("  Gender: %d\n", person->gender);
}

void selectRows(char *tableName, Attribute *attributes, int numAttributes) {
    printf("Selecting rows from table %s where:\n", tableName);
    for (int i = 0; i < numAttributes; i++) {
        printf("  %s = %d\n", attributes[i].name, attributes[i].value);
    }
}

int main() {
    Person people[MAX_ROWS];
    Attribute attributes[MAX_COLS];

    strcpy(attributes[0].name, "name");
    attributes[0].value = "John";

    strcpy(attributes[1].name, "age");
    attributes[1].value = 25;

    strcpy(attributes[2].name, "gender");
    attributes[2].value = 1;

    createTable("survivors", attributes, 3);

    people[0].name = "John";
    people[0].age = 25;
    people[0].gender = 1;

    insertRow("survivors", &people[0]);

    selectRows("survivors", attributes, 3);

    return 0;
}