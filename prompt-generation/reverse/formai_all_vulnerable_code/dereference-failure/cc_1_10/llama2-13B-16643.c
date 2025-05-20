//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DATABASE_SIZE 100000
#define RECORD_SIZE 50

typedef struct record {
    char name[50];
    char address[50];
    int age;
} record_t;

typedef struct database {
    char *data;
    size_t capacity;
    size_t size;
} database_t;

void init_database(database_t *db) {
    db->data = malloc(DATABASE_SIZE);
    db->capacity = DATABASE_SIZE;
    db->size = 0;
}

void insert_record(database_t *db, char *name, char *address, int age) {
    size_t len = strlen(name) + strlen(address) + 1;
    if (db->size == db->capacity) {
        size_t new_capacity = db->capacity * 2;
        char *new_data = realloc(db->data, new_capacity);
        if (new_data == NULL) {
            printf("Error: realloc failed\n");
            exit(1);
        }
        db->data = new_data;
        db->capacity = new_capacity;
    }
    char *record = (char *)malloc(len);
    snprintf(record, len, "%s %s %d", name, address, age);
    memcpy(db->data + db->size * RECORD_SIZE, record, len);
    db->size++;
}

void query_record(database_t *db, char *name) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(name, db->data + i * RECORD_SIZE) == 0) {
            char *record = (char *)malloc(RECORD_SIZE);
            memcpy(record, db->data + i * RECORD_SIZE, RECORD_SIZE);
            printf("%s %s %d\n", record, db->data + (i + 1) * RECORD_SIZE, db->data[i * RECORD_SIZE + 2]);
            free(record);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    database_t db;
    init_database(&db);

    char *name1 = "John";
    char *address1 = "123 Main St";
    int age1 = 30;
    insert_record(&db, name1, address1, age1);

    char *name2 = "Jane";
    char *address2 = "456 Elm St";
    int age2 = 25;
    insert_record(&db, name2, address2, age2);

    char *name3 = "Bob";
    char *address3 = "789 Oak St";
    int age3 = 40;
    insert_record(&db, name3, address3, age3);

    query_record(&db, "John");
    query_record(&db, "Jane");
    query_record(&db, "Bob");

    return 0;
}