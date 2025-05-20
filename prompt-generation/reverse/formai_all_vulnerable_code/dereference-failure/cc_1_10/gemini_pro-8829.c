//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char email[30];
    int age;
} Person;

typedef struct {
    char table_name[20];
    int num_rows;
    int num_columns;
    Person *rows;
} Table;

Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = malloc(sizeof(Table));
    strcpy(table->table_name, name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->rows = malloc(num_rows * sizeof(Person));
    return table;
}

void insert_person(Table *table, Person person) {
    table->rows[table->num_rows++] = person;
}

Person *find_person(Table *table, char *name) {
    for (int i = 0; i < table->num_rows; i++) {
        if (strcmp(table->rows[i].name, name) == 0) {
            return &table->rows[i];
        }
    }
    return NULL;
}

void print_table(Table *table) {
    printf("Table: %s\n", table->table_name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_columns);
    for (int i = 0; i < table->num_rows; i++) {
        printf("Row %d:\n", i + 1);
        printf("Name: %s\n", table->rows[i].name);
        printf("Email: %s\n", table->rows[i].email);
        printf("Age: %d\n", table->rows[i].age);
        printf("\n");
    }
}

int main() {
    // Create a table
    Table *table = create_table("People", 0, 3);

    // Insert some people into the table
    Person person1 = {"Alice", "alice@example.com", 25};
    insert_person(table, person1);
    Person person2 = {"Bob", "bob@example.com", 30};
    insert_person(table, person2);
    Person person3 = {"Carol", "carol@example.com", 35};
    insert_person(table, person3);

    // Find a person in the table
    Person *person = find_person(table, "Bob");
    if (person == NULL) {
        printf("Person not found\n");
    } else {
        printf("Person found:\n");
        printf("Name: %s\n", person->name);
        printf("Email: %s\n", person->email);
        printf("Age: %d\n", person->age);
    }

    // Print the table
    print_table(table);

    return 0;
}