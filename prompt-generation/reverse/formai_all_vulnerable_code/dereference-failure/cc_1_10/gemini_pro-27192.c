//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
}pair;

typedef struct {
    int size;
    int capacity;
    pair *data;
}db;

db *db_create() {
    db *new_db = malloc(sizeof(db));
    new_db->size = 0;
    new_db->capacity = 4;
    new_db->data = malloc(sizeof(pair) * new_db->capacity);
    return new_db;
}

void db_destroy(db *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->data[i].name);
        free(db->data[i].value);
    }
    free(db->data);
    free(db);
}

void db_set(db *db, char *name, char *value) {
    if (db->size == db->capacity) {
        db->capacity *= 2;
        db->data = realloc(db->data, sizeof(pair) * db->capacity);
    }
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            free(db->data[i].value);
            db->data[i].value = malloc(strlen(value) + 1);
            strcpy(db->data[i].value, value);
            return;
        }
    }
    db->data[db->size].name = malloc(strlen(name) + 1);
    strcpy(db->data[db->size].name, name);
    db->data[db->size].value = malloc(strlen(value) + 1);
    strcpy(db->data[db->size].value, value);
    db->size++;
}

char *db_get(db *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            return db->data[i].value;
        }
    }
    return NULL;
}

void db_print(db *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s = %s\n", db->data[i].name, db->data[i].value);
    }
}

int main() {
    db *my_db = db_create();

    db_set(my_db, "name", "John Doe");
    db_set(my_db, "age", "30");
    db_set(my_db, "city", "New York");

    db_print(my_db);

    char *age = db_get(my_db, "age");
    printf("Age: %s\n", age);

    db_destroy(my_db);

    return 0;
}