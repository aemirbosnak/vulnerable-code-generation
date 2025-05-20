//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *city;
} Person;

typedef struct {
    int num_rows;
    int num_cols;
    Person **data;
} Database;

void init_database(Database *db) {
    db->num_rows = 0;
    db->num_cols = 3;
    db->data = (Person **)malloc(MAX_ROWS * sizeof(Person *));
    for (int i = 0; i < MAX_ROWS; i++) {
        db->data[i] = (Person *)malloc(MAX_COLS * sizeof(Person));
        for (int j = 0; j < MAX_COLS; j++) {
            db->data[i][j].name = NULL;
            db->data[i][j].age = 0;
            db->data[i][j].city = NULL;
        }
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->data[i][j].name!= NULL) {
                free(db->data[i][j].name);
            }
            if (db->data[i][j].city!= NULL) {
                free(db->data[i][j].city);
            }
        }
        free(db->data[i]);
    }
    free(db->data);
}

void add_person(Database *db, char *name, int age, char *city) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: database is full\n");
        return;
    }
    if (db->num_cols < 3) {
        for (int i = 0; i < db->num_cols; i++) {
            db->num_cols++;
            for (int j = 0; j < db->num_rows; j++) {
                db->data[j][i].name = NULL;
                db->data[j][i].age = 0;
                db->data[j][i].city = NULL;
            }
        }
    }
    int row = db->num_rows++;
    db->data[row][0].name = strdup(name);
    db->data[row][1].age = age;
    db->data[row][2].city = strdup(city);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->data[i][j].name!= NULL) {
                printf("%s ", db->data[i][j].name);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);
    add_person(&db, "John", 30, "New York");
    add_person(&db, "Jane", 25, "Los Angeles");
    print_database(&db);
    destroy_database(&db);
    return 0;
}