//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_VALUE_LEN 1024
#define MAX_RECORDS 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].key);
        free(db->records[i].value);
    }
    free(db->records);
}

int compare_keys(const void *a, const void *b) {
    const char *key1 = *(const char **)a;
    const char *key2 = *(const char **)b;
    return strcmp(key1, key2);
}

void add_record(Database *db, const char *key, const char *value) {
    if (db->num_records >= MAX_RECORDS) {
        fprintf(stderr, "Database is full.\n");
        exit(1);
    }
    Record *rec = &db->records[db->num_records];
    strncpy(rec->key, key, MAX_KEY_LEN);
    strncpy(rec->value, value, MAX_VALUE_LEN);
    db->num_records++;
}

int search_record(Database *db, const char *key) {
    Record *rec = bsearch(key, db->records, db->num_records, sizeof(Record), compare_keys);
    if (rec == NULL) {
        return -1;
    }
    return strcmp(rec->key, key);
}

void print_record(const Record *rec) {
    printf("%s: %s\n", rec->key, rec->value);
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "name", "Linus Torvalds");
    add_record(&db, "age", "51");
    add_record(&db, "occupation", "Software Engineer");

    int idx = search_record(&db, "name");
    if (idx >= 0) {
        print_record(&db.records[idx]);
    } else {
        printf("Record not found.\n");
    }

    destroy_database(&db);

    return 0;
}