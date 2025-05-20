//Falcon-180B DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

typedef struct {
    Person *data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = (Person *)malloc(MAX_ROWS * sizeof(Person));
    db->num_rows = 0;
    db->num_cols = 2;
}

void add_person(Database *db, char *name, int age) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: database is full.\n");
        return;
    }
    strcpy(db->data[db->num_rows].name, name);
    db->data[db->num_rows].age = age;
    db->num_rows++;
}

void print_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        printf("%s %d\n", db->data[i].name, db->data[i].age);
    }
}

void query_database(Database *db, char *query) {
    int i, j, k;
    char *token;
    char *delimiter = " ";
    char *name = NULL;
    int age = 0;
    int match_count = 0;

    token = strtok(query, delimiter);
    while (token!= NULL) {
        if (strcmp(token, "name") == 0) {
            token = strtok(NULL, delimiter);
            if (token!= NULL) {
                name = token;
            }
        } else if (strcmp(token, "age") == 0) {
            token = strtok(NULL, delimiter);
            if (token!= NULL) {
                age = atoi(token);
            }
        } else if (strcmp(token, "and") == 0 || strcmp(token, "or") == 0) {
            // ignore
        } else {
            printf("Error: invalid query.\n");
            return;
        }
        token = strtok(NULL, delimiter);
    }

    if (name == NULL || age == 0) {
        printf("Error: incomplete query.\n");
        return;
    }

    for (i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0 && db->data[i].age == age) {
            match_count++;
            printf("%s %d\n", db->data[i].name, db->data[i].age);
        }
    }

    if (match_count == 0) {
        printf("No results found.\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    add_person(&db, "Alice", 25);
    add_person(&db, "Bob", 30);
    add_person(&db, "Charlie", 20);

    print_database(&db);

    query_database(&db, "name Alice and age 25");

    return 0;
}