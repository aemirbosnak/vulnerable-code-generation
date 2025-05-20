//Falcon-180B DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 150
#define MAX_ROWS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

int main() {
    FILE *db_file;
    Person *people = NULL;
    int num_people = 0;
    char query[MAX_NAME_LEN + 10];

    db_file = fopen("database.txt", "r");
    if (db_file == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    while (fgets(query, sizeof(query), db_file)!= NULL) {
        if (num_people == MAX_ROWS) {
            printf("Database is full.\n");
            break;
        }

        Person *new_person = malloc(sizeof(Person));
        if (new_person == NULL) {
            printf("Error allocating memory for new person.\n");
            return 1;
        }

        strcpy(new_person->name, strtok(query, ","));
        new_person->age = atoi(strtok(NULL, ","));

        people = realloc(people, sizeof(Person) * ++num_people);
        if (people == NULL) {
            printf("Error reallocating memory for people array.\n");
            return 1;
        }

        people[num_people - 1] = *new_person;
        free(new_person);
    }

    fclose(db_file);

    printf("Number of people in database: %d\n", num_people);

    return 0;
}