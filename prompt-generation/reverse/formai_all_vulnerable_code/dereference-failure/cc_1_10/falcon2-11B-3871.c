//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

typedef struct {
    int id;
    Person *person;
} Database;

void insert(Database *db, Person *person) {
    if (db->id >= 1000) {
        printf("Database is full, cannot insert more records.\n");
        return;
    }
    db->person = (Person *)malloc(sizeof(Person));
    memcpy(db->person, person, sizeof(Person));
    db->id++;
}

void search(Database *db, char *name) {
    int i;
    for (i = 0; i < db->id; i++) {
        if (strcmp(db->person[i].name, name) == 0) {
            printf("Record found for %s\n", db->person[i].name);
            printf("Age: %d, Salary: %.2f\n", db->person[i].age, db->person[i].salary);
            return;
        }
    }
    printf("Record not found for %s\n", name);
}

void delete(Database *db, int id) {
    if (id >= 0 && id < db->id) {
        for (int i = id; i < db->id - 1; i++) {
            db->person[i] = db->person[i + 1];
        }
        db->id--;
    } else {
        printf("Invalid id, record not found.\n");
    }
}

int main() {
    Database db;
    db.id = 0;

    Person person1 = {"John Doe", 25, 5000.00};
    insert(&db, &person1);

    Person person2 = {"Jane Smith", 30, 6000.00};
    insert(&db, &person2);

    search(&db, "John Doe");
    search(&db, "Jane Smith");
    search(&db, "Mike Johnson");

    delete(&db, 0);
    search(&db, "John Doe");
    search(&db, "Jane Smith");
    search(&db, "Mike Johnson");

    return 0;
}