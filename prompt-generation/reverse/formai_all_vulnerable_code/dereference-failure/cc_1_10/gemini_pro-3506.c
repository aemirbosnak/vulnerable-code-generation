//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[20];
    int age;
    char address[50];
};

struct database {
    struct record *records;
    int num_records;
};

struct database *create_database(int num_records) {
    struct database *db = malloc(sizeof(struct database));
    db->records = malloc(sizeof(struct record) * num_records);
    db->num_records = num_records;
    return db;
}

void destroy_database(struct database *db) {
    free(db->records);
    free(db);
}

void add_record(struct database *db, struct record *record) {
    db->records[db->num_records] = *record;
    db->num_records++;
}

void print_database(struct database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
    }
}

int main() {
    struct database *db = create_database(3);

    struct record record1 = {"John", 30, "123 Main Street"};
    struct record record2 = {"Jane", 25, "456 Elm Street"};
    struct record record3 = {"Bob", 40, "789 Oak Street"};

    add_record(db, &record1);
    add_record(db, &record2);
    add_record(db, &record3);

    print_database(db);

    destroy_database(db);

    return 0;
}