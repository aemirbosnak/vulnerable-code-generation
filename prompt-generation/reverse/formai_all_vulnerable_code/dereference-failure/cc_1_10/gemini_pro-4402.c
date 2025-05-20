//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[30];
    int age;
    char address[50];
    char phone[15];
};

struct database {
    struct record *records;
    int num_records;
};

struct database *create_database() {
    struct database *db = malloc(sizeof(struct database));
    db->records = NULL;
    db->num_records = 0;

    return db;
}

void destroy_database(struct database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].name);
        free(db->records[i].address);
        free(db->records[i].phone);
    }

    free(db->records);
    free(db);
}

int add_record(struct database *db, struct record *record) {
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(struct record));
    db->records[db->num_records++] = *record;

    return 0;
}

int delete_record(struct database *db, int index) {
    if (index < 0 || index >= db->num_records) {
        return -1;
    }

    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;

    return 0;
}

int find_record(struct database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void print_record(struct record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Address: %s\n", record->address);
    printf("Phone: %s\n", record->phone);
}

void print_database(struct database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
        printf("\n");
    }
}

int main() {
    struct database *db = create_database();

    struct record record1 = {"John Doe", 30, "123 Main Street", "555-1212"};
    struct record record2 = {"Jane Doe", 25, "456 Elm Street", "555-1213"};

    add_record(db, &record1);
    add_record(db, &record2);

    print_database(db);

    int index = find_record(db, "Jane Doe");
    if (index != -1) {
        delete_record(db, index);
    }

    print_database(db);

    destroy_database(db);

    return 0;
}