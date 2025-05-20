//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#define DB_SIZE 1024
#define REC_SIZE 1024

typedef struct {
    char name[50];
    char address[50];
    int age;
} record_t;

typedef struct {
    char *data;
    size_t size;
} db_t;

db_t *db_create(size_t size) {
    db_t *db = malloc(sizeof(db_t));
    db->data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    db->size = size;
    return db;
}

void db_insert(db_t *db, record_t *rec) {
    size_t offs = db->size * (size_t)rand() / RAND_MAX;
    memcpy(db->data + offs, rec, REC_SIZE);
}

record_t *db_search(db_t *db, const char *name) {
    size_t offs = db->size * (size_t)rand() / RAND_MAX;
    record_t rec;
    memcpy(&rec, db->data + offs, REC_SIZE);
    if (strcmp(rec.name, name) == 0) {
        return &rec;
    }
    return NULL;
}

void db_delete(db_t *db, const char *name) {
    record_t *rec = db_search(db, name);
    if (rec != NULL) {
        memset(db->data + (size_t)rec - (size_t)db->data, 0xCC, REC_SIZE);
    }
}

int main() {
    db_t *db = db_create(DB_SIZE);
    record_t rec1 = {"Alice", "123 Main St", 25};
    record_t rec2 = {"Bob", "456 Elm St", 30};
    record_t rec3 = {"Charlie", "789 Oak St", 35};

    db_insert(db, &rec1);
    db_insert(db, &rec2);
    db_insert(db, &rec3);

    record_t *rec = db_search(db, "Alice");
    assert(rec != NULL);
    printf("Found record: %s %s %d\n", rec->name, rec->address, rec->age);

    rec = db_search(db, "Bob");
    assert(rec != NULL);
    printf("Found record: %s %s %d\n", rec->name, rec->address, rec->age);

    rec = db_search(db, "Charlie");
    assert(rec != NULL);
    printf("Found record: %s %s %d\n", rec->name, rec->address, rec->age);

    db_delete(db, "Alice");

    rec = db_search(db, "Alice");
    assert(rec == NULL);

    return 0;
}