//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

typedef struct {
    Record *data;
    int size;
    int capacity;
} Database;

void initDatabase(Database *db, int capacity) {
    db->data = (Record *) malloc(capacity * sizeof(Record));
    db->size = 0;
    db->capacity = capacity;
}

void addRecord(Database *db, int id, char *name, int age) {
    if (db->size >= db->capacity) {
        printf("Database is full. Cannot add record.\n");
        return;
    }

    db->data[db->size].id = id;
    strcpy(db->data[db->size].name, name);
    db->data[db->size].age = age;

    db->size++;
}

void printRecords(Database db) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db.size; i++) {
        printf("%d\t%s\t%d\n", db.data[i].id, db.data[i].name, db.data[i].age);
    }
}

void searchRecord(Database db, int id) {
    for (int i = 0; i < db.size; i++) {
        if (db.data[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\n", db.data[i].id);
            printf("Name: %s\n", db.data[i].name);
            printf("Age: %d\n", db.data[i].age);
        }
    }
}

int main() {
    Database db;
    initDatabase(&db, 10);

    addRecord(&db, 1, "John Doe", 25);
    addRecord(&db, 2, "Jane Smith", 30);
    addRecord(&db, 3, "Bob Johnson", 40);

    printRecords(db);

    searchRecord(db, 2);

    return 0;
}