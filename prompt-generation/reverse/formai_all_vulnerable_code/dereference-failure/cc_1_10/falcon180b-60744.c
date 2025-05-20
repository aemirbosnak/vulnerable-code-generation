//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **) malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *) malloc(sizeof(char) * MAX_ROW_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s\n", table->data[i]);
    }
}

int main() {
    Table *table = create_table(3, 3);
    table->data[0] = strdup("Name");
    table->data[1] = strdup("Age");
    table->data[2] = strdup("Address");
    table->data[3] = strdup("John");
    table->data[4] = strdup("25");
    table->data[5] = strdup("123 Main St.");
    table->data[6] = strdup("Jane");
    table->data[7] = strdup("30");
    table->data[8] = strdup("456 Elm St.");

    Person *person1 = (Person *) malloc(sizeof(Person));
    person1->name = strdup("John");
    person1->age = 25;
    person1->address = strdup("123 Main St.");

    Person *person2 = (Person *) malloc(sizeof(Person));
    person2->name = strdup("Jane");
    person2->age = 30;
    person2->address = strdup("456 Elm St.");

    printf("Table:\n");
    print_table(table);

    printf("\nPeople:\n");
    printf("Name: %s, Age: %d, Address: %s\n", person1->name, person1->age, person1->address);
    printf("Name: %s, Age: %d, Address: %s\n", person2->name, person2->age, person2->address);

    destroy_table(table);
    free(person1);
    free(person2);

    return 0;
}