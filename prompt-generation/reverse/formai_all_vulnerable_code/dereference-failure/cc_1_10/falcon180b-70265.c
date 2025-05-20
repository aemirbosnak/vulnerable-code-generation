//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_QUERY_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    float height;
} Person;

typedef struct {
    Person *data;
    int capacity;
    int size;
} Database;

void init_database(Database *db, int capacity) {
    db->data = malloc(capacity * sizeof(Person));
    db->capacity = capacity;
    db->size = 0;
}

void destroy_database(Database *db) {
    free(db->data);
}

int add_person(Database *db, const char *name, int age, char gender, float height) {
    if (db->size >= db->capacity) {
        return 0;
    }

    Person *person = db->data + db->size;
    strncpy(person->name, name, MAX_NAME_LENGTH);
    person->age = age;
    person->gender = gender;
    person->height = height;

    ++db->size;
    return 1;
}

int query_person(Database *db, const char *query) {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    float height;
    int count = 0;

    sscanf(query, "name=%63s age=%d gender=%c height=%f", name, &age, &gender, &height);

    for (int i = 0; i < db->size; ++i) {
        Person *person = db->data + i;

        if (person->age == age && person->gender == gender && person->height == height) {
            strncpy(person->name, name, MAX_NAME_LENGTH);
            ++count;
        }
    }

    return count;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_person(&db, "Romeo", 20, 'M', 1.8);
    add_person(&db, "Juliet", 18, 'F', 1.6);

    printf("Added Romeo and Juliet to the database.\n");

    int result = query_person(&db, "name=Juliet age=18 gender=F height=1.6");

    if (result > 0) {
        printf("Found %d person(s) matching the query.\n", result);
    } else {
        printf("No person found matching the query.\n");
    }

    destroy_database(&db);

    return 0;
}