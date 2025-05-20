//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 10

typedef struct {
    char name[50];
    int age;
} Record;

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    int rows = 0;
    int columns = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    Record *database = malloc(rows * sizeof(Record));
    Person *people = malloc(rows * sizeof(Person));

    printf("Enter the names and ages of the records:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%s %d", database[i].name, &database[i].age);
        people[i].id = i;
        strcpy(people[i].name, database[i].name);
        people[i].age = database[i].age;
    }

    printf("Database:\n");
    for (int i = 0; i < rows; i++) {
        printf("%-20s %d\n", database[i].name, database[i].age);
    }

    printf("\nPeople:\n");
    for (int i = 0; i < rows; i++) {
        printf("%-20s %d\n", people[i].name, people[i].age);
    }

    free(database);
    free(people);

    return 0;
}