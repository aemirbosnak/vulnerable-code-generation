//FormAI DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char key[20];
    char data[100];
} record_t;

typedef struct {
    record_t records[MAX_RECORDS];
    int count;
} database_t;

void add_record(database_t *db, record_t r) {
    db->records[db->count++] = r;
}

void print_records(database_t db) {
    for (int i = 0; i < db.count; i++) {
        printf("%d: %s = %s\n", db.records[i].id, db.records[i].key, db.records[i].data);
    }
}

typedef int (*comparator_t)(const void *, const void *);

int compare_ids(const void *a, const void *b) {
    record_t *ra = (record_t *)a;
    record_t *rb = (record_t *)b;
    return ra->id - rb->id;
}

int compare_keys(const void *a, const void *b) {
    record_t *ra = (record_t *)a;
    record_t *rb = (record_t *)b;
    return strcmp(ra->key, rb->key);
}

typedef int (*search_fn_t)(const void *, const void *);

const record_t *search(database_t db, const void *key, search_fn_t fn) {
    record_t find = {0, "", ""};
    memcpy(find.key, key, strlen(key) + 1);

    return bsearch(&find, db.records, db.count, sizeof(record_t), fn);
}

int main(int argc, char **argv) {
    database_t db = {0};
    record_t r1 = {1, "key1", "data1"};
    record_t r2 = {2, "key2", "data2"};
    record_t r3 = {3, "key3", "data3"};
    record_t r4 = {4, "key4", "data4"};

    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);
    add_record(&db, r4);

    printf("Unsorted: \n");
    print_records(db);

    qsort(db.records, db.count, sizeof(record_t), compare_ids);
    printf("\nSorted by ID: \n");
    print_records(db);

    qsort(db.records, db.count, sizeof(record_t), compare_keys);
    printf("\nSorted by Key: \n");
    print_records(db);

    const char *search_key = "key3";
    const record_t *result = search(db, search_key, compare_keys);
    if (result != NULL) {
        printf("\nFound record: %d %s %s\n", result->id, result->key, result->data);
    } else {
        printf("\nRecord not found\n");
    }

    return 0;
}