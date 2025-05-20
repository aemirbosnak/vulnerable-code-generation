//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_FIELD_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} record_t;

typedef struct {
    record_t *data;
    int num_records;
    int max_records;
} database_t;

void init_database(database_t *db, int max_records) {
    db->data = (record_t *) malloc(max_records * sizeof(record_t));
    db->num_records = 0;
    db->max_records = max_records;
}

void destroy_database(database_t *db) {
    free(db->data);
}

int add_record(database_t *db, char *key, char *value) {
    if (db->num_records >= db->max_records) {
        printf("Database is full.\n");
        return -1;
    }

    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            printf("Key already exists.\n");
            return -1;
        }
    }

    strcpy(db->data[db->num_records].key, key);
    strcpy(db->data[db->num_records].value, value);
    db->num_records++;

    return 0;
}

int search_record(database_t *db, char *key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            printf("%s\n", db->data[i].value);
            return 0;
        }
    }

    printf("Record not found.\n");
    return -1;
}

int main() {
    database_t db;
    init_database(&db, 10);

    add_record(&db, "name", "John");
    add_record(&db, "age", "30");
    add_record(&db, "city", "New York");

    search_record(&db, "name");
    search_record(&db, "age");
    search_record(&db, "city");

    destroy_database(&db);

    return 0;
}